#include " bmp8.h"

t_bmp8 * bmp8_loadImage(const char * filename) {
    FILE * file = fopen(filename, "rb");
    if (!file) {
        printf("Error when opening the file");
    }
 }


void bmp8_saveImage(const char * filename, t_bmp8 * img) {

}
void bmp8_free(t_bmp8 * img) {

}

void bmp8_printInfo(t_bmp8 * img) {

}