//hxcpp include should be first
#include <hxcpp.h>

#include "./linc_stb_image_resize.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "../lib/stb_image_resize2.h"

namespace linc {

    namespace stb_image_resize {

        Dynamic to_image_resize_data(Array<unsigned char> bytes, int w, int h);
        Array<unsigned char> to_haxe_bytes(unsigned char* image_bytes, int length);

        Dynamic resize_uint8_srgb(Array<unsigned char> inputPixels, unsigned int byteOffset, unsigned int byteLength, int inputW, int inputH, int inputStrideInBytes, int outputW, int outputH, int outputStrideInBytes, int pixelLayout, int comp)
	    {
            unsigned char *image_bytes = stbir_resize_uint8_srgb(
                &inputPixels[0] + byteOffset, inputW, inputH, inputStrideInBytes,
                NULL, outputW, outputH, outputStrideInBytes,
                (stbir_pixel_layout)pixelLayout
            );

            if (!image_bytes) return null();

            Array<unsigned char> bytes = to_haxe_bytes(image_bytes, outputW * outputH * comp);

            return to_image_resize_data(bytes, outputW, outputH);
	    }

	    Dynamic resize_uint8_linear(Array<unsigned char> inputPixels, unsigned int byteOffset, unsigned int byteLength, int inputW, int inputH, int inputStrideInBytes, int outputW, int outputH, int outputStrideInBytes, int pixelLayout, int comp)
	    {
            unsigned char *image_bytes = stbir_resize_uint8_linear(
                &inputPixels[0] + byteOffset, inputW, inputH, inputStrideInBytes,
                NULL, outputW, outputH, outputStrideInBytes,
                (stbir_pixel_layout)pixelLayout
            );

            if (!image_bytes) return null();

            Array<unsigned char> bytes = to_haxe_bytes(image_bytes, outputW * outputH * comp);

            return to_image_resize_data(bytes, outputW, outputH);
	    }

            //note this calls free on the image_bytes
        Array<unsigned char> to_haxe_bytes(unsigned char* image_bytes, int length) {

            Array<unsigned char> haxe_bytes = new Array_obj<unsigned char>(length,length);

            memcpy(haxe_bytes->GetBase(), image_bytes, length);

            free(image_bytes);

            return haxe_bytes;

        } //to_haxe_bytes

        Dynamic to_image_resize_data(Array<unsigned char> bytes, int w, int h) {

            hx::Anon result = hx::Anon_obj::Create();

                result->Add(HX_CSTRING("w"), w);
                result->Add(HX_CSTRING("h"), h);
                result->Add(HX_CSTRING("bytes"), bytes);

            return result;

        } //to_image_resize_data

    } //stb_image_resize namespace

} //linc