#include "tga.h"

void image_clear(Image* img)
{
    int size = img->header->width * img->header->height;
    Pixel c = { 0, 0, 0, 255 };
    for(int i = 0; i < size; i++)
    {
        img->data[i] = c;
    }
    return;
}

void image_free(Image* img)
{
    if(img)
    {
        free(img->header);
        free(img->data);
        free(img);
    }
    return;
}

void image_write(const Image* img, char* path)
{
    FILE* f = fopen(path, "wb");
    int count = img->header->width * img->header->height;
    fwrite(img->header, sizeof(TGAHeader), 1, f);
    fwrite(img->data, sizeof(Pixel), count, f);
    fclose(f);
    return;
}

void image_set_pixel(Image* img, int row, int col, Pixel color)
{
    if ((row > 0 && row < img->header->width) && (col > 0 && col < img->header->height))
    {
        int position = col * img->header->width + row;
        img->data[position] = color;
    }
}

TGAHeader* tga_header_create(const int w, const int h)
{
    TGAHeader* header = (TGAHeader*) malloc(sizeof(TGAHeader));
    memset( header, 0, sizeof( TGAHeader ) );

    header->image_type = 2;
    header->width = (ushort) w;
    header->height = (ushort) h;
    header->depth = 32;
    header->descriptor = 1 << 5;

    return header;
}

Image* image_new(const int w, const int h)
{
    Image* img = (Image*) malloc(sizeof(Image));
    img->header = tga_header_create(w, h);
    img->data = (Pixel*) malloc(sizeof(Pixel) * w * h);

    image_clear(img);
    return img;
}

