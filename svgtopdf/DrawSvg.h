#pragma once
#include "stdafx.h"
#include <tchar.h>
#include <string>

extern "C" {
#include "libharu\hpdf.h"
#include "libharu\hpdf_utils.h"
}

class SVGManager {
	NSVGimage * g_image; 
	std::string fileName;

public:
	SVGManager(std::string fileName);
	SVGManager();
	bool isLoaded();
	bool loadFromFile(std::string fileName);
	bool convertToPDF(std::string fileName);
	
	~SVGManager();
};