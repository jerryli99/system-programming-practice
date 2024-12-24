#include "lsb_steganography.h"

/*
So in my opinion, lsb is a strawman's solution to hide information.
It is just too simple, so anyone can just try to crack it.

OK, what if you randomly distribute the bits to different locations with some 
clever tricks? I mean, sure, but it could add some speckels in the image, raising
suspicion anyways. 

So what now?

Maybe we can hide the bits in regions that not like their neighboring pixels.

What image feature can you think of that have this kind of property?

Edges. I just learned some edge detection math, it was interesting.

So we can use a bunch of jungle animal pictures, such as a Panda staring at you 
with a bamboo in the mouth while hanging out on some random tree that is 100 years
old. 

*/

/**
    @brief Embed data into an image

    @param image BMP_IMAGE pointer
    @param data  a constant uint8_t pointer
    @param output_file a constant char pointer

    @return returns true if embeding is success, and false otherwise.
*/
bool lsb_embed_data(BMP_IMAGE *image, 
                    const uint8_t *data, 
                    size_t data_size, 
                    const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;
    
    // Maximum bytes available for embedding
    size_t pixel_capacity = (width * height * 3) / 8;

    if (data_size > pixel_capacity) 
    {
        fprintf(stderr, "Error: Data size exceeds the embedding " \
                        "capacity of the image.\n");
        return false;
    }

    size_t data_index = 0;
    uint8_t bit_mask = 1; // To extract individual bits

    for (uint32_t y = 0; y < height && data_index < data_size; y++) 
    {
        for (uint32_t x = 0; x < width && data_index < data_size; x++) 
        {
            RGB_PIXEL pixel = get_pixel(image, x, y);

            for (int channel = 0; channel < 3; channel++) 
            {
                uint8_t *color_channel = (channel == 0) ? &pixel.r :
                                         (channel == 1) ? &pixel.g : &pixel.b;

                // Embed a single bit into the LSB of the current channel
                uint8_t current_bit = (data[data_index] & bit_mask) ? 1 : 0;
                *color_channel = (*color_channel & ~1) | current_bit;

                bit_mask <<= 1;
                if (bit_mask == 0) 
                {
                    bit_mask = 1; // Reset bit mask
                    data_index++;
                }
            } //end of RGB channel loop

            set_pixel(image, x, y, pixel);
        }
    }

    save_bmp_image(output_file, image);
    printf("Data embedded successfully into %s\n", output_file);
    return true;
}


//extract data from image
bool lsb_extract_data(const BMP_IMAGE *image, 
                      uint8_t *data, 
                      size_t data_size) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;
    // Maximum bytes available for extraction
    size_t pixel_capacity = (width * height * 3) / 8;

    if (data_size > pixel_capacity) 
    {
        fprintf(stderr, "Error: Data size exceeds the extraction " \
                "capacity of the image.\n");
        return false;
    }

    size_t data_index = 0;
    uint8_t bit_mask = 1;
    data[data_index] = 0;

    for (uint32_t y = 0; y < height && data_index < data_size; y++) 
    {
        for (uint32_t x = 0; x < width && data_index < data_size; x++) 
        {
            RGB_PIXEL pixel = get_pixel(image, x, y);

            uint8_t channels[3] = { pixel.r, pixel.g, pixel.b };
            for (int channel = 0; channel < 3; channel++) 
            {
                // Extract the LSB of the current channel
                uint8_t lsb = channels[channel] & 1;
                if (lsb == 1) 
                {
                    data[data_index] |= bit_mask;
                }

                bit_mask <<= 1;
                if (bit_mask == 0) 
                {
                    bit_mask = 1; // Reset bit mask
                    data_index++;
                    if (data_index < data_size) 
                    {
                        data[data_index] = 0; // Initialize next byte
                    }
                }
            } //end of RGB channel loop
        }
    }

    printf("Data extracted successfully.\n");
    return true;
}
