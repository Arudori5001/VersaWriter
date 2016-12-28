#ifndef INTERRUPT_JOY_STICK_H
#define INTERRUPT_JOY_STICK_H

#include "mbed.h"
#include "rtos.h"

#include <vector>

class InterruptJoyStick{
public:
    InterruptJoyStick(PinName down, PinName left, PinName up, PinName right, PinName center);
    InterruptIn* getDownPin();
    InterruptIn* getLeftPin();
    InterruptIn* getUpPin();
    InterruptIn* getRightPin();
    InterruptIn* getCenterPin();
    
private:
    InterruptIn* downPin;
    InterruptIn* leftPin;
    InterruptIn* upPin;
    InterruptIn* rightPin;
    InterruptIn* centerPin;
};

#endif //INTERRUPT_JOY_STICK_H