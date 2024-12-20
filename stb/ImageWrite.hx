package stb;

import haxe.io.BytesData;

@:keep
#if !display
@:build(linc.Linc.touch())
@:build(linc.Linc.xml('stb_image_write'))
#end
@:include('linc_stb_image_write.h')
extern class ImageWrite {

	@:native("linc::stb_image_write::write_bmp")
	static function write_bmp(filename:String, w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int):Int;

	@:native("linc::stb_image_write::write_tga")
	static function write_tga(filename:String, w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int):Int;

	@:native("linc::stb_image_write::write_hdr")
	static function write_hdr(filename:String, w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int):Int;

	@:native("linc::stb_image_write::write_png")
	static function write_png(filename:String, w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int, stride_in_bytes:Int):Int;

	@:native("linc::stb_image_write::write_jpg")
	static function write_jpg(filename:String, w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int, quality:Int):Int;

	@:native("linc::stb_image_write::write_png_to_mem")
	static function write_png_to_mem(w:Int, h:Int, comp:Int, bytes:BytesData, byteOffset:Int, byteLength:Int, stride_in_bytes:Int):BytesData;

}
