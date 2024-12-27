#ifndef _EDGE_DETECTION_H_
#define _EDGE_DETECTION_H_

#include "bmp.h"

void sobel_edge_detection(BMP_IMAGE *image, const char *output_file);
void roberts_cross_edge_detection(BMP_IMAGE *image, const char *output_file);

#endif