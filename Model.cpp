#include "Model.h"

Model::Model(Accelerometer *accMeter){
    this->state=0;
    this->accMeter = accMeter;
}

void Model::updateState(){
    int vState;
    int matLength = 30;
    if(accMeter->getVy() >= 0){
        vState = 1;
    }else{
        vState = matLength - 1;
    }
    
    state = (state + vState) % matLength;
}

int Model::getState(){
    return this->state;    
}