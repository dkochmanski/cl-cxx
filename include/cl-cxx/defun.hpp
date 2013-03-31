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
#include <cl-cxx/base.hpp>
#include <cl-cxx/wrapper.hpp>

#ifndef CL_CXX_DEFUN_H
#define CL_CXX_DEFUN_H

namespace cl_cxx {

  template<class F>
  inline void defun(cl_object symbol, F f) {
    struct Foo {
      static cl_object callback(void *f, cl_arglist arglist) {
	return wrap((F)f, arglist);
      }
    };
    define_function(symbol, Foo::callback, (void*)f);
  }

  template<class F>
  inline void defun(const char *symbol_name, F f) {
    struct Foo {
      static cl_object callback(void *f, cl_arglist arglist) {
	return wrap((F)f, arglist);
      }
    };
    define_function(symbol_name, Foo::callback, (void*)f);
  }

}

#endif // CL_CXX_DEFUN_H
