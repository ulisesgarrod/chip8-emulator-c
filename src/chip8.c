#include <stdio.h>
#include <string.h>
#include "chip8.h"

void chip8_init(struct CHIP8 *chip8)
{
    memset(chip8->memory, 0, sizeof(chip8->memory)); //Memory
    memset(chip8->V, 0, sizeof(chip8->V)); //Registers
    chip8->delay_timer = 0; //Delay Timer
    chip8->sound_timer = 0; //Sound Timer
    memset(chip8->pixels, 0, sizeof(chip8->pixels)); //Display 64x32 pixels
    memset(chip8->keypad, 0, sizeof(chip8->keypad)); //Hexadecimal keypad
    chip8->SP = 0; //Stack pointer
    chip8->PC = 0x200; //Program Counter
    chip8->I = 0; //I register
    memset(chip8->stack, 0, sizeof(chip8->stack)); //Stack

    //Font initialization (from 0x050 to 0x09F)

    uint8_t font[80] = {
                    0b01110000,0b01010000,0b01010000,0b01010000,0b01110000, //0
                    0b00010000,0b00110000,0b00010000,0b00010000,0b00010000, //1
                    0b01110000,0b00010000,0b01110000,0b01000000,0b01110000, //2
                    0b01110000,0b00010000,0b01110000,0b00010000,0b01110000, //3
                    0b01010000,0b01010000,0b01110000,0b00010000,0b00010000, //4
                    0b01110000,0b01000000,0b01110000,0b00010000,0b01110000, //5
                    0b01110000,0b01000000,0b01110000,0b01010000,0b01110000, //6
                    0b01110000,0b00010000,0b00010000,0b00010000,0b00010000, //7
                    0b01110000,0b01010000,0b01110000,0b01010000,0b01110000, //8
                    0b01110000,0b01010000,0b01110000,0b00010000,0b00010000, //9
                    0b01100000,0b10010000,0b11110000,0b10010000,0b10010000, //A
                    0b11100000,0b10010000,0b11100000,0b10010000,0b11100000, //B
                    0b11100000,0b10000000,0b10000000,0b10000000,0b11100000, //C
                    0b11100000,0b10010000,0b10010000,0b10010000,0b11100000, //D
                    0b11100000,0b10000000,0b11100000,0b10000000,0b11100000, //E
                    0b11100000,0b10000000,0b11000000,0b10000000,0b10000000, //F
                    };

    for(int i=0x50; i<=0x9F; i++)
    {
        chip8->memory[i] = font[i-80];
    }
}