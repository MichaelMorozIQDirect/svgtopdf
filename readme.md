Introduction
------------

This code was written to demonstrate the process of parsing vector **SVG** files in **C/C++ application**, working with Bezier curves, and saving the vector image to **PDF**. For the ease of understanding all processing in app only works in grayscale mode. The code was written for Windows, but has no Windows-only dependencies and can be easily ported to Linux or any embedded platform.

**Scalable Vector Graphics (SVG)** is a 2D vector image format widely used in Web development. The SVG format is heavily based on XML standard. While the raster image (PNG, JPG, GIF,  etc..) is composed of a fixed set of pixels, the vector SVG image is composed of a fixed set of shapes, like circles, lines, rectangles, Bezier curves etc. The advantage of SVG format is that it can be easily scaled to any level without the loss of quantity.

I have included a nice picture of cat here:
<img src="https://iq.direct/images/stories/svg/cat.svg" alt="Cat" width="200px"/>

**Bézier curve** is a parametric curve which is used to model smooth curves that can be scaled indefinitely. Bezier curve can be represented as a set of _control points_. Quadratic and cubic Bezier curves are most common. Higher degree curves are more computationally expensive to evaluate. When more complex shapes are needed, low order Bezier curves are patched together, producing a composite Bezier curve. A composite Bezier curve is commonly referred to as a _path_.

The **Portable Document Format (PDF)** is a file format to represent documents, including text formatting, raster images,vector graphics etc. Vector graphics in PDF are constructed with paths too. Paths are usually composed of lines and cubic Bezier curves, but can also be constructed from the outlines of text. Paths in PDF can be stroked, filled, clipping. Strokes and fills can use any color set in the graphics state, including patterns.

Background
----------

For the processing of SVG files I used brilliant library called [nanosvg](https://github.com/memononen/nanosvg). It is small and lightweight and can be used even in embedded development projects. To compose PDF files I have used write-only [libHaru](http://libharu.org/) library. Though not actively developed now (2017), it still can be used in C/C++ projects

Using the code
--------------

The `SvgConverter`  class is a basic workhorse to convert SVG to PDF. The same object can be used multiple to convert other images. You just need to call method that responsible for loading on other file.
```c++
//..
SvgConverter converter;
converter.loadFromFile(fileInput); // load svg image to inner buffer
converter.convertToPDF(fileOutput); // parse and write image from buffer to pdf file
//..
```
To approximate Bezier curve and draw it, we will use one of the properties of such curves.  
_Any cubic Bezier curve **B** from beginning to end can be divided into two curves, which together will describe the same curve as **B**._

Use from console
----------------

You can use an application from console to include in some batch processing. Application receives two command line arguments, where first argument is SVG file path and second is PDF file path.  
For example:
```
./svgtopdf cat.svg cat.pdf
```
Feedback
--------

I will be happy with any comments and suggestions. If you need some some custom app to be developed, feel free to [contact me for custom app development](https://iq.direct/contacts.html "Custom App Development - IQ Direct").

Good luck!