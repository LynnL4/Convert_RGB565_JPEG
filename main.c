#include <stdio.h>
#include "jpeglib.h"
#include "encode.h"
#include "img.h"

uint8_t jpeg[64*1024] = {0};
uint8_t buf[2048]= {0};

JFILE input = {
    .buffer = gImage_rgb565,
    .index = 0
};

JFILE output = {
    .buffer = jpeg,
    .index = 0
};

int main()
{
    printf("hello world\n\r");
    jpeg_encode(&input, &output, 320, 240, 90, buf);


    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            printf("%02x ", jpeg[i*32 + j]);
        }
        printf("\n\r");
    }

    printf("length: %d\n\r", output.index);

    FILE *fp = fopen("lll.jpg","wb");

    for(int i =0; i < output.index; i++)
    {
        putc(jpeg[i], fp);
    }
    fclose(fp);

}