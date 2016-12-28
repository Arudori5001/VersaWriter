#include "View.h"

const string View::SCREEN_CLEAR_STR = "\033[2J\033[H";
const double View::WIDTH = 2;
const double View::HEIGHT = 2;
const double View::ALPHA = 0.1;
const double View::ACC_THRESHOLD = 0.00;

View::View(InterruptJoyStick *joyStick, Serial *pc, MMA7660 *mma, vector<DigitalOut *> leds, DigitalOut *led,
        int commIntervalMs, int accIntervalMs, int blinkIntervalMs)
{
    this->joyStick = joyStick;
    
    this->pc = pc;
    this->drawTimer = new RtosTimer(queue.event(this, &View::drawScreen), osTimerPeriodic);
    this->commIntervalMs = commIntervalMs;
    
    this->mma = mma;
    this->accMeter = new Accelerometer(WIDTH, HEIGHT, ALPHA, accIntervalMs / 1000.0, ACC_THRESHOLD);
    this->accReadTimer = new RtosTimer(queue.event(this, &View::readAcc), osTimerPeriodic);
    this->accIntervalMs = accIntervalMs;
    
    this->led = led;
    
    this->leds = leds;
    this->model = new Model(accMeter);
    this->blinkTimer = new RtosTimer(queue.event(this, &View::updateBusout), osTimerPeriodic);
    this->blinkIntervalMs = blinkIntervalMs;
    
    ax = 0;
    ay = 0;
    az = 0;
}

void View::setup(){
    joyStick->getCenterPin()->rise(queue.event(this, &View::onCenterPushed));
    drawTimer->start(commIntervalMs);
    accReadTimer->start(accIntervalMs);
    blinkTimer->start(blinkIntervalMs);
    
    queue.dispatch();
}