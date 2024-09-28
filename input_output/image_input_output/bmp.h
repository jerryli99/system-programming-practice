#include <stdio.h>
#include "types.h"

#define BMP_FILE_TYPE 0x4D42
#define RGB_COLOR_CHANNELS 3
#define MAX_FILE_NAME_LEN 1024
#define FILE_BASE_NAME_LEN 1000

typedef unsigned char bitmap_t;

/*
since my compiler gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0 is inserting 
extra padding, I will need to tell the compiler not to do that. 
Hence the code here.
*/
#pragma pack(push, 1)

typedef struct bmp_header 
{
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixel_array_offset;//the offset to the starting address of bitmap data
} BMP_HEADER;

typedef struct dib_header 
{
    uint32_t header_size;
    uint32_t bitmap_width; //in pixels
    uint32_t bitmap_height; //in pixels
    uint16_t color_plane_num; //number of color planes used
    uint16_t bits_per_pixel; //color depth of the image, i.e. 1, 4, 8, 16, 24,..
    uint32_t compression_method; //i.e. BI_RGB, BI_PNG, BI_BITFIELDS, ...
    uint32_t raw_bitmap_size; //image size, padding included
    int32_t  horizontal_resolution; //pixel per metre, signed integer
    int32_t  vertical_resolution; //pixel per metre, signed integer
    uint32_t palette_color_count; //number of colors in the color palette
    uint32_t important_color_used_count; 
} DIB_HEADER;

typedef struct bmp_image
{
    BMP_HEADER bmp_header;
    DIB_HEADER dib_header;
    bitmap_t *data;
} BMP_IMAGE;

#pragma pack(pop)

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB_PIXEL;


//These functions are not designed well. I will improve them when I have time.
void get_base_filename(const char *full_name, char *base_name, size_t size);
void read_bmp_error(const char *message, FILE *img_fp, BMP_IMAGE *image);
void free_bmp_image(BMP_IMAGE *image);
BMP_IMAGE* read_bmp_image(const char *filename);
void print_bmp_info(const BMP_IMAGE *image);
void save_bmp_image(const char *file_name, BMP_IMAGE *image);
RGB_PIXEL get_pixel(const BMP_IMAGE *image, uint32_t x, uint32_t y);
void set_pixel(BMP_IMAGE *image, uint32_t x, uint32_t y, RGB_PIXEL pixel);
void extract_rgb_layers(BMP_IMAGE *image, const char *file_name);
void binarize_image(BMP_IMAGE *image, uint8_t threshold, const char *output_file);
