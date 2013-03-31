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

#ifndef CL_CXX_OBJECT_H
#define CL_CXX_OBJECT_H

#include <string>
#include <cl-cxx/base.hpp>
#include <cl-cxx/class.hpp>

namespace cl_cxx {

  template<class A>
  inline cl_object to_cl_object(A o)
  {
    return cl_cxx_backend::make_foreign_data(new class_<A>(o));
  }

  template<class A>
  inline cl_object to_cl_object(A *o)
  {
    return cl_cxx_backend::make_foreign_data(new class_<A>(o));
  }

  template<> extern cl_object to_cl_object(int i);
  template<> extern cl_object to_cl_object(long i);
  template<> extern cl_object to_cl_object(unsigned long i);
  template<> extern cl_object to_cl_object(float i);
  template<> extern cl_object to_cl_object(double i);
  template<> extern cl_object to_cl_object(const std::string &s);

  template<class A>
  inline A from_cl_object(cl_object o)
  {
    return class_<A>().from_cl_object(o);
  }

  template<> extern int from_cl_object<int>(cl_object o);
  template<> extern long from_cl_object<long>(cl_object o);
  template<> extern unsigned long from_cl_object<unsigned long>(cl_object o);
  template<> extern float from_cl_object<float>(cl_object o);
  template<> extern double from_cl_object<double>(cl_object o);
  template<> extern std::string from_cl_object<std::string>(cl_object o);

} // namespace cl_cxx

#endif // CL_CXX_OBJECT_H
