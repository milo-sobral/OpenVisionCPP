
#include "image.hpp"

class Image {

    // Represents a pixel
    struct RGB {
        // List of constructors
        RGB(): r(0), g(0), b(0) {}
        RGB(float f): r(f), g(f), b(f) {}
        RGB(float rr, float gg, float bb): r(rr), g(gg), b(bb) {}

        // Overloading operators
        bool operator != (const RGB &pixel) const {
            return (pixel.r != r || pixel.g != g || pixel.b != b);
        }

        RGB& operator *= (const RGB &pixel) { 
            r *= pixel.r, g *= pixel.g, b *= pixel.b; 
            return *this; 
        } 

        RGB operator += (const RGB &pixel) { 
            r += pixel.r, g += pixel.g, b += pixel.b; 
            return *this; 
        } 

        friend float& operator += (float &f, const RGB pixel) { 
            f += (pixel.r + pixel.g + pixel.b) / 3.f; 
            return f; 
        }

        float r, g, b;
    };

    // Constructors of an Image
    Image() : w(0), h(0), pixels(nullptr) { 
        /* empty image */ 
    }
    Image(const unsigned int &_w, const unsigned int &_h, const RGB &color = kBlack) : 
        w(_w), h(_h), pixels(NULL) 
    { 
        pixels = new RGB[w * h]; 
        for (int i = 0; i < w * h; ++i) 
            pixels[i] = color; 
    } 

    // Overloading operators
    const RGB& operator [] (const unsigned int &i) const { 
        return pixels[i]; 
    } 
    RGB& operator [] (const unsigned int &i) { 
        return pixels[i]; 
    } 

    // Class variables
    unsigned int w, h; // Image resolution 
    RGB *pixels; // 1D array of pixels 
    static RGB kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
};

Image::RGB Image::kBlack = Image::RGB(0); 
Image::RGB Image::kWhite = Image::RGB(1); 
Image::RGB Image::kRed = Image::RGB(1,0,0); 
Image::RGB Image::kGreen = Image::RGB(0,1,0); 
Image::RGB Image::kBlue = Image::RGB(0,0,1); 