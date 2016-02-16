/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputComponent.cpp
 * Author: sam
 * 
 * Created on 1 February 2016, 2:48 PM
 */

#define AXIS_BUFFER 0.1

#include "InputComponent.h"
#include <iostream>

InputComponent::InputComponent() {
    
}

InputComponent::InputComponent(const InputComponent& orig) {
}

InputComponent::~InputComponent() {
}

void InputComponent::init() {
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    
    A=B=X=Y=U=D=L=R=Sel=Strt=LB=RB=LTh=RTh=lTr=rTr      = 0;
    lTh_X=lTh_Y=rTh_X=rTh_Y=lTrig=rTrig                 = 0.0;
}

bool InputComponent::updateInputs() {
    quit = false;
    incrementAllButtons();
    
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT          : quit = true;
                break;
            case SDL_KEYDOWN       : keyEvent(event);
                break; 
            case SDL_JOYAXISMOTION : axisMotion(event);
                break;
            case SDL_JOYBUTTONDOWN : buttonEvent(event, BUTTON_DOWN);
                break;
            case SDL_JOYBUTTONUP   : buttonEvent(event, BUTTON_UP);
                break;
            case SDL_JOYHATMOTION  : dpadPress(event);
                break;
        }
    }
    
    return quit;
}

void InputComponent::axisMotion(SDL_Event& _event) {
    Sint16 axis = _event.jaxis.axis;
    double value = (double)_event.jaxis.value/(double)32768;
    
    if ( (value < -AXIS_BUFFER ) || ( value > AXIS_BUFFER ) ) {
        
        //testAxis(axis, value);
        
             if( axis == 0 ) lTh_X = value;
        else if( axis == 1 ) lTh_Y = value;
        else if( axis == 3 ) rTh_X = value;
        else if( axis == 4 ) rTh_Y = value;
        else if( axis == 2 ) {
            if (lTr < TR_BFR && value > TR_BFR) lTr   = 1;
            else lTr = 0;
            lTrig = value;
        }
        else if( axis == 5 ) {
            if( rTr < TR_BFR && value > TR_BFR) rTr   = 1;
            else rTr = 0;
            rTrig = value;
        }    
    }
}

void InputComponent::dpadPress(SDL_Event& _event) {
    Uint8 direction = _event.jhat.value;
    
         if (direction == SDL_HAT_LEFT)     { L++;   U = 0; D = 0; R = 0; }
    else if (direction == SDL_HAT_RIGHT)    { L = 0; U = 0; D = 0; R++;   } 
    else if (direction == SDL_HAT_UP)       { L = 0; U++;   D = 0; R = 0; }
    else if (direction == SDL_HAT_DOWN)     { L = 0; U = 0; D++;   R = 0; }
    else if (direction == SDL_HAT_CENTERED) { L = 0; U = 0; D = 0; R = 0; };
}

void InputComponent::incrementAllButtons() {
    inc(&A);   inc(&B);    inc(&X);  inc(&Y); 
    inc(&Sel); inc(&Strt); inc(&LB); inc(&RB);
    inc(&U);   inc(&D);    inc(&L);  inc(&R); 
}

void InputComponent::inc(unsigned int* button) { 
    if (*button > 0) { *button = *button + 1; }   
}

void InputComponent::buttonEvent(SDL_Event& _event, bool state) {
    Uint8 button = _event.jbutton.button;

         if (button == 0)  updateButton(&A,    state);
    else if (button == 1)  updateButton(&B,    state);
    else if (button == 2)  updateButton(&X,    state);
    else if (button == 3)  updateButton(&Y,    state);
    else if (button == 4)  updateButton(&RB,   state);
    else if (button == 5)  updateButton(&LB,   state);
    else if (button == 6)  updateButton(&Sel,  state);
    else if (button == 7)  updateButton(&Strt, state);
    else if (button == 8)  updateButton(&LTh,  state);
    else if (button == 9)  updateButton(&RTh,  state);
}

void InputComponent::updateButton(unsigned int* button, bool state) {
    //testButton(*button, state);
         if(state == BUTTON_DOWN) *button = 1;
    else if(state == BUTTON_UP)   *button = 0;
          
}

void InputComponent::keyEvent(SDL_Event& _event) {
    SDL_Keycode key = _event.key.keysym.sym;
    
    if (key == SDLK_ESCAPE) quit = true;
}


void InputComponent::testAxis(int axis, double value) {
    std::cout << axis << ":  " << value << std::endl;
}

void InputComponent::testButton(unsigned int button, bool value) {
    std::cout << button << ":  " << value << std::endl;
}

void InputComponent::testDPad(unsigned int button, Uint8 dir) {
    std::cout << dir << ":  " << button << std::endl;
    
}

