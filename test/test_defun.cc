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

#include <gtest/gtest.h>
#include <gtest/gtest-death-test.h>
#include "common.hpp"
#include <cl-cxx/defun.hpp>

namespace cl_cxx_test {

  using namespace cl_cxx;

  int f_int_int(int i) {
    return 1+i;
  }

  TEST(Defun, DefunInt1) {
    defun("FOO", f_int_int);
    ASSERT_EQ(1, from_cl_object<int>(eval_string("(FOO 0)")));
    ASSERT_EQ(0, from_cl_object<int>(eval_string("(FOO -1)")));
    ASSERT_EQ(2, from_cl_object<int>(eval_string("(FOO 1)")));
  }

  int f_int_int_ref(int &i) {
    int output = i + 1;
    i = i + 2;
    return output;
  }

  TEST(Defun, DefunIntRef1) {
    defun("FOO", f_int_int_ref);
    ASSERT_T(eval_string("(EQUAL (print (MULTIPLE-VALUE-LIST (FOO 0))) '(1 2))"));
    ASSERT_T(eval_string("(EQUAL (MULTIPLE-VALUE-LIST (FOO 1)) '(2 3))"));
    ASSERT_T(eval_string("(EQUAL (MULTIPLE-VALUE-LIST (FOO 2)) '(3 4))"));
  }

} // cl_cxx_test
