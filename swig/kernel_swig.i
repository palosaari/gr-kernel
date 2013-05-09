/* -*- c++ -*- */

#define KERNEL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "kernel_swig_doc.i"

%{
#include "kernel/libv4l2_x.h"
%}


%include "kernel/libv4l2_x.h"
GR_SWIG_BLOCK_MAGIC2(kernel, libv4l2_x);
