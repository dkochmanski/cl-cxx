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

  template<typename A>
  struct complex_argument_wrapper {
    class_<A> value;
    complex_argument_wrapper(cl_object o) : value(o) {}
  };

  template<typename A>
  struct argument_wrapper : public complex_argument_wrapper<A> {};

  template<typename A>
  struct argument_wrapper<A&> : public argument_wrapper<A> {
    typedef argument_wrapper<A> parent;
    argument_wrapper(cl_object o) : parent(o) {}
  };

#define DEF_CL_CXX_SIMPLE_ARGUMENT(T) \
  template<> struct argument_wrapper<T> {				\
    T value;								\
    argument_wrapper(cl_object o) : value(from_cl_object<T>(o)) {} };

  DEF_CL_CXX_SIMPLE_ARGUMENT(int);
  DEF_CL_CXX_SIMPLE_ARGUMENT(unsigned int);
  DEF_CL_CXX_SIMPLE_ARGUMENT(long);
  DEF_CL_CXX_SIMPLE_ARGUMENT(unsigned long);
  DEF_CL_CXX_SIMPLE_ARGUMENT(double);
  DEF_CL_CXX_SIMPLE_ARGUMENT(float);
  DEF_CL_CXX_SIMPLE_ARGUMENT(std::string);

} // namespace cl_cxx

#endif CL_CXX_ARGUMENT_H
