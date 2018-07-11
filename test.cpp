

#include "bitmap.h"

#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

int main(int args, char* argv[])
{
    Bitmap lil_mario_shroom;
    lil_mario_shroom.open("monochrome_image.bmp");
    assert(lil_mario_shroom.isImage());

    PixelMatrix pixels = lil_mario_shroom.toPixelMatrix();

    std::reverse(std::begin(pixels), std::end(pixels));

    lil_mario_shroom.fromPixelMatrix(pixels);

    lil_mario_shroom.save("REVERSED_monochrome_image.bmp");


    Bitmap test_image;
    PixelMatrix test_pixels(200, std::vector<Pixel>());
    for (int i = 0; i < 200; ++i)
    {
        for (int j = 0; j < 200; ++j)
            test_pixels[i].push_back(Pixel(j % 2 == 1));
    }
    test_image.fromPixelMatrix(test_pixels);
    assert(test_image.isImage());
    test_image.save("test_image.bmp");

    return 0;
}