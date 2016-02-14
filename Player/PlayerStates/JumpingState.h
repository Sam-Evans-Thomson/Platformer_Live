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


#define JUMPING_PATH "Sprites/Running"

class JumpingState : public PrimaryState {
public:
    JumpingState();

    ~JumpingState();
    
    void init() override;
    
    void loadGraphics() override;
    
    void resolvePlatformCollisions() override;
    void resolvePlatformCollision(BasicPlatform* platform) override;
    
    void enter() override;
    void exit() override;
    void handleInputs(InputComponent* ic) override;
    void update(double timeDelta) override;

    
private:

    
};

#endif /* JUMPINGSTATE_H */

