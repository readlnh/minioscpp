#include "port.h"

Port::Port(uint16_t portnumber) {
    this->portnumber = portnumber;
}

Port::~Port() {

}

Port8Bit::Port8Bit(uint16_t portnumber) : Port(portnumber) {

}

Port8Bit::~Port8Bit() {

}

void Port8Bit::Write(uint8_t data) {
    __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
}

uint8_t Port8Bit::Read() {
    uint8_t result; 
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (portnumber));
    return result;
}

Port8BitSlow::Port8BitSlow(uint16_t portnumber) : Port8Bit(portnumber) {

}

Port8BitSlow::~Port8BitSlow() {

}

void Port8BitSlow::Write(uint8_t data) {
   Write8Slow(portnumber, data);
}

