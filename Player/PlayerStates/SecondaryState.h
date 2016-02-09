/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SecondaryState.h
 * Author: sam
 *
 * Created on 3 February 2016, 4:11 PM
 */

#ifndef SECONDARYSTATE_H
#define SECONDARYSTATE_H

#include "../../Graphics/Graphic.h"
#include "../../InputComponent.h"

class SecondaryState{
public:
    
    SecondaryState();
    SecondaryState(const SecondaryState& orig);
    virtual ~SecondaryState();
    
    virtual void init();
    
    void setStateComponent();
    
    virtual void enter();
    virtual void exit();
    virtual void handleInputs(InputComponent* ic);
    
    virtual void update(double timeDelta);
    
    Graphic* graphic;
    Graphic* enterGraphic;
    Graphic* exitGraphic;
    ;
    
private:
    void changeState(SecondaryState* sc);
    
protected:
    
};

#endif /* SECONDARYSTATE_H */

