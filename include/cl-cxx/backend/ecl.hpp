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

#ifndef CL_CXX_BACKEND_ECL_H
#define CL_CXX_BACKEND_ECL_H

#include <ecl/ecl.h>

namespace cl_cxx_backend {

  typedef ::cl_object cl_object;

  typedef cl_object cl_arglist;

  extern const cl_object nil;
  extern const cl_object t;

  /** Extract the nth-argument from the call we just constructed. */
  cl_object nth_arg(cl_arglist arglist, int n);

  /** Return a Common Lisp object that wraps around a pointer. */
  cl_object make_foreign_data(void *p);

  typedef cl_object (*callback_t)(void *f, cl_arglist);

  /** Define a Common Lisp function that invokes the corresponding callback. */
  void define_function(cl_object symbol, callback_t callback, void *f);
  void define_function(const char *symbol_name, callback_t callback, void *f);

  /** Call a Common Lisp function with a variable number of arguments. */
  extern const cl_object (*funcall)(::cl_narg narg, cl_object ...);

  /** Find a symbol in a package. */
  cl_object symbol(const char *package, const char *name);

  /** Find a symbol in the CL package. */
  cl_object symbol(const char *name);

  /** Eval a string expression. */
  cl_object eval_string(const char *string, cl_object error_value);
  cl_object eval_string(const char *string);

  /** Object to use for returning multiple values. */
  struct return_stack {
    /** The type of value that a C function must return. */
    typedef cl_object value;
    /** The creator with no values. */
    return_stack() : env(ecl_process_env()) {
      env->nvalues = 0;
      env->values[0] = ECL_NIL;
    }
    /** A function to add one value at a time. */
    return_stack &operator<<(cl_object o) {
      env->values[env->nvalues++] = o;
      return *this;
    }
    /** A function to finally return all the values that were grouped. */
    value return_value() {
      return env->values[0];
    }
  private:
    /* Copy constructors are hidden and forbidden. */
    return_stack(const return_stack &s);
    const return_stack &operator=(const return_stack &s);
    const cl_env_ptr env;
  };

} // namespace cl_cxx_backend

#endif // CL_CXX_BACKEND_ECL_H
