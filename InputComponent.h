/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputComponent.h
 * Author: sam
 *
 * Created on 1 February 2016, 2:48 PM
 */


#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#define BUTTON_UP false
#define BUTTON_DOWN true

#include <SDL2/SDL_events.h>
#include <SDL.h>
#include <stdio.h>
#include <iostream>



class InputComponent {
public:
    InputComponent();
    InputComponent(const InputComponent& orig);
    virtual ~InputComponent();

    void init();
    bool updateInputs();
    
    
    //  These integers show how many frames the button has been held down
    //  for. If the value is zero the button is released. If it is 1 it has
    //  just been pressed.
    unsigned int A;
    unsigned int B;
    unsigned int X;
    unsigned int Y;
    unsigned int Sel;
    unsigned int Strt;
    unsigned int LB;
    unsigned int RB;
    
    unsigned int LTh;
    unsigned int RTh;
    
    unsigned int U;
    unsigned int D;
    unsigned int L;
    unsigned int R;
    
    double lTh_X;
    double lTh_Y;
    double rTh_X;
    double rTh_Y;
    double rTr;
    double lTr;
    
private:
    SDL_Joystick *joystick;
    
    void axisMotion(SDL_Event &_event);
    
    void dpadPress(SDL_Event &_event);
    
    void incrementAllButtons();
    void inc(unsigned int* button);
    void buttonEvent(SDL_Event &_event, bool state);
    void updateButton(unsigned int* button, bool state);
    
    void testAxis(int axis, double value);
    void testButton(unsigned int button, bool value);
    void testDPad(unsigned int button, Uint8 dir);
    
};

#endif /* INPUTCOMPONENT_H */

