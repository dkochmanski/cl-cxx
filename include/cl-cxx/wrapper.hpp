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
#include <cl-cxx/object.hpp>

namespace cl_cxx {

using namespace cl_cxx_backend;


template<class Ret>
inline cl_object wrap(Ret F(), cl_arglist a) {
  return to_cl_object(F());
}

template<class Ret, class T1>
inline cl_object wrap(Ret F(T1 a1), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1))));
}

template<class Ret, class T1, class T2>
inline cl_object wrap(Ret F(T1 a1, T2 a2), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2))));
}

template<class Ret, class T1, class T2, class T3>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3))));
}

template<class Ret, class T1, class T2, class T3, class T4>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5)), 
                        from_cl_object<T6>(nth_arg(a, 6))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5)), 
                        from_cl_object<T6>(nth_arg(a, 6)), 
                        from_cl_object<T7>(nth_arg(a, 7))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5)), 
                        from_cl_object<T6>(nth_arg(a, 6)), 
                        from_cl_object<T7>(nth_arg(a, 7)), 
                        from_cl_object<T8>(nth_arg(a, 8))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5)), 
                        from_cl_object<T6>(nth_arg(a, 6)), 
                        from_cl_object<T7>(nth_arg(a, 7)), 
                        from_cl_object<T8>(nth_arg(a, 8)), 
                        from_cl_object<T9>(nth_arg(a, 9))));
}

template<class Ret, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
inline cl_object wrap(Ret F(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10), cl_arglist a) {
  return to_cl_object(F(from_cl_object<T1>(nth_arg(a, 1)), 
                        from_cl_object<T2>(nth_arg(a, 2)), 
                        from_cl_object<T3>(nth_arg(a, 3)), 
                        from_cl_object<T4>(nth_arg(a, 4)), 
                        from_cl_object<T5>(nth_arg(a, 5)), 
                        from_cl_object<T6>(nth_arg(a, 6)), 
                        from_cl_object<T7>(nth_arg(a, 7)), 
                        from_cl_object<T8>(nth_arg(a, 8)), 
                        from_cl_object<T9>(nth_arg(a, 9)), 
                        from_cl_object<T10>(nth_arg(a, 10))));
}

} // namespace cl_cxx
#endif // CL_CXX_WRAPPER_H
