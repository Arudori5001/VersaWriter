#ifndef MODEL_H
#define MODEL_H

#include "mbed.h"

#include <string>
#include <vector>

#include "Accelerometer.h"

using namespace std;

class Model{
private:
    Accelerometer *accMeter;
    int state;
public:
    void updateState();
    int getState();
    Model(Accelerometer *accMeter);   
};


#endif