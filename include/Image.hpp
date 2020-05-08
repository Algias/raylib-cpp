#ifndef RAYLIB_CPP_IMAGE_HPP_
#define RAYLIB_CPP_IMAGE_HPP_



#include "./raylib-cpp-utils.hpp"
namespace raylib {
#include <string>
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifdef __cplusplus
	}
#endif
}

#include <Rectangle.hpp>
#include <Font.hpp>
namespace raylibcpp {

	class Image : public raylib::Image {
	public:
		Image() {};
		Image(raylib::Image image) {
			set(image);
		}
		Image(const std::string& fileName) {
			Load(fileName);
		}
		Image(raylib::Color* pixels, int width, int height) {
			LoadEx(pixels, width, height);
		}
		Image(void* data, int width, int height, int format) {
			LoadPro(data, width, height, format);
		}
		Image(const std::string& fileName, int width, int height, int format, int headerSize) {
			LoadRaw(fileName, width, height, format, headerSize);
		}
		Image(raylib::Texture2D texture) {
			set(raylib::GetTextureData(texture));
		}
		Image(int width, int height, Color color = Color::RayWhite) {
			set(raylib::GenImageColor(width, height, color));
		}

		static Image Text(std::string text, int fontSize, Color color) {
			return raylib::ImageText(text.c_str(), fontSize, color);
		}

		static Image Text(Font font, std::string text, float fontSize, float spacing, Color tint) {
			return raylib::ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
		}

		static Image GetScreenData() {
			return Image(raylib::GetScreenData());
		}

		static Image GenColor(int width, int height, Color color) {
			return raylib::GenImageColor(width, height, color);
		}

		static Image GenGradientV(int width, int height, Color top, Color bottom) {
			return raylib::GenImageGradientV(width, height, top, bottom);
		}

		static Image GenGradientH(int width, int height, Color left, Color right) {
			return raylib::GenImageGradientH(width, height, left, right);
		}

		static Image GenGradientRadial(int width, int height, float density, Color inner, Color outer) {
			return raylib::GenImageGradientRadial(width, height, density, inner, outer);
		}

		static Image GenChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
			return raylib::GenImageChecked(width, height, checksX, checksY, col1, col2);
		}

		static Image GenWhiteNoise(int width, int height, float factor) {
			return raylib::GenImageWhiteNoise(width, height, factor);
		}

		static Image GenPerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
			return raylib::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
		}

		static Image GenCellular(int width, int height, int tileSize) {
			return raylib::GenImageCellular(width, height, tileSize);
		}

		~Image() {
			Unload();
		};

		Image& operator=(const raylib::Image& image) {
			set(image);
			return *this;
		}

		raylib::Image& operator=(const Image& image) {
			set(image);
			return *this;
		}

		inline void set(raylib::Image image) {
			data = image.data;
			width = image.width;
			height = image.height;
			mipmaps = image.mipmaps;
			format = image.format;
		}

		void Load(const std::string& fileName) {
			set(raylib::LoadImage(fileName.c_str()));
		}

		void LoadEx(raylib::Color* pixels, int width, int height) {
			set(raylib::LoadImageEx(pixels, width, height));
		}

		void LoadPro(void* data, int width, int height, int format) {
			set(raylib::LoadImagePro(data, width, height, format));
		}

		void LoadRaw(const std::string& fileName, int width, int height, int format, int headerSize) {
			set(raylib::LoadImageRaw(fileName.c_str(), width, height, format, headerSize));
		}

		inline void Unload() {
			raylib::UnloadImage(*this);
		};

		inline Image& Export(const std::string& fileName) {
			raylib::ExportImage(*this, fileName.c_str());
			return *this;
		}
		inline Image& ExportAsCode(const std::string& fileName) {
			raylib::ExportImageAsCode(*this, fileName.c_str());
			return *this;
		}

		GETTERSETTER(void*, Data, data)
			GETTERSETTER(int, Width, width)
			GETTERSETTER(int, Height, height)
			GETTERSETTER(int, Mipmaps, mipmaps)
			GETTERSETTER(int, Format, format)

			inline Image Copy() {
			return raylib::ImageCopy(*this);
		}
		inline Image FromImage(raylib::Rectangle rec) {
			return raylib::ImageFromImage(*this, rec);
		}

		inline Image& ToPOT(Color fillColor) {
			raylib::ImageToPOT(this, fillColor);
			return *this;
		}

		inline Image& Format(int newFormat) {
			raylib::ImageFormat(this, newFormat);
			return *this;
		}

		inline Image& AlphaMask(Image alphaMask) {
			raylib::ImageAlphaMask(this, alphaMask);
			return *this;
		}

		inline Image& AlphaCrop(float threshold) {
			raylib::ImageAlphaCrop(this, threshold);
			return *this;
		}

		inline Image& AlphaPremultiply() {
			raylib::ImageAlphaPremultiply(this);
			return *this;
		}

		inline Image& Crop(raylib::Rectangle crop) {
			raylib::ImageCrop(this, crop);
			return *this;
		}
		inline Image& Resize(int newWidth, int newHeight) {
			raylib::ImageResize(this, newWidth, newHeight);
			return *this;
		}
		inline Image& ResizeNN(int newWidth, int newHeight) {
			raylib::ImageResizeNN(this, newWidth, newHeight);
			return *this;
		}
		inline Image& ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color color) {
			raylib::ImageResizeCanvas(this, newWidth, newHeight, offsetX, offsetY, color);
			return *this;
		}
		inline Image& Mipmaps() {
			raylib::ImageMipmaps(this);
			return *this;
		}
		inline Image& Dither(int rBpp, int gBpp, int bBpp, int aBpp) {
			raylib::ImageDither(this, rBpp, gBpp, bBpp, aBpp);
			return *this;
		}

		inline Image& FlipVertical() {
			raylib::ImageFlipVertical(this);
			return *this;
		}
		inline Image& FlipHorizontal() {
			raylib::ImageFlipHorizontal(this);
			return *this;
		}

		inline Image& RotateCW() {
			raylib::ImageRotateCW(this);
			return *this;
		}
		inline Image& RotateCCW() {
			raylib::ImageRotateCCW(this);
			return *this;
		}
		inline Image& ColorTint(raylib::Color color = WHITE) {
			raylib::ImageColorTint(this, color);
			return *this;
		}
		inline Image& ColorInvert() {
			raylib::ImageColorInvert(this);
			return *this;
		}
		inline Image& ColorGrayscale() {
			raylib::ImageColorGrayscale(this);
			return *this;
		}
		inline Image& ColorContrast(float contrast) {
			raylib::ImageColorContrast(this, contrast);
			return *this;
		}
		inline Image& ColorBrightness(int brightness) {
			raylib::ImageColorBrightness(this, brightness);
			return *this;
		}
		inline Image& ColorReplace(raylib::Color color, raylib::Color replace) {
			raylib::ImageColorReplace(this, color, replace);
			return *this;
		}

		inline raylib::Color* ExtractPalette(int maxPaletteSize, int* extractCount) {
			return raylib::ImageExtractPalette(*this, maxPaletteSize, extractCount);
		}

		inline Rectangle GetAlphaBorder(float threshold) {
			return raylib::GetImageAlphaBorder(*this, threshold);
		}

		inline Image& ClearBackground(raylib::Color color = WHITE) {
			raylib::ImageClearBackground(this, color);
			return *this;
		}

		inline Image& DrawPixel(int posX, int posY, raylib::Color color) {
			raylib::ImageDrawPixel(this, posX, posY, color);
			return *this;
		}

		inline Image& DrawPixel(raylib::Vector2 position, raylib::Color color) {
			raylib::ImageDrawPixelV(this, position, color);
			return *this;
		}

		inline Image& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, raylib::Color color) {
			raylib::ImageDrawLine(this, startPosX, startPosY, endPosX, endPosY, color);
			return *this;
		}

		inline Image& DrawLine(raylib::Vector2 start, raylib::Vector2 end, raylib::Color color) {
			raylib::ImageDrawLineV(this, start, end, color);
			return *this;
		}

		inline Image& DrawCircle(int centerX, int centerY, int radius, raylib::Color color) {
			raylib::ImageDrawCircle(this, centerX, centerY, radius, color);
			return *this;
		}

		inline Image& DrawCircle(raylib::Vector2 center, int radius, raylib::Color color) {
			raylib::ImageDrawCircleV(this, center, radius, color);
			return *this;
		}
		inline Image& DrawRectangle(int posX, int posY, int width, int height, raylib::Color color = WHITE) {
			raylib::ImageDrawRectangle(this, posX, posY, width, height, color);
			return *this;
		}
		inline Image& DrawRectangle(Vector2 position, Vector2 size, raylib::Color color = WHITE) {
			raylib::ImageDrawRectangleV(this, position, size, color);
			return *this;
		}
		inline Image& DrawRectangle(raylib::Rectangle rec, raylib::Color color = WHITE) {
			raylib::ImageDrawRectangleRec(this, rec, color);
			return *this;
		}
		inline Image& DrawRectangleLines(raylib::Rectangle rec, int thick, raylib::Color color) {
			raylib::ImageDrawRectangleLines(this, rec, thick, color);
			return *this;
		}
		inline Image& Draw(raylib::Image& src, raylib::Rectangle srcRec, raylib::Rectangle dstRec, raylib::Color tint = WHITE) {
			raylib::ImageDraw(this, src, srcRec, dstRec, tint);
			return *this;
		}

		inline Image& DrawText(raylib::Vector2 position, const std::string& text, int fontSize, raylib::Color color = WHITE) {
			raylib::ImageDrawText(this, position, text.c_str(), fontSize, color);
			return *this;
		}
		inline Image& DrawText(raylib::Vector2 position, raylib::Font font, const std::string& text, float fontSize, float spacing, raylib::Color color = WHITE) {
			raylib::ImageDrawTextEx(this, position, font, text.c_str(), fontSize, spacing, color);
			return *this;
		}

		inline raylib::Color* GetImageData() {
			return raylib::GetImageData(*this);
		}

		inline raylib::Vector4* GetImageDataNormalized() {
			return raylib::GetImageDataNormalized(*this);
		}
		inline operator raylib::Texture2D() {
			return raylib::LoadTextureFromImage(*this);
		}
	};
}

#endif
