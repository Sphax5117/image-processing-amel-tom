#include "bmp8.c"

int main () {
    int a = bmp8_loadImage("lena_gray.bmp");
    return a;
}
