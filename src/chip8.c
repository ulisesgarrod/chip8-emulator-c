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

void chip8_load_rom(struct CHIP8 *chip8, const char *romname)
{
    FILE *fileptr = fopen(romname, "rb");
    
    if (fileptr == NULL)
    {
        printf("Error reading ROM\n");
        return;
    }

    printf("ROM detected succesfully\n");

    fseek(fileptr, 0, SEEK_END);
    long last_position = ftell(fileptr);
    fseek(fileptr, 0, SEEK_SET);

    if (last_position > 3584) //4096 - 0x200 = 3584, number of bytes available to use
    {
        fclose(fileptr);
        printf("ROM size exceeded");
        return;
    } else if (last_position == 0)
    {
        fclose(fileptr);
        printf("ROM is empty");
        return;
    } else if (last_position < 0)
    {
        fclose(fileptr);
        printf("ROM size detection failed");
        return;
    } else 
    {
        uint8_t buffer[last_position];

        size_t read_count = fread(buffer, 1, last_position, fileptr);
        if (read_count != last_position)
        {
            printf("Read data does not match the file content");
        } else {
            for (int i = 0x200; i < 0x200+last_position; i++)
            {
                chip8->memory[i] = buffer[i-0x200]; //i starts on 0x200
            }
        }
        fclose(fileptr);
    }
}