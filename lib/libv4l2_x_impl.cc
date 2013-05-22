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
    libv4l2_x::make(const char *filename)
    {
      return gnuradio::get_initial_sptr (new libv4l2_x_impl(filename));
    }

    /*
     * The private constructor
     */
    libv4l2_x_impl::libv4l2_x_impl(const char *filename)
      : gr_sync_block("libv4l2_x",
              gr_make_io_signature(0, 0, 0),
              gr_make_io_signature(1, 1, sizeof (gr_complex)))
    {
        fd = v4l2_open(filename, O_RDWR | O_NONBLOCK, 0);
        if (fd < 0) {
            perror(filename);
            throw std::runtime_error("can't open file");
        }
    }

    /*
     * Our virtual destructor.
     */
    libv4l2_x_impl::~libv4l2_x_impl()
    {
        if (fd > 0)
            v4l2_close(fd);
    }

    int
    libv4l2_x_impl::work(int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items)
    {
        gr_complex *out = (gr_complex *) output_items[0];
        int ret, errors = 0, i;

        // Read data from device
        ret = v4l2_read(fd, out, noutput_items * sizeof (gr_complex));

        // Tell runtime system how many output items we produced.
        if (ret > 0)
            ret = ret / sizeof (gr_complex);
        else
            ret = 0;

        return ret;
    }

  } /* namespace kernel */
} /* namespace gr */

