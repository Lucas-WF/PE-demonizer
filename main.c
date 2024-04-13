#include <string.h>
#include <stdlib.h>

#include "demonizer.c"
#include "parser.c"
#include "flags.c"

void parse_headers(char* buffer);

int main(int argc, char** argv) {
    uint8_t* buffer;
    long size;

    handle_flags(argc, argv);

    if(filename == NULL) {
        return 0;
    }

    FILE* fd = fopen(filename, "rb+");

    if(fd == NULL) {
        printf("pe-demonizer: could not find a file that meets with %s\nTry running 'pe-demonizer -h' for help", filename);
        return 0;
    }

    fseek(fd, 0L, SEEK_END);
    size = ftell(fd);
    rewind(fd);

    buffer = (uint8_t*)malloc(size);
    fread(buffer, 1, size, fd);
    rewind(fd);

    if(shouldParse) {
        parse_headers(buffer);
    }

    if(shouldOverwriteDOS) {
        demonize_dos_header(fd);
    }

    if(shouldOverwriteCOFF) {
        demonize_coff_header(fd);
    }

    fclose(fd);
    free(buffer);
    return 0;
}

void parse_headers(char* buffer) {
    parse_dos_header(buffer, &dos_header);
    parse_pe(buffer, PE);
    parse_coff_header(buffer, &coff_header);
}