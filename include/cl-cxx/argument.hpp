// -*- mode: c++; fill-column: 80; c-basic-offset: 2; indent-tabs-mode: nil -*-
/*
    Copyright (c) 2013 Juan Jose Garcia Ripoll

    Tensor is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published
    by the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Library General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef CL_CXX_ARGUMENT_H
#define CL_CXX_ARGUMENT_H

#include <cl-cxx/base.hpp>
#include <cl-cxx/object.hpp>

namespace cl_cxx {

  using namespace cl_cxx_backend;

  /*
   * Elementary type wrappers. If they are only input values, the value is
   * extracted and stored in a local field. If they are reference values we
   * need to create an object when returning and adding it to the array of
   * output values.
   */

  template<typename A>
  struct simple_argument_wrapper {
    A value;
    simple_argument_wrapper(cl_object o) : value(from_cl_object<A>(o)) {}
    friend return_stack &operator<<(return_stack &s, simple_argument_wrapper<A> &a) {
      return s;
    }
  };

  template<typename A>
  struct simple_reference_argument_wrapper {
    A value;
    simple_reference_argument_wrapper(cl_object o) : value(from_cl_object<A>(o)) {}
    friend return_stack &operator<<(return_stack &s, simple_reference_argument_wrapper<A> &a) {
      return s << to_cl_object(a.value);
    }
  };

  /*
   * Class type wrappers. We only need a reference to the field stored in
   * a foreign object created by the Lisp. If the argument is a reference
   * we also add the value to the stack.
   */

  template<typename A>
  struct complex_argument_wrapper {
    class_<A> value;
    complex_argument_wrapper(cl_object o) : value(o) {}
  };

  template<typename A>
  struct argument_wrapper {
    class_<A> value;
    argument_wrapper(cl_object o) : value(o) {}
    friend return_stack &operator<<(return_stack &s, argument_wrapper<A> &a) {
      return s;
    }
  };

  template<typename A>
  struct argument_wrapper<A&> {
    class_<A> value;
    argument_wrapper(cl_object o) : value(o), original(o) {}
    friend return_stack &operator<<(return_stack &s, argument_wrapper<A&> &a) {
      return s << a.original;
    }
  private:
    cl_object original;
  };

#define DEF_CL_CXX_SIMPLE_ARGUMENT(T) \
  template<> struct argument_wrapper<T> : public simple_argument_wrapper<T> { \
    typedef simple_argument_wrapper<T> parent;                          \
    argument_wrapper(cl_object o) : parent(o) {} };                     \
  template<> struct argument_wrapper<T&> : public simple_reference_argument_wrapper<T> { \
    typedef simple_reference_argument_wrapper<T> parent;                \
    argument_wrapper(cl_object o) : parent(o) {} };

  DEF_CL_CXX_SIMPLE_ARGUMENT(int);
  DEF_CL_CXX_SIMPLE_ARGUMENT(unsigned int);
  DEF_CL_CXX_SIMPLE_ARGUMENT(long);
  DEF_CL_CXX_SIMPLE_ARGUMENT(unsigned long);
  DEF_CL_CXX_SIMPLE_ARGUMENT(double);
  DEF_CL_CXX_SIMPLE_ARGUMENT(float);
  DEF_CL_CXX_SIMPLE_ARGUMENT(std::string);

} // namespace cl_cxx

#endif CL_CXX_ARGUMENT_H
