#ifndef VIEW_H
#define VIEW_H

#include "mbed.h"
#include "rtos.h"
#include "MMA7660.h"

#include <sstream>
#include <cmath>

#include "InterruptJoyStick.h"
#include "Accelerometer.h"
#include "Model.h"

using namespace std;


class View{
private:
    static const string SCREEN_CLEAR_STR;
    static const double WIDTH;
    static const double HEIGHT;
    static const double ALPHA;
    static const double ACC_THRESHOLD;

    InterruptJoyStick *joyStick;
    Serial *pc;
    RtosTimer *drawTimer;
    
    DigitalOut *led;
    MMA7660 *mma;
    Accelerometer *accMeter;
    RtosTimer *accReadTimer;
    
    EventQueue queue;
    
    vector<DigitalOut *> leds;
    Model *model;
    RtosTimer *blinkTimer;
    
    int commIntervalMs;
    int accIntervalMs;
    int blinkIntervalMs;
    double ax;
    double ay;
    double az;
    
    void drawScreen(){
        stringstream ss;
        ss << SCREEN_CLEAR_STR.c_str();
        
        ss << "ax:" << ax << "\r\n";
        ss << "ay:" << ay << "\r\n";
        ss << "az:" << az << "\r\n";
        ss << "x :" << accMeter->getX() << "\r\n";
        ss << "y :" << accMeter->getY() << "\r\n";
        ss << "s :" << model->getState() << "\r\n";
        string stateStr = "          ";
        stateStr[model->getState()] = '*';
        ss << stateStr << "\r\n";
        
        pc->printf(ss.str().c_str());
    };
    
    void readAcc(){
        ax = mma->x();
        ay = mma->y();
        az = mma->z();
        accMeter->setAx(ax);
        accMeter->setAy(ay);
        accMeter->updateState();
        model->updateState();
    }
    
    void updateBusout(){
        /*
        string matrix[] = {
            "*         ",
            " *        ",
            "  *       ",
            "   *      ",
            "    *     ",
            "     *    ",
            "      *   ",
            "       *  ",
            "        * ",
            "         *",
        };
        */
        /*
        string matrix[] = {
            "    *    ",
            "    *    ",
            "   * *   ",
            "   * *   ",
            "  *   *  ",
            "  *   *  ",
            " ******* ",
            " *     * ",
            "*       *",
            "*       *",
        };
        */
        
        /*
        string matrix[] = {
            "*****     ",
            "*    *    ",
            "*    *    ",
            "*   *     ",
            "*****     ",
            "*   *     ",
            "*   *     ",
            "*    *    ",
            "*    *    ",
            "*     *   ",
        };
        */
        
        string matrix[] = {
            "         *               *    ",
            "         *               *    ",
            "         *               *    ",
            "         *      ***      *    ",
            " *****   ***   *   *   ***    ",
            "*  *  *  *  *  *****  *  *    ",
            "*  *  *  *  *  *      *  *    ",
            "*  *  *  ***    ***    ** *   ",
            "                              ",
            "***************************   ",
        };
        
        int newStateIdx = model->getState();
        for(int i=0;i<leds.size();i++){
            *leds[i] = (matrix[i][newStateIdx] != ' ') ? 1 : 0;
        }
    }
    
    void onCenterPushed(){
        accMeter->resetLocation();
        *led = !*led; 
    };
    
public:
    View(InterruptJoyStick *joyStick, Serial *pc, MMA7660 *mma, vector<DigitalOut *> leds, DigitalOut *led, int commIntervalMs, int accIntervalMs, int blinkIntervalMs);
    void setup();
};


#endif //VIEW_H