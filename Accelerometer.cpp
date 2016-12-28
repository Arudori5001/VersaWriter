#include "Accelerometer.h"

Accelerometer::Accelerometer(double width, double height, double alpha, double timeSpan, double threshold){
    this->width = width;
    this->height = height;
    this->alpha = alpha;
    this->timeSpan = timeSpan;
    this->threshold = threshold;
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    axMes = 0;
    ayMes = 0;
}
    
void Accelerometer::resetLocation(){
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
}

void Accelerometer::updateState(){
    vx += ax * timeSpan;
    vy += ay * timeSpan;
    x += vx * timeSpan;
    y += vy * timeSpan;
    
    if(abs(x) > width){
        x = min(width, max(-width, x));
        vx = 0;    
    }
    
    if(abs(y) > height){
        y = min(height, max(-height, y));
        vy = 0;    
    } 
}

void Accelerometer::setAx(double value){
    if(threshold < abs(value)){
        axMes = value;
    }else{
        axMes = 0;
    }
    ax = alpha * ax + (1 - alpha) * axMes;
}

void Accelerometer::setAy(double value){
    if(threshold < abs(value)){
        ayMes = value;
    }else{
        ayMes = 0;
    }
    ay = alpha * ay + (1 - alpha) * ayMes;
}

double Accelerometer::getX(){
    return x;    
}

double Accelerometer::getY(){
    return y;    
}


double Accelerometer::getVx(){
    return vx;    
}

double Accelerometer::getVy(){
    return vy;    
}