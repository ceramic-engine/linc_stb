#pragma once

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include "../lib/stb_image_resize2.h"

namespace linc {

    namespace stb_image_resize {

        extern Dynamic resize_uint8_srgb(Array<unsigned char> inputPixels, unsigned int byteOffset, unsigned int byteLength, int inputW, int inputH, int inputStrideInBytes, int outputW, int outputH, int outputStrideInBytes, int pixelLayout, int comp);

        extern Dynamic resize_uint8_linear(Array<unsigned char> inputPixels, unsigned int byteOffset, unsigned int byteLength, int inputW, int inputH, int inputStrideInBytes, int outputW, int outputH, int outputStrideInBytes, int pixelLayout, int comp);

    } //stb_image_resize namespace

} //linc
