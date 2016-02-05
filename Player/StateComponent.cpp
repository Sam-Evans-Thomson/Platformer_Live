/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateComponent.cpp
 * Author: sam
 * 
 * Created on 2 February 2016, 2:20 PM
 */

#include "StateComponent.h"
#include "PlayerStates/RunningState.h"
#include "PlayerStates/PrimaryState.h"
#include "PlayerStates/SecondaryState.h"


StateComponent::StateComponent(){
    init();
}

StateComponent::StateComponent(const StateComponent& orig) { }

StateComponent::~StateComponent() { 
    delete running;
    secondary = nullptr;
    primary =   nullptr;
}

void StateComponent::update(double timeDelta) {

}


void StateComponent::init() {
    primary = nullptr;
    secondary = nullptr;
    running = new RunningState(this);

    // character starts in running state.
    primary = running;
}

void StateComponent::changePrimaryState(PrimaryState* primeState) {
    primary->exit();
    primary = primeState;
    primary->enter();
}

void StateComponent::changeSecondaryState(SecondaryState* secondState) {
    if (secondary != nullptr) secondary->exit();
    secondary = secondState;
    if (secondary != nullptr) secondary->enter();
}



