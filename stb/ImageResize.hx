package stb;

import haxe.io.BytesData;

enum abstract StbImageResizePixelLayout(Int) from Int to Int {

    var STBIR_1CHANNEL = 1;
    var STBIR_2CHANNEL = 2;
    var STBIR_RGB      = 3;               // 3-chan, with order specified (for channel flipping)
    var STBIR_BGR      = 0;               // 3-chan, with order specified (for channel flipping)
    var STBIR_4CHANNEL = 5;

    var STBIR_RGBA = 4;                   // alpha formats, where alpha is NOT premultiplied into color channels
    var STBIR_BGRA = 6;
    var STBIR_ARGB = 7;
    var STBIR_ABGR = 8;
    var STBIR_RA   = 9;
    var STBIR_AR   = 10;

    var STBIR_RGBA_PM = 11;               // alpha formats, where alpha is premultiplied into color channels
    var STBIR_BGRA_PM = 12;
    var STBIR_ARGB_PM = 13;
    var STBIR_ABGR_PM = 14;
    var STBIR_RA_PM   = 15;
    var STBIR_AR_PM   = 16;

    var STBIR_RGBA_NO_AW = 11;            // alpha formats, where NO alpha weighting is applied at all!
    var STBIR_BGRA_NO_AW = 12;            //   these are just synonyms for the _PM flags (which also do
    var STBIR_ARGB_NO_AW = 13;            //   no alpha weighting). These names just make it more clear
    var STBIR_ABGR_NO_AW = 14;            //   for some folks).
    var STBIR_RA_NO_AW   = 15;
    var STBIR_AR_NO_AW   = 16;

}

typedef StbImageResizeData = {

    var w: Int;
    var h: Int;
    var bytes: BytesData;

}

@:keep
#if !display
@:build(linc.Linc.touch())
@:build(linc.Linc.xml('stb_image_resize'))
#end
@:include('linc_stb_image_resize.h')
extern class ImageResize {

	@:native("linc::stb_image_resize::resize_uint8_srgb")
	static function resize_uint8_srgb(inputPixels:BytesData, byteOffset:Int, byteLength:Int, inputW:Int, inputH:Int, inputStrideInBytes:Int, outputW:Int, outputH:Int, outputStrideInBytes:Int, pixelLayout:StbImageResizePixelLayout, comp:Int):StbImageResizeData;

	@:native("linc::stb_image_resize::resize_uint8_linear")
	static function resize_uint8_linear(inputPixels:BytesData, byteOffset:Int, byteLength:Int, inputW:Int, inputH:Int, inputStrideInBytes:Int, outputW:Int, outputH:Int, outputStrideInBytes:Int, pixelLayout:StbImageResizePixelLayout, comp:Int):StbImageResizeData;

}
