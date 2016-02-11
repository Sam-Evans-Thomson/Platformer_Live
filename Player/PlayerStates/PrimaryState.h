/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrimaryState.h
 * Author: sam
 *
 * Created on 3 February 2016, 4:09 PM
 */

#ifndef PRIMARYSTATE_H
#define PRIMARYSTATE_H

#include "../../Graphics/Graphic.h"
#include <string>
#include "../PhysicsComponent.h"
#include "../Player.h"
#include "../../Level/LevelManager.h"

class InputComponent;
class BasicPlatform;

class PrimaryState {
public:
    PrimaryState();
    PrimaryState(const PrimaryState& orig);
    virtual ~PrimaryState();
    
    virtual void init();
    
    void setStateComponent();
    
    virtual void enter();
    virtual void exit();
    virtual void handleInputs(InputComponent* ic);
    
    virtual void resolvePlatformCollisions();
    virtual void resolvePlatformCollision(BasicPlatform* platform);
    
    virtual void update(double timeDelta);
    
    virtual void loadGraphics();
    
    // HEAP
    Graphic* graphic;
    Graphic* enterGraphic;
    Graphic* exitGraphic;
    
    // STACK
    std::string path;
    
private:
    void changeState(PrimaryState* sc);
    
    
    
protected:
    void clearFlags();
};

#endif /* PRIMARYSTATE_H */

