#include " bmp8.h"
t_bmp8* bmp8_loadImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        fprintf(stderr, "Error: Unable to read BMP header from file %s\n", filename);
        fclose(file);
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    unsigned int width = *(unsigned int*)&header[18];
    unsigned int height = *(unsigned int*)&header[22];
    unsigned short colorDepth = *(unsigned short*)&header[28];
    unsigned int dataSize = *(unsigned int*)&header[34];

    if (colorDepth != 8) {
        fprintf(stderr, "Error: BMP file %s is not an 8-bit grayscale image (color depth = %d)\n", filename, colorDepth);
        fclose(file);
        return NULL;
    }

    t_bmp8* image = (t_bmp8*)malloc(sizeof(t_bmp8));
    if (!image) {
        fprintf(stderr, "Error: Memory allocation failed for BMP structure\n");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->colorDepth = colorDepth;
    image->dataSize = dataSize;

    image->data = (unsigned char*)malloc(dataSize);
    if (!image->data) {
        fprintf(stderr, "Error: Memory allocation failed for BMP data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    unsigned int dataOffset = *(unsigned int*)&header[10];
    fseek(file, dataOffset, SEEK_SET);

    if (fread(image->data, sizeof(unsigned char), dataSize, file) != dataSize) {
        fprintf(stderr, "Error: Unable to read BMP image data from file %s\n", filename);
        free(image->data);
        free(image);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return image;
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