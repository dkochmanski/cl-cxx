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

#include <cstring>
#include <ecl/ecl.h>
#include <ecl/ecl-inl.h>
#include <cl-cxx/backend/ecl.hpp>

namespace cl_cxx_backend {

  cl_object symbol(const char *package, const char *name) {
    cl_object p = ecl_find_package(package);
    return _ecl_intern(name, p);
  }

  cl_object symbol(const char *name) {
    return symbol("CL", name);
  }

} // namespace cl_cxx_backend
