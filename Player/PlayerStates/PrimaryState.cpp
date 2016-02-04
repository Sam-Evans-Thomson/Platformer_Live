/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrimaryState.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 4:09 PM
 */

#include "PrimaryState.h"

PrimaryState::PrimaryState(StateComponent* sc) : stateComp(sc){ }

PrimaryState::PrimaryState(const PrimaryState& orig) { }

PrimaryState::~PrimaryState() { 
    
}

void PrimaryState::setStateComponent(StateComponent* sc) { stateComp = sc;}

void PrimaryState::changeState(PrimaryState* sc) {

}

void PrimaryState::enter() {

}

void PrimaryState::exit() {

}

void PrimaryState::handleInputs(InputComponent* ic) {

}

void PrimaryState::init() {

}

void PrimaryState::update(double timeDelta) {

}
