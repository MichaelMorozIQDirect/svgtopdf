#ifndef __SVG_CONVERTER_H__
#define __SVG_CONVERTER_H__

#include <string>
#include <nanosvg.h>
#include <hpdf.h>

typedef struct {
	float x;
	float y;
}Vector2f;

class SvgConverter {

private:

	NSVGimage * g_image; 
	std::string fileName;

public:
	SvgConverter(std::string fileName);
	SvgConverter();
	bool isLoaded();
	bool loadFromFile(std::string fileName);
	bool convertToPDF(std::string fileName);
	
	~SvgConverter();
};

#endif //__SVG_CONVERTER_H__
