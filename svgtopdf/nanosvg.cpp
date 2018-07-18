#include "stdafx.h"

// This file is neded to imporve compilation performance: not to recompile nanosvg each time the 
// main files are rebuilt

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"