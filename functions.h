
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include <math.h>


uint32_t to_pio(int IRE, float time_us){

    uint32_t level = roundf((IRE*31)/140);

    uint32_t time = roundf(((time_us * 1000) - 40)/8);

    return ((time << 5) | level);
    
}

void scanline(PIO pio, uint sm){
    pio_sm_put_blocking(pio, sm, to_pio(40, 1.5));
    pio_sm_put_blocking(pio, sm, to_pio(0, 4.7));
    pio_sm_put_blocking(pio, sm, to_pio(40, 4.7));
    pio_sm_put_blocking(pio, sm, to_pio(140, 4.7));

}


