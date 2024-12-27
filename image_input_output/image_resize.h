#ifndef _IMAGE_RESIZE_H_
#define _IMAGE_RESIZE_H_

#include "bmp.h"

//resize using the nearest neighbor interpolation method
BMP_IMAGE* resize_nearest_neighbor(BMP_IMAGE *image, 
                                   uint32_t new_width, 
                                   uint32_t new_height);



//other resize methods here...


#endif