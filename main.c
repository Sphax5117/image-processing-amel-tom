#include "bmp8.c"

int main () {
    t_bmp8 * img = bmp8_loadImage("lena_gray.bmp");
    bmp8_saveImage("lena_gray.bmp", img);
}
