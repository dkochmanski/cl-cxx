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
#ifndef CL_CXX_WRAPPER_H
#define CL_CXX_WRAPPER_H

#include <cl-cxx/base.hpp>
#include <cl-cxx/argument.hpp>

namespace cl_cxx {

using namespace cl_cxx_backend;


template<class Ret>
inline cl_object wrap(Ret F(), cl_arglist a) {
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F());
  return (s).return_value();
}

template<class Ret, class T1>
inline cl_object wrap(Ret F(T1 a1), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value));
  return (s << b1).return_value();
}

template<class Ret, class T1, class T2>
inline cl_object wrap(Ret F(T1 a1, T2 a2), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value));
  return (s << b1 << b2).return_value();
}

template<class Ret, class T1, class T2, class T3>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value));
  return (s << b1 << b2 << b3).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value));
  return (s << b1 << b2 << b3 << b4).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value));
  return (s << b1 << b2 << b3 << b4 << b5).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  argument_wrapper<T6> b6(nth_arg(a, 6));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value, b6.value));
  return (s << b1 << b2 << b3 << b4 << b5 << b6).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  argument_wrapper<T6> b6(nth_arg(a, 6));
  argument_wrapper<T7> b7(nth_arg(a, 7));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value, b6.value, b7.value));
  return (s << b1 << b2 << b3 << b4 << b5 << b6 << b7).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  argument_wrapper<T6> b6(nth_arg(a, 6));
  argument_wrapper<T7> b7(nth_arg(a, 7));
  argument_wrapper<T8> b8(nth_arg(a, 8));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value, b6.value, b7.value, b8.value));
  return (s << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  argument_wrapper<T6> b6(nth_arg(a, 6));
  argument_wrapper<T7> b7(nth_arg(a, 7));
  argument_wrapper<T8> b8(nth_arg(a, 8));
  argument_wrapper<T9> b9(nth_arg(a, 9));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value, b6.value, b7.value, b8.value, b9.value));
  return (s << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << b9).return_value();
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10), cl_arglist a) {
  argument_wrapper<T1> b1(nth_arg(a, 1));
  argument_wrapper<T2> b2(nth_arg(a, 2));
  argument_wrapper<T3> b3(nth_arg(a, 3));
  argument_wrapper<T4> b4(nth_arg(a, 4));
  argument_wrapper<T5> b5(nth_arg(a, 5));
  argument_wrapper<T6> b6(nth_arg(a, 6));
  argument_wrapper<T7> b7(nth_arg(a, 7));
  argument_wrapper<T8> b8(nth_arg(a, 8));
  argument_wrapper<T9> b9(nth_arg(a, 9));
  argument_wrapper<T10> b10(nth_arg(a, 10));
  cl_cxx_backend::return_stack s;
  s << to_cl_object(F(b1.value, b2.value, b3.value, b4.value, b5.value, b6.value, b7.value, b8.value, b9.value, b10.value));
  return (s << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << b9 << b10).return_value();
}

} // namespace cl_cxx
#endif // CL_CXX_WRAPPER_H
