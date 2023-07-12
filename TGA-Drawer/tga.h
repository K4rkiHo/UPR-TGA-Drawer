#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char uchar;    // 1B
typedef unsigned short ushort;  // 2B

typedef struct {
    uchar id_len;
    uchar color_map_type;
    uchar image_type;
    uchar color_map[5];
    ushort x_origin;
    ushort y_origin;
    ushort width;
    ushort height;
    uchar depth;
    uchar descriptor;
} TGAHeader;

typedef struct {
    uchar blue;
    uchar green;
    uchar red;
    uchar alpha;
} Pixel;

typedef struct {
    TGAHeader* header;
    Pixel* data;
} Image;

//TGA
TGAHeader* tga_header_create(const int w, const int h);
void image_clear(Image * img);
Image* image_new(const int w, const int h);
void image_free(Image * img);
void image_write(const Image * img, char * path);
void image_set_pixel(Image* img, int row, int col, Pixel color);

//Shapes
void draw_triag(Image * tga, int x, int y, int s, Pixel color);
void DDA(Image * tga, int x1, int y1, int x2, int y2, Pixel color);
void draw_circle(Image* img, int x, int y, int r, Pixel color);
void draw_rect(Image* img, int x, int y, int w, int h, Pixel color);
void draw_hline(Image* img, int x, int y, int len, Pixel color);
void draw_vline(Image* img, int x, int y, int len, Pixel color);


