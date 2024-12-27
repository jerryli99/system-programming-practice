#ifndef _LSB_STEGANOGRAPHY_H_
#define _LSB_STEGANOGRAPHY_H_

#include <stdint.h>
#include <stdbool.h>

#include "bmp.h"

bool lsb_embed_data(BMP_IMAGE *image, 
                    const uint8_t *data, 
                    size_t data_size, 
                    const char *output_file);

bool lsb_extract_data(const BMP_IMAGE *image, 
                      uint8_t *data, 
                      size_t data_size);

#endif