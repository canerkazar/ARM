#include "mbed.h"

AnalogOut my_output(PA_4);

#define PI        (3.141592653589793238462)
#define AMPLITUDE (1.0)    // x * 3.3V
#define PHASE     (PI * 1) // 2*pi is one period
#define RANGE     (0x7FFF)
#define OFFSET    (0x7FFF)


#define BUFFER_SIZE (360)
uint16_t buffer[BUFFER_SIZE];

void calculate_sinewave(void);

int main() {
    printf("Sinewave example\n");
    calculate_sinewave();
    while(1) {      
        // sinewave output
        for (int i = 0; i < BUFFER_SIZE; i++) {
            my_output.write_u16(buffer[i]);
            wait_us(10);
        }
    }
}


void calculate_sinewave(void){
  for (int i = 0; i < BUFFER_SIZE; i++) {
     double rads = (PI * i)/180.0; 
     buffer[i] = (uint16_t)(AMPLITUDE * (RANGE * (cos(rads + PHASE))) + OFFSET);
  }
}
