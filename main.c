#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "output.pio.h"

//#define fp (92 << 5) | 12
//#define synctip (292 << 5) | 0

uint32_t bp(){
    return ((582 << 5) | 9);
}

uint32_t fp(){
    return ((182 << 5) | 9);
}

uint32_t synctip(){
    return ((582 << 5) | 0);
}

uint32_t video (){
    return ((6570 << 5) | 31);
}

void scanline(PIO pio, uint sm){
    pio_sm_put_blocking(pio, sm, fp());
    pio_sm_put_blocking(pio, sm, synctip());
    pio_sm_put_blocking(pio, sm, bp());
    pio_sm_put_blocking(pio, sm, video());
}

int main(){

    PIO pio = pio0;

    uint offset = pio_add_program(pio, &write_program);

    uint sm = pio_claim_unused_sm(pio, true);
    write_program_init(pio, sm, offset);

    while (true) {
        scanline(pio, sm);
    }
}

