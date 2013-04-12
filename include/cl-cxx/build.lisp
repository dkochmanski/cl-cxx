(defun wrapper (arg-list)
  (format t "
#include <cl-cxx/base.hpp>
#include <cl-cxx/argument.hpp>

namespace cl_cxx {

using namespace cl_cxx_backend;

")
  (loop for l in arg-list
     do (format t "
template<class Ret~{, class T~A~}>
inline cl_object wrap(Ret F(~:*~{T~A a~:*~A~^, ~}), cl_arglist a) {~:*~{
  argument_wrapper<T~A> b~:*~A(nth_arg(a, ~:*~A));~}
  return to_cl_object(F(~:*~{b~A.value~^, ~}));
}
"
		l))
  (format t "
} // namespace cl_cxx
"))

(defun create-header (filename template &key (depth 10))
  (let ((conditional (format nil "CL_CXX_~A_H" (string-upcase (pathname-name filename)))))
    (with-open-file (*standard-output* filename
		     :direction :output :if-exists :supersede
		     :if-does-not-exist :create)
      (format t "// -*- mode: c++; fill-column: 80; c-basic-offset: 2; indent-tabs-mode: nil -*-
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
#ifndef ~A
#define ~:*~A
"
	      conditional)
      (funcall template
	       (loop with arg = '()
		  for i from 1 to (1+ depth)
		  collect (reverse arg)
		  do (push i arg)))
      (format t "#endif // ~A~%" conditional))))

(create-header (merge-pathnames "wrapper.hpp" *load-truename*) #'wrapper)

#+ecl
(ext:quit)
