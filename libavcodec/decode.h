/*
 * generic decoding-related code
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_DECODE_H
#define AVCODEC_DECODE_H

#include "libavutil/buffer.h"
#include "libavutil/frame.h"
#include "libavutil/hwcontext.h"

#include "avcodec.h"

/**
 * Called by decoders to get the next packet for decoding.
 *
 * @param pkt An empty packet to be filled with data.
 * @return 0 if a new reference has been successfully written to pkt
 *         AVERROR(EAGAIN) if no data is currently available
 *         AVERROR_EOF if and end of stream has been reached, so no more data
 *                     will be available
 */
int ff_decode_get_packet(AVCodecContext *avctx, AVPacket *pkt);

void ff_decode_bsfs_uninit(AVCodecContext *avctx);

/**
 * Make sure avctx.hw_frames_ctx is set. If it's not set, the function will
 * try to allocate it from hw_device_ctx. If that is not possible, an error
 * message is printed, and an error code is returned.
 */
int ff_decode_get_hw_frames_ctx(AVCodecContext *avctx,
                                enum AVHWDeviceType dev_type);

#endif /* AVCODEC_DECODE_H */
