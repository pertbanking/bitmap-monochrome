[//]: # @mainpage

# C++ Bitmap [monochrome] header files

This is a small library for writing monochrome bitmap files.

Monochromes can be used for several different things. You may want
to use this library as an image writer for a color threshold program, or, maybe
you want to borrow code from here to make your own Bitmap library more 
diverse. For whatever you use them for, monochromes can be quite pretty--- and 
they are extremely small!

__Mention__

This library was initially started by Kevin Buffardi, Ph.D at California 
State University, Chico. All I did was specialize it for monochrome bitmaps.
See his original repository here:

https://github.com/kbuffardi/Bitmap



## Getting Started

1. Clone this repository onto your development environment
2. Copy `bitmap.h` and `bitmap.cpp` to your project directory
3. In your C++ program file, include the header file `bitmap.h`
4. Declare your variables of type *Bitmap* or *Pixel*.

See the guides for the Bitmap and Pixel data types below.

## Pixel

Represents a single Pixel in the image. A Pixel is either on or off, 
essentially a `bool`, and that's exactly what it wraps--- one `bool`.

By default, a pixel is off. Its `bool` (`on`) is accessible as a public member.
See Pixel.


### Example of use

```
Pixel dot(true);

// ...

dot.on = false;
```


## Bitmap

Represents a bitmap where a grid of pixels (in row-major order)
describes the color of each pixel within the image. Limited to Windows BMP
formatted images with no compression and 1 bit color depth.


### Functions

#### open

`void open(std::string)`

*Opens a file as its name is provided and reads pixel-by-pixel the colors
into a matrix of pixels. Any errors will cout but will result in an
empty matrix (with no rows and no columns).*

*parameter: name of the filename to be opened and read as a matrix of pixels*

#### save

`void save(std::string) const`

*Saves the current image, represented by the matrix of pixels, as a
Windows BMP file with the name provided by the parameter. File extension
is not forced but should be .bmp. Any errors will cout and will NOT 
attempt to save the file.*

#### isImage

`bool isImage() const`

*Validates whether or not the current matrix of pixels represents a
proper image. Tests for non-zero-size rows and consistent non-zero-size columns 
for each row.*

*return: boolean value of whether or not the matrix is a valid image*

#### toPixelMatrix

`std::vector <std::vector <Pixel> > toPixelMatrix() const`

*Provides a vector of vector of pixels representing the bitmap*

*return: the bitmap image, represented by a matrix of pixels*

#### fromPixelMatrix

`void fromPixelMatrix(const std::vector <std::vector <Pixel> > &)`

*Overwrites the current bitmap with that represented by a matrix of
pixels. Does not validate that the new matrix of pixels is a proper
image.*

*parameter: a matrix of pixels to represent a bitmap*


### Example of use

Since monochromes online seem to be nonexistent, I have created one and 
attached it to this repository, entitled "monochrome_image.bmp". Feel free to 
view it for an example or for testing. 

```
#include <algorithm>
#include <memory>
#include <vector>
#include "bitmap.h"

using namespace std;

int main()
{
  Bitmap image;
  vector <vector <Pixel> > bmp;

  //read a file example.bmp and convert it to a pixel matrix
  image.open("example.bmp");

  //verify that the file opened was a valid image
  bool validBmp = image.isImage();

  //pull the Pixel matrix from the loaded file
  bmp = image.toPixelMatrix();

  //flip example.bmp vertically.
  std::reverse(std::begin(bmp), std::end(bmp));

  //save the image
  image.save("reversed.bmp");

  return 0;
}
```
