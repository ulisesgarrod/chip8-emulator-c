#include <stdio.h>
#include "chip8.h"

void main(int argc, char *argv[]) {
    struct CHIP8 chip8;
    chip8_init(&chip8);
    
    if (argc == 1)
    {
        printf("No ROM input");
    } else 
    {
        chip8_load_rom(&chip8, argv[1]);
    }
}