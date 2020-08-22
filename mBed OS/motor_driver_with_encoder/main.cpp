#include "mbed.h"
 
PwmOut EN(D9);
DigitalOut DO1(D10);
DigitalOut DO2(D11);
 
Serial pc(USBTX, USBRX);
 
long float delta_time = 0;
float rpm = 0;
float inc_enc_constant = 0.03125;    // 32 Encoder Ticks per Revolution
 
 
Timer t;
// t.read_us() is 32bit interger, max 2^31 - 1 = 2147483647 us = 2147.483647 s = 35.7913941167 min
 
class Counter
{
public:
 
 
    Counter(PinName pin) : _interrupt(pin) {        // create the InterruptIn on the pin specified to Counter
        _interrupt.fall(this, &Counter::increment); // attach increment function of this counter instance
    }
 
 
    void increment() {
        delta_time = t.read_us();
        t.reset();
 
        rpm = ( inc_enc_constant  / (delta_time/1000000) ) *60 ; // rev / m
 
        _count++;
    }
 
    int read() {
        return _count;
    }
 
private:
    InterruptIn _interrupt;
    volatile int _count;
};
 
 
 
 
 
Counter counter(p30);   // opto interrupter counter
 
int main()
{
    pc.baud(115200);
    EN.period(0.020);
 
    t.start();
 
    float duty = 0.10;
 
    while(1) {
 
        wait(1);
 
        EN.write(duty);
        duty = duty + 0.01; // increment H-Bridge EN PWM duty cycle 1%
        DO1 = 1;         // set H-Bridge input A1 high
        DO2 = 0;         // set H-Bridge input A2 low
 
        // pc.printf("Count so far: %d\n", counter.read());
        // pc.printf("dt: %d\n", delta_time);
 
        pc.printf("RPM: %f\n", rpm);
        pc.printf("DUTY CYCLE: %f\n",duty);
 
    }
}
 