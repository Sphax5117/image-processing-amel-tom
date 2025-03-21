#include " bmp8.h"

int bmp8_loadImage(const char * filename) {
    FILE * file = fopen(filename, "rb");
    if (!file) {
        printf( "Error: Unable to open file \n");
    } else {
        printf("File opened sucessfully");
}
        return 0;
    }
    
void bmp8_saveImage(const char * filename, t_bmp8 * img) {
if (!filename || !img || !img->data) {
    fprintf(stderr, "Error: Invalid parameters for bmp8_saveImage.\n");
    return;
}

FILE *file = fopen(filename, "wb");
if (!file) {
    fprintf(stderr, "Error: Could not open file for writing.\n");
    return;
}

if (fwrite(img->header, sizeof(unsigned char), 54, file) != 54) {
    fprintf(stderr, "Error: Failed to write BMP header.\n");
    fclose(file);
    return;
}

if (fwrite(img->colorTable, sizeof(unsigned char), 1024, file) != 1024) {
    fprintf(stderr, "Error: Failed to write color table.\n");
    fclose(file);
    return;
}

if (fwrite(img->data, sizeof(unsigned char), img->dataSize, file) != img->dataSize) {
    fprintf(stderr, "Error: Failed to write image data.\n");
    fclose(file);
    return;
}

fclose(file);

}

    
void bmp8_free(t_bmp8 * img) {

}

void bmp8_printInfo(t_bmp8 * img) {
    
}