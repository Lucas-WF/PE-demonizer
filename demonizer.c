#include "demonizer.h"

const uint8_t data[] = {0x44, 0x45, 0x4D, 0x4F, 0x4E, 0x49, 0x5A, 0x45};

void demonize_dos_header(FILE* file) {
    for(int offset = 0; offset < 64; offset+=8) {
        fwrite(data, sizeof(uint8_t), sizeof(data), file);
    }

    rewind(file);
}

void demonize_coff_header(FILE* file) {
    int offset = 132;
    fseek(file, 132, SEEK_SET);

    for(offset; offset+8 < 152; offset+=8) {
        fwrite(data, sizeof(uint8_t), sizeof(data), file);
    }

    rewind(file);
}