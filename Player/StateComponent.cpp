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
#include "PlayerStates/JumpingState.h"

#include "PlayerStates/PrimaryState.h"
#include "PlayerStates/SecondaryState.h"


StateComponent::StateComponent(){
    init();
}

StateComponent::StateComponent(const StateComponent& orig) { }

StateComponent::~StateComponent() { 
    delete running;
    delete jumping;
    secondary = nullptr;
    primary =   nullptr;
}

void StateComponent::update(double timeDelta) {

}


void StateComponent::init() {
    direction = FACING_R;

    running = new RunningState(this);
    jumping = new JumpingState(this);
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

void StateComponent::handleInputs(InputComponent* ic) {
    primary->handleInputs(ic);
}



