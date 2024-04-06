#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include <../../include/stb_image.h>

Image::Image(const unsigned int image_width, const unsigned int image_height, const std::vector<char>& image_data, const Format image_format)
    : width_(image_width), height_(image_height), data_(image_data), format_(image_format) { }

Image Image::LoadImage(const std::string& path) {
    int x;
    int y;
    int channels;
    Format format;

    std::unique_ptr<stbi_uc> data = std::unique_ptr<stbi_uc>(stbi_load(("res/texture/" + path).c_str(), &x, &y, &channels, 0));

    if (data == nullptr)
        throw STBImageError(path + '\n' + "Failed to load image.");

    switch (channels) {
        case 3:
            format = RGB;
            break;

        case 4:
            format = RGBA;
            break;

        default:
            throw STBImageError("Incorrect number of channels (" + std::to_string(channels) + ") in file: " + path);
    }

    int size = x * y * channels;
    return Image(x, y, std::vector<char>{data.get(), data.get() + size}, format);
}
