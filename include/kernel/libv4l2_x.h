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


#ifndef INCLUDED_KERNEL_LIBV4L2_X_H
#define INCLUDED_KERNEL_LIBV4L2_X_H

#include <kernel/api.h>
#include <gr_sync_block.h>

#include <libv4l2.h>
#include <fcntl.h>

namespace gr {
  namespace kernel {

    /*!
     * \brief <+description of block+>
     * \ingroup kernel
     *
     */
    class KERNEL_API libv4l2_x : virtual public gr_sync_block
    {
    public:
       typedef boost::shared_ptr<libv4l2_x> sptr;

       /*!
        * \brief Return a shared_ptr to a new instance of kernel::libv4l2_x.
        *
        * To avoid accidental use of raw pointers, kernel::libv4l2_x's
        * constructor is in a private implementation
        * class. kernel::libv4l2_x::make is the public interface for
        * creating new instances.
        */
       static sptr make(const char *filename);
    };

  } // namespace kernel
} // namespace gr

#endif /* INCLUDED_KERNEL_LIBV4L2_X_H */

