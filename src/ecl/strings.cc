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

#include <string>
#include <ecl/ecl.h>
#include <cl-cxx/object.hpp>

namespace cl_cxx {

  template<> cl_object to_cl_object(const std::string &s)
  {
    cl_object output = make_base_string_copy(s.c_str());
  }

  template<> std::string from_cl_object<std::string>(cl_object o)
  {
    o = si_coerce_to_base_string(o);
    return std::string((const char *)o->base_string.self);
  }

} // namespace cl_cxx
