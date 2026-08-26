#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void swap_colors(uint8_t *data, int width, int height, int channels)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * channels;
            
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];
            
            int brightness = (r + g + b) / 3;
            
            if (brightness < 32)
            {
                data[index] = 128;
                data[index + 1] = 0;
                data[index + 2] = 255;
            }
            else if (brightness < 64)
            {
                data[index] = 0;
                data[index + 1] = 0;
                data[index + 2] = 255;
            }
            else if (brightness < 96) 
            {
                data[index] = 0;
                data[index + 1] = 255;
                data[index + 2] = 255;
            }
            else if (brightness < 128)
            {
                data[index] = 0;
                data[index + 1] = 255;
                data[index + 2] = 0;
            }
            else if (brightness < 160)
            {
                data[index] = 255;
                data[index + 1] = 255;
                data[index + 2] = 0;
            }
            else if (brightness < 192)
            {
                data[index] = 255;
                data[index + 1] = 128;
                data[index + 2] = 0;
            }
            else if (brightness < 224)
            {
                data[index] = 255;
                data[index + 1] = 0;
                data[index + 2] = 0;
            }
            else
            {
                data[index] = 255;
                data[index + 1] = 128;
                data[index + 2] = 255;
            }
        }
    }
}

int main(int argc, char **argv)
{   
    int width, height, channels;
    uint8_t *data = stbi_load(argv[1], &width, &height, &channels, 4);

    swap_colors(data, width, height, channels);
    
    stbi_write_png("output.png", width, height, channels, data, width * channels);
    stbi_image_free(data);
    
    return 0;
}
