#pragma once

#include <vector>
#include <string>
#include <memory>

#include "../Exceptions/Exceptions.h"

class Image {
public:
    enum Format {
        RGB, RGBA
    };

    Image(const unsigned int image_width, const unsigned int image_height, const std::vector<char>& image_data, const Format image_format);
    static Image LoadImage(const std::string& path);

private:
    Format format_;
    unsigned int width_;
    unsigned int height_;
    std::vector<char> data_;

public:
    inline Format GetFormat() const {
        return format_;
    }

    inline unsigned GetWidth() const {
        return width_;
    }

    inline unsigned GetHeight() const {
        return height_;
    }

    inline const std::vector<char>& GetData() const {
        return data_;
    }
};
