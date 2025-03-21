#include " bmp8.h"

int bmp8_loadImage(const char * filename) {
    FILE * file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    } else {
        printf("File opened sucessfully");
    }
    return 0;
 }


void bmp8_saveImage(const char * filename, t_bmp8 * img) {

}
void bmp8_free(t_bmp8 * img) {

}

void bmp8_printInfo(t_bmp8 * img) {

}