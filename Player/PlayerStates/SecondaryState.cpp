/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SecondaryState.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 4:11 PM
 */

#include "SecondaryState.h"

SecondaryState::SecondaryState(StateComponent* sc) : stateComp(sc) {

}

SecondaryState::SecondaryState(const SecondaryState& orig) { }

SecondaryState::~SecondaryState() {

}

void SecondaryState::setStateComponent(StateComponent* sc) { stateComp = sc;
}

void SecondaryState::init() {

}


void SecondaryState::enter() {

}

void SecondaryState::exit() {

}

void SecondaryState::handleInputs(InputComponent* ic) {

}

void SecondaryState::update(double timeDelta) {

}

void SecondaryState::changeState(SecondaryState* sc) {

}
