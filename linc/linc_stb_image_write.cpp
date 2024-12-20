//hxcpp include should be first
#include <hxcpp.h>

#include "./linc_stb_image_write.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

namespace linc {

    namespace stb_image_write {

        Array<unsigned char> to_haxe_bytes(unsigned char* image_bytes, int length);

        int write_bmp(char const *filename, int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength)
	    {
	        return stbi_write_bmp(filename, x, y, comp, &bytes[0] + byteOffset);
	    }

	    int write_tga(char const *filename, int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength)
	    {
	        return stbi_write_tga(filename, x, y, comp, &bytes[0] + byteOffset);
	    }

	    int write_hdr(char const *filename, int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength)
	    {
	        return stbi_write_hdr(filename, x, y, comp, (float*)(&bytes[0] + byteOffset));
	    }

	    int write_png(char const *filename, int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength, int stride_in_bytes)
	    {
	        return stbi_write_png(filename, x, y, comp, &bytes[0] + byteOffset, stride_in_bytes);
	    }

	    int write_jpg(char const *filename, int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength, int quality)
	    {
	        return stbi_write_jpg(filename, x, y, comp, &bytes[0] + byteOffset, quality);
	    }

	    Array<unsigned char> write_png_to_mem(int x, int y, int comp, Array<unsigned char> bytes,
        	unsigned int byteOffset, unsigned int byteLength, int stride_in_bytes)
	    {
			int out_len = 0;
	    	unsigned char* image_bytes = stbi_write_png_to_mem(&bytes[0] + byteOffset, stride_in_bytes, x, y, comp, &out_len);
			return to_haxe_bytes(image_bytes, out_len);
	    }

        Array<unsigned char> to_haxe_bytes(unsigned char* image_bytes, int length) {

            Array<unsigned char> haxe_bytes = new Array_obj<unsigned char>(length,length);

            memcpy(haxe_bytes->GetBase(), image_bytes, length);

            STBIW_FREE(image_bytes);

            return haxe_bytes;

        } //to_haxe_bytes

    } //stb_image_write namespace

} //linc