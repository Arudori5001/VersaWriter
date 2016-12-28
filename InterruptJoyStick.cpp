#include "InterruptJoyStick.h"


InterruptJoyStick::InterruptJoyStick(PinName down, PinName left, PinName up, PinName right, PinName center)
{
    this->downPin = new InterruptIn(down);
    this->leftPin = new InterruptIn(left);
    this->upPin = new InterruptIn(up);
    this->rightPin = new InterruptIn(right);
    this->centerPin = new InterruptIn(center);
}

InterruptIn* InterruptJoyStick::getDownPin(){
    return downPin;
}

InterruptIn* InterruptJoyStick::getLeftPin(){
    return leftPin;
}

InterruptIn* InterruptJoyStick::getUpPin(){
    return upPin;
}

InterruptIn* InterruptJoyStick::getRightPin(){
    return rightPin;
}

InterruptIn* InterruptJoyStick::getCenterPin(){
    return centerPin;
}
