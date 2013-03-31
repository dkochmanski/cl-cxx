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

#include <ecl/ecl.h>
#include <cl-cxx/object.hpp>

namespace cl_cxx {

  /************************************************************
   * FROM LISP TO C++
   */

  template<> cl_object to_cl_object(int i)
  {
    return ecl_make_fixnum(i);
  }

  template<> cl_object to_cl_object(unsigned int i)
  {
    return ecl_make_fixnum(i);
  }

  template<> cl_object to_cl_object(long i)
  {
    return ecl_make_long(i);
  }

  template<> cl_object to_cl_object(unsigned long i)
  {
    return ecl_make_ulong(i);
  }

  template<> cl_object to_cl_object(float i)
  {
    return ecl_make_single_float(i);
  }

  template<> cl_object to_cl_object(double i)
  {
    return ecl_make_double_float(i);
  }

  /************************************************************
   * FROM C++ TO LISP
   */

  template<> int from_cl_object(cl_object o)
  {
    return ecl_fixnum(o);
  }

  template<> unsigned int from_cl_object(cl_object o)
  {
    return ecl_fixnum(o);
  }

  template<> long from_cl_object(cl_object o)
  {
    return ecl_to_long(o);
  }

  template<> unsigned long from_cl_object(cl_object o)
  {
    return ecl_to_ulong(o);
  }

  template<> float from_cl_object(cl_object o)
  {
    return ecl_to_float(o);
  }

  template<> double from_cl_object(cl_object o)
  {
    return ecl_to_double(o);
  }

} // namespace cl_cxx
