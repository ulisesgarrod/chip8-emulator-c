#include <stdint.h>

struct CHIP8 {
    uint8_t memory[4096]; //Memory
    uint8_t V[16]; //Registers
    uint8_t delay_timer, sound_timer; //Timers
    uint8_t pixels[2048]; //Display 64x32 pixels
    uint8_t keypad[16]; //Hexadecimal keypad
    uint8_t SP; //Stack pointer
    uint16_t PC; //Program counter
    uint16_t I; //I register
    uint16_t stack[16]; //Stack
};