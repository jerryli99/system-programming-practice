#include "types.h"

#define BMP_FILE_TYPE 0x4D42

typedef unsigned char bitmap_t;

#pragma pack(push, 1)

typedef struct bmp_header 
{
    uint16 type;
    uint32 file_size;
    uint16 reserved1;
    uint16 reserved2;
    uint32 pixel_array_offset;//the offset to the starting address of bitmap data
} BMP_HEADER;

typedef struct dib_header 
{
    uint32 header_size;
    uint32 bitmap_width; //in pixels
    uint32 bitmap_height; //in pixels
    uint16 color_plane_num; //number of color planes used
    uint16 bits_per_pixel; //color depth of the image, i.e. 1, 4, 8, 16, 24,..
    uint32 compression_method; //i.e. BI_RGB, BI_PNG, BI_BITFIELDS, ...
    uint32 raw_bitmap_size; //image size, padding included
    int32  horizontal_resolution; //pixel per metre, signed integer
    int32  vertical_resolution; //pixel per metre, signed integer
    uint32 palette_color_count; //number of colors in the color palette
    uint32 important_color_used_count; 
} DIB_HEADER;

typedef struct bmp_image
{
    BMP_HEADER bmp_header;
    DIB_HEADER dib_header;
    bitmap_t *image_data;    
} BMP_IMAGE;

#pragma pack(pop)

BMP_IMAGE* read_bmp_image(const char *filename);
void print_bmp_info(const BMP_IMAGE *image);
void extract_rgb(const BMP_IMAGE *image);




#if 0
typedef struct bmp_header 
{
    uint16_t id;
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

typedef struct {
    BMP_HEADER bmp_header;
    DIB_HEADER dib_header;
    unsigned char* img_data; 
} BMPImage;

static BMPImage *read_bmp(FILE *fp, char **error);

static bool check_bmp_header(BMP_HEADER *bmp_hdr, FILE *fp);

static bool write_bmp(FILE *fp, BMPImage *image, char **error);

static void free_bmp(BMPImage *image);

static BMPImage *crop_bmp(BMPImage *image, int x_pos, int y_pos, 
    int width, int height, char **error);

static void print_bmp_info(const BMP_Header *bmp_hdr);
#endif