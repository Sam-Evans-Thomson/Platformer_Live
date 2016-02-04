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

class Player;
class StateComponent;

class RunningState : public PrimaryState {
public:
    RunningState(StateComponent* sc);
    
    ~RunningState();
    
    void init() override;
    
    void enter() override;
    void exit() override;
    void handleInputs(InputComponent* ic) override;
    void update(double timeDelta) override;
    void loadGraphics();

private:
    
};

#endif /* RUNNINGSTATE_H */

