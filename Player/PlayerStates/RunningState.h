/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RunningState.h
 * Author: sam
 *
 * Created on 3 February 2016, 7:57 AM
 */

#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "PrimaryState.h"

class StateComponent;

#define RUNNING_PATH "Sprites/Running"

class RunningState : public PrimaryState {
public:
    RunningState(StateComponent* sc);
    
    ~RunningState();
    
    void init() override;
    
    void loadGraphics() override;
    
    void enter() override;
    void exit() override;
    void handleInputs(InputComponent* ic) override;
    void update(double timeDelta) override;

private:
    
};

#endif /* RUNNINGSTATE_H */

