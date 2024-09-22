/* 

This program will read the bmp image file, assuming we are on a little-endian 
system to make things easier.

The code to check endian:
int num = 0x12345678;
char* pc = (char*) &num;
for (int i = 0; i < 4; i++) {
    printf("%p: %02x \n", pc, (unsigned char) *pc++);
}
*/

#if 0
#include <stdio.h>
#include <stdint.h>

#define BMP_FILE_ID 0x4D42

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

void print_bytes_as_hex(const void *ptr, size_t size);
uint16_t read_bmp_uint16(FILE *bmp_fp);
uint32_t read_bmp_uint32(FILE *bmp_fp);
int32_t read_bmp_int32(FILE *bmp_fp);

int main(int argc, char *argv[])
{
    BMP_HEADER bmp_header;
    DIB_HEADER dib_header;

    FILE *img_fp = fopen(argv[1], "rb"); //just a quick test
    if (img_fp == NULL) 
    {
        perror("Error opening file");
        return (1);
    }

    bmp_header.id = read_bmp_uint16(img_fp);
    if (bmp_header.id != BMP_FILE_ID)
    {
        fprintf(stderr, "Not a BMP file.\n");
        fclose(img_fp);
        return (1);
    }
    
    bmp_header.file_size = read_bmp_uint32(img_fp);
    bmp_header.reserved1 = read_bmp_uint16(img_fp);
    bmp_header.reserved2 = read_bmp_uint16(img_fp);
    bmp_header.pixel_array_offset = read_bmp_uint32(img_fp);

    dib_header.header_size = read_bmp_uint32(img_fp);
    dib_header.bitmap_width = read_bmp_uint32(img_fp);
    dib_header.bitmap_height = read_bmp_uint32(img_fp);
    dib_header.color_plane_num = read_bmp_uint16(img_fp);
    dib_header.bits_per_pixel = read_bmp_uint16(img_fp);

    printf("bmp_width: %d\n", dib_header.bitmap_width);
    printf("bmp height: %d\n", dib_header.bitmap_height);
    
    fclose(img_fp);

    return (0);
}


void print_bytes_as_hex(const void *ptr, size_t size)
{
    const uint8_t *byte_ptr = (const uint8_t *)ptr;
    for (size_t count = 0; count < size; count++)
    {
        printf("%02x ", byte_ptr[count]);
    }
}

uint16_t read_bmp_uint16(FILE *bmp_fp)
{
    uint16_t value;
    fread(&value, sizeof(uint16_t), 1, bmp_fp);

    // Print the raw bytes in hexadecimal format
    printf("Read 16-bit value (hex): ");
    print_bytes_as_hex(&value, sizeof(uint16_t));
    printf(", Value: %d\n", value);

    return (value);
}

uint32_t read_bmp_uint32(FILE *bmp_fp)
{
    uint32_t value;
    fread(&value, sizeof(uint32_t), 1, bmp_fp);

    // Print the raw bytes in hexadecimal format
    printf("Read 32-bit value (hex): ");
    print_bytes_as_hex(&value, sizeof(uint32_t));
    printf(", Value: %d\n", value);

    return (value);
}

int32_t read_bmp_int32(FILE *bmp_fp)
{
    int32_t value;
    fread(&value, sizeof(int32_t), 1, bmp_fp);

    // Print the raw bytes in hexadecimal format
    printf("Read 32-bit value (hex): ");
    print_bytes_as_hex(&value, sizeof(int32_t));
    printf(", Value: %d\n", value);

    return (value);
}
#endif

//------------------------------------------------------------------------------
//  Improved version
//------------------------------------------------------------------------------



