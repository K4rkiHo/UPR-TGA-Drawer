#include "tga.c"

void draw_vline(Image* img, int x, int y, int l, Pixel color)
{
    for(int i = 0; i < l; i++)
    {
        image_set_pixel(img, y+i, x, color);
    }
}

void draw_hline(Image* img, int x, int y, int l, Pixel color)
{
    for(int i = 0; i < l; i++)
    {
        image_set_pixel(img, y, x+i, color);
    }
}

void draw_rect(Image* img, int x, int y, int w, int h, Pixel color)
{
    draw_vline(img, x, y, h, color);
    draw_hline(img, x, y, w, color);
    draw_hline(img, x, y+h, w, color);
    draw_vline(img, x+w, y, h, color); 
}

void draw_circle(Image* img, int x, int y, int r, Pixel color)
{
    for(float p = 0.0; p < 2 * M_PI; p += 0.02)
    {
        int x1 = (float)x + (float)r*cos(p);
        int y1 = (float)y + (float)r*sin(p);
        image_set_pixel(img, y1, x1, color);
    }
}

void DDA(Image * tga, int x1, int y1, int x2, int y2, Pixel color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float steps = fmax(abs(dx), abs(dy));
    float xinc = dx/steps;
    float yinc = dy/steps;

    float x = x1;
    float y = y1;

    while (steps >= 0)
    {
        image_set_pixel(tga,round(x),round(y),color);
        x += xinc;
        y += yinc;
        steps--;
    }
}

void draw_triag(Image * tga, int x, int y, int s, Pixel color)
{
    draw_vline(tga, y, x, s, color);
    int middle = s/2;
    if (middle % 2 != 0)
    {
        middle += 1;
    }
    int h = s * sin(60);
    DDA(tga, x, y, x + middle ,y + h * 3 , color);
    DDA(tga, x + s - 1, y, x + middle, y + h * 3, color);
}