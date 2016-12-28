#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <algorithm>
#include <cmath>


using namespace std;

class Accelerometer{
private:
    double timeSpan;
    double threshold;
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
    double axMes;
    double ayMes;
    double alpha;
    double width;
    double height;
    
public:
    Accelerometer(double width, double height, double alpha, double timeSpan, double threshold);
    void resetLocation();
    void updateState();
    void setAx(double value);
    void setAy(double value);
    double getX();
    double getY();
    double getVx();
    double getVy();
};

#endif