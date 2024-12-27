#ifndef _BLUR_H_
#define _BLUR_H_

#include "bmp.h"

void simple_blur(BMP_IMAGE *image, const char *output_file);
void gaussian_blur(BMP_IMAGE *image, const char *output_file);

#endif