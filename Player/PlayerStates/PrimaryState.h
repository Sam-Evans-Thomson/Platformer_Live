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

class InputComponent;
class StateComponent;

class PrimaryState {
public:
    PrimaryState(StateComponent* sc);
    PrimaryState(const PrimaryState& orig);
    virtual ~PrimaryState();
    
    virtual void init();
    
    void setStateComponent(StateComponent* sc);
    
    virtual void enter();
    virtual void exit();
    virtual void handleInputs(InputComponent* ic);
    
    virtual void update(double timeDelta);
    
    virtual void loadGraphics();
    
    Graphic* graphic;
    Graphic* enterGraphic;
    Graphic* exitGraphic;
    
    StateComponent* stateComp;
    std::string path;
    
private:
    void changeState(PrimaryState* sc);
    
    
    
protected:
    
};

#endif /* PRIMARYSTATE_H */

