#include <cstdlib> 
#include <cstdio> 
#include <iostream>

class Image {
    private:
        float r, g, b;
        struct RGB;
    public:
        const RGB& operator [] (const unsigned int &i) const;
        RGB& operator [] (const unsigned int &i) ;
};