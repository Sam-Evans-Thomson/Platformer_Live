/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JumpingState.h
 * Author: sam
 *
 * Created on 6 February 2016, 12:28 PM
 */

#ifndef JUMPINGSTATE_H
#define JUMPINGSTATE_H

#include "PrimaryState.h"

#define JUMP_COUNT_MAX 10

class StateComponent;

#define JUMPING_PATH "Sprites/Running"

class JumpingState : public PrimaryState {
public:
    JumpingState(StateComponent* sc);

    ~JumpingState();
    
    void init() override;
    
    void loadGraphics() override;
    
    void enter() override;
    void exit() override;
    void handleInputs(InputComponent* ic) override;
    void update(double timeDelta) override;
    
private:

    int jumpCount;
    
};

#endif /* JUMPINGSTATE_H */

