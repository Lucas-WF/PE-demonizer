#include <stdbool.h>

char* filename;
bool shouldParse = false;
bool shouldOverwriteDOS = false;
bool shouldOverwriteCOFF = false;

void handle_flags(int argc, char** argv) {
    if(argc < 2) {
        puts("PE-Demonizer v0.0.1\nTry running 'pe-demonizer -h' for help");
        return;
    }

    for(int i=1; i<argc; i++) {
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            puts("PE-Demonizer v0.0.1\nUsage: pe-demonizer -f [File] [Options]\nOPTIONS:\n  -f, --file: Specifies the file that will be operated\n  -d, --dos-header: Overwrite the DOS-Header with DEMONIZE hexa repr\n  -c, --coff-header: Overwrite the COFF-Header with DEMONIZE hexa repr\n  -p, --parse: Parse the PE headers");
            return;
        }

        if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if(i < argc - 1) {
                filename = argv[++i];
                continue;
            } else {
                printf("pe-demonizer: missing file argument after '%s'\nTry running 'pe-demonizer -h' for help", argv[i]);
                return;
            }
        }

        if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dos-header") == 0) {
            shouldOverwriteDOS = true;
            continue;
        }

        if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--coff-header") == 0) {
            shouldOverwriteCOFF = true;
            continue;
        }

        if(strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--parse") == 0) {
            shouldParse = true;
            continue;
        }

        printf("pe-demonizer: unrecognized option '%s'\nTry running 'pe-demonizer -h' for help", argv[i]);
        exit(1);
    }
}