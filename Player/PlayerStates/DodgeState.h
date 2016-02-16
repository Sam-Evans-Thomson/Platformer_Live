/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DodgeState.h
 * Author: sam
 *
 * Created on 16 February 2016, 11:47 AM
 */

#ifndef DODGESTATE_H
#define DODGESTATE_H

#include "PrimaryState.h"


#define DODGE_PATH "Sprites/Running"




class DodgeState : public PrimaryState {
public:
    DodgeState();
    
    ~DodgeState();
    
    void init() override;
    
    void loadGraphics() override;
    
    void resolvePlatformCollisions();
    void resolvePlatformCollision(BasicPlatform* platform);
    
    void enter() override;
    void exit() override;
    void handleInputs(InputComponent* ic) override;
    void update(double timeDelta) override;
    
    PrimaryState* prevState;
    
private:
    Timer* timer;
    
    
    
};

#endif /* DODGESTATE_H */

