#include "parser.h"

void parse_dos_header(char* buffer, IMAGE_DOS_HEADER* dos_header) {
    memcpy(&dos_header->e_magic, &buffer[0], sizeof(uint16_t));

    printf("Magic: %04X\n", dos_header->e_magic);

    memcpy(&dos_header->e_cblp, &buffer[2], sizeof(uint16_t));

    printf("CBLP: %04X\n", dos_header->e_cblp);

    memcpy(&dos_header->e_cp, &buffer[4], sizeof(uint16_t));

    printf("CP: %04X\n", dos_header->e_cp);

    memcpy(&dos_header->e_crlc, &buffer[6], sizeof(uint16_t));

    printf("CRLC: %04X\n", dos_header->e_crlc);

    memcpy(&dos_header->e_cparhdr, &buffer[8], sizeof(uint16_t));

    printf("CPARHDR: %04X\n", dos_header->e_cparhdr);

    memcpy(&dos_header->e_minalloc, &buffer[10], sizeof(uint16_t));

    printf("MINALLOC: %04X\n", dos_header->e_minalloc);

    memcpy(&dos_header->e_maxalloc, &buffer[12], sizeof(uint16_t));

    printf("MAXALLOC: %04X\n", dos_header->e_maxalloc);

    memcpy(&dos_header->e_ss, &buffer[14], sizeof(uint16_t));

    printf("SS: %04X\n", dos_header->e_ss);

    memcpy(&dos_header->e_sp, &buffer[16], sizeof(uint16_t));

    printf("SP: %04X\n", dos_header->e_sp);

    memcpy(&dos_header->e_csum, &buffer[18], sizeof(uint16_t));

    printf("CSUM: %04X\n", dos_header->e_csum);

    memcpy(&dos_header->e_ip, &buffer[20], sizeof(uint16_t));

    printf("IP: %04X\n", dos_header->e_ip);

    memcpy(&dos_header->e_cs, &buffer[22], sizeof(uint16_t));

    printf("CS: %04X\n", dos_header->e_cs);

    memcpy(&dos_header->e_lfarlc, &buffer[24], sizeof(uint16_t));

    printf("LFARLC: %04X\n", dos_header->e_lfarlc);

    memcpy(&dos_header->e_ovno, &buffer[26], sizeof(uint16_t));

    printf("OVNO: %04X\n", dos_header->e_ovno);

    memcpy(&dos_header->e_res, &buffer[28], sizeof(uint16_t)*4);

    printf("RES: %08X\n", dos_header->e_res);

    memcpy(&dos_header->e_oemid, &buffer[36], sizeof(uint16_t));

    printf("OEMID: %04X\n", dos_header->e_oemid);

    memcpy(&dos_header->e_oeminfo, &buffer[38], sizeof(uint16_t));

    printf("OEMINFO: %04X\n", dos_header->e_oeminfo);

    memcpy(&dos_header->e_res2, &buffer[40], sizeof(uint16_t)*10);

    printf("RES2: %020X\n", dos_header->e_res2);

    memcpy(&dos_header->e_lfanew, &buffer[60], sizeof(uint32_t));

    printf("ELFANEW: %08X\n\n", dos_header->e_lfanew);
}

void parse_pe(char* buffer, uint32_t pe) {
    memcpy(&pe, &buffer[128], sizeof(uint32_t));
    printf("PE: %08X\n\n", pe);
}

void parse_coff_header(char* buffer, IMAGE_COFF_HEADER* coff_header) {
    memcpy(&coff_header->Machine, &buffer[132], sizeof(uint16_t));
    printf("Machine: %04X\n", coff_header->Machine);
    memcpy(&coff_header->NumberOfSections, &buffer[134], sizeof(uint16_t));
    printf("NumberOfSections: %04X\n", coff_header->NumberOfSections);
    memcpy(&coff_header->TimeDateStamp, &buffer[136], sizeof(uint32_t));
    printf("TimeDateStamp: %08X\n", coff_header->TimeDateStamp);
    memcpy(&coff_header->PointerToSymbolTable, &buffer[140], sizeof(uint32_t));
    printf("PointerToSymbolTable: %08X\n", coff_header->PointerToSymbolTable);
    memcpy(&coff_header->NumberOfSymbols, &buffer[144], sizeof(uint32_t));
    printf("NumberOfSymbols: %08X\n", coff_header->NumberOfSymbols);
    memcpy(&coff_header->SizeOfOptionalHeader, &buffer[148], sizeof(uint16_t));
    printf("SizeOfOptionalHeader: %08X\n", coff_header->SizeOfOptionalHeader);
    memcpy(&coff_header->Characteristics, &buffer[150], sizeof(uint16_t));
    printf("Characteristics: %08X\n", coff_header->Characteristics);
}