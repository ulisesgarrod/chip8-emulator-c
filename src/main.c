#include <stdio.h>
#include "chip8.h"

void main() {
    struct CHIP8 chip8;
    chip8_init(&chip8);
    printf("%d", chip8.PC);
}