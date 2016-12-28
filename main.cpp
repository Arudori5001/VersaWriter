#include "mbed.h"
#include "MMA7660.h"

#include <vector>

#include "View.h"

using namespace std;

Serial pc(USBTX, USBRX); // tx, rx
InterruptJoyStick joy(p12,p13,p15,p16,p14);
MMA7660 acc(p28,p27);
DigitalOut testLed(LED1);

int main() {
    vector<DigitalOut *> leds;
    leds.push_back(new DigitalOut(p5 ));
    leds.push_back(new DigitalOut(p6 ));
    leds.push_back(new DigitalOut(p7 ));
    leds.push_back(new DigitalOut(p8 ));
    leds.push_back(new DigitalOut(p9 ));
    leds.push_back(new DigitalOut(p10));
    leds.push_back(new DigitalOut(p11));
    leds.push_back(new DigitalOut(p17));
    leds.push_back(new DigitalOut(p18));
    leds.push_back(new DigitalOut(p19));
    
    pc.baud(115200);
    View view(&joy, &pc, &acc, leds, &testLed, 500, 2, 2);
    view.setup();
    while(true) {}
}

