#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "output.pio.h"
#include "functions.h"

int main(){

    PIO pio = pio0;

    uint offset = pio_add_program(pio, &write_program);

    uint sm = pio_claim_unused_sm(pio, true);
    write_program_init(pio, sm, offset);

    while (true) {
        scanline(pio, sm);
    }
}

