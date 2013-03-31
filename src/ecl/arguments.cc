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

#include <iostream>
#include <ecl/ecl.h>
#include <ecl/internal.h>
#include <cl-cxx/backend/ecl.hpp>

namespace cl_cxx_backend {

  const cl_object (*funcall)(::cl_narg narg, cl_object ...) = cl_funcall;

  const cl_object nil = ECL_NIL;
  const cl_object t = ECL_T;

  cl_object nth_arg(cl_object arglist, int i)
  {
    if (i > arglist->frame.size) {
      std::cerr << "Missing argument #" << i << " in a CL-CXX wrapped function.\n";
      abort();
    }
    return ((cl_object*)arglist->frame.base)[i-1];
  }

  static
  cl_object callback_function(cl_narg narg, ...)
  {
    {
    cl_env_ptr the_env = ecl_process_env();
    cl_object output;
    ECL_STACK_FRAME_VARARGS_BEGIN(narg, narg, frame);
    {
      cl_object closure = the_env->function;
      cl_object closure_env = closure->cclosure.env;
      {
        cl_object env = closure_env;
        callback_t wrapper = (callback_t)ECL_CONS_CAR(closure_env);
        void *f = (void*)ECL_CONS_CDR(closure_env);
	output = wrapper(f, frame);
      }
    }
    ECL_STACK_FRAME_VARARGS_END(frame);
    ecl_return1(the_env, output);
    }
  }

  void define_function(cl_object symbol, callback_t callback, void *f)
  {
    cl_object env = ecl_cons((cl_object)callback, (cl_object)f);
    cl_object fn = ecl_make_cclosure_va(callback_function, env, ECL_NIL);
    si_fset(2, symbol, fn);
  }

  void define_function(const char *name, callback_t callback, void *f)
  {
    define_function(symbol(name), callback, f);
  }

} // namespace ecl_cxx_backend
