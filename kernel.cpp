#include "types.h"
#include "gdt.h"
#include "interrupts.h"

void printf(char* str) {
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;
    
    static uint8_t x, y;

    for(int i = 0; str[i] != '\0'; i++) { 
        if(str[i] == '\n') {
            y++;
            x = 0;
        }
        else {
            VideoMemory[80*y + x] = (VideoMemory[80*y + x] & 0xFF00) | str[i];
            x++;
        }

        if(x >= 80) {
            y++;
            x = 0;
        }

        if(y >= 25) {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    (VideoMemory[80*y + x] & 0xFF00) | ' ';
            x = y = 0;
        }
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(const void* multiboot_structure, uint32_t magicnumber) {
    printf("Hello World!\n");
    printf("dfd\n");
    GlobalDescriptorTable gdt;
    InterruptManager interrupts(&gdt);
    interrupts.Active();
    while(1);
}
