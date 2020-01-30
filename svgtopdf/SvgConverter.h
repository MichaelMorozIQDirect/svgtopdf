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

private:
	float distPtSeg(float x, float y, float px, float py, float qx, float qy);
	void pdfcubicBez(HPDF_Page page, float x1, float y1, float x2, float y2,
		float x3, float y3, float x4, float y4,
		float tol, int level, Vector2f startPoint);
	void pdfPath(HPDF_Page page, float* pts, int npts, char closed, float tol, bool bFilled,
		Vector2f startPoint);
};

#endif //__SVG_CONVERTER_H__