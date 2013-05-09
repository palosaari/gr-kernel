/* -*- c++ -*- */
/* 
 * Copyright 2013 Antti Palosaari <crope@iki.fi>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include "libv4l2_x_impl.h"

namespace gr {
  namespace kernel {

    libv4l2_x::sptr
    libv4l2_x::make()
    {
      return gnuradio::get_initial_sptr (new libv4l2_x_impl());
    }

    /*
     * The private constructor
     */
    libv4l2_x_impl::libv4l2_x_impl()
      : gr_sync_block("libv4l2_x",
		      gr_make_io_signature(0, 0, 0),
		      gr_make_io_signature(<+MIN_IN+>, <+MAX_IN+>, sizeof (<+float+>)))
    {}

    /*
     * Our virtual destructor.
     */
    libv4l2_x_impl::~libv4l2_x_impl()
    {
    }

    int
    libv4l2_x_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const float *in = (const float *) input_items[0];
        float *out = (float *) output_items[0];

        // Do <+signal processing+>

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace kernel */
} /* namespace gr */

