
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include <math.h>


uint32_t us_to_pio(int IRE, float time_us){

    uint32_t level = roundf((IRE*31)/140);

    uint32_t time = roundf(((time_us * 1000) - 40)/8);

    return ((time << 5) | level);
    
}

uint32_t ns_to_pio(int IRE, int time_ns){

    uint32_t level = roundf((IRE*31)/140);

    uint32_t time = roundf(((time_ns) - 40)/8);

    return ((time << 5) | level);
    
}


void data(){

}

void scanline(PIO pio, uint sm){
    pio_sm_put_blocking(pio, sm, us_to_pio(40, 1.5));
    pio_sm_put_blocking(pio, sm, us_to_pio(0, 4.7));
    pio_sm_put_blocking(pio, sm, us_to_pio(40, 4.7));
    int j = 40;

    for(int i = 0; i < 720; i++){
        if(j > 140){
            j = 40;
        }
        pio_sm_put_blocking(pio, sm, ns_to_pio(j, 73));
        j++;
    }
    //pio_sm_put_blocking(pio, sm, us_to_pio(140, 52.6));

}


