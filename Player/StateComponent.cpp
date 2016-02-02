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

StateComponent::StateComponent(Player* p) : p(p) {
    primary = nullptr;
    secondary = nullptr;
}

StateComponent::StateComponent(const StateComponent& orig) {
}

StateComponent::~StateComponent() {
}

void StateComponent::init() { primary = &running; }

SecondaryState::SecondaryState() {

}

SecondaryState::SecondaryState(const SecondaryState& orig) {

}

PrimaryState::PrimaryState() {

}

PrimaryState::PrimaryState(const PrimaryState& orig) {

}

void PrimaryState::setInputComponent(InputComponent* ic) { inputComp = ic; }

void SecondaryState::setInputComponent(InputComponent* ic) { inputComp = ic; }

void PrimaryState::setStateComponent(StateComponent* sc) { stateComp = sc; }

void SecondaryState::setStateComponent(StateComponent* sc) { stateComp = sc; }


ActivateState::ActivateState() {

}

BlockState::BlockState() {

}

ClimbingState::ClimbingState() {
    
}

DodgeState::DodgeState() {

}

DropAttackState::DropAttackState() {

}

EatingState::EatingState() {

}

GrabbingState::GrabbingState() {

}

JumpingState::JumpingState() {

}

void RunningState::inputs() {
         if (inputComp->A == 1 )    { stateComp->jump();  }
    else if (inputComp->B == 1)     { stateComp->dodge(); }
    else if (inputComp->X == 1)     { stateComp->useItem(); }
    else if (inputComp->Y == 1)     { stateComp->activate(); }
    else if (inputComp->LB == 1)    { stateComp->block(); }
    else if (inputComp->RB == 1)    { stateComp->melee1(); }
}


Melee1State::Melee1State() {

}

Melee2State::Melee2State() {

}

NullState::NullState() {

}

RangeState::RangeState() {

}

RunningState::RunningState() {
    
}

RunningState::RunningState(const RunningState& orig) {

}

StunState::StunState() {

}

void StateComponent::update(double timeDelta) {

}

void ActivateState::update(double timeDelta) {
    
}

void SecondaryState::update(double timeDelta) {

}

void BlockState::update(double timeDelta) {

}

void Melee1State::update(double timeDelta) {

}

void PrimaryState::update(double timeDelta) {

}

void NullState::update(double timeDelta) {

}

void ClimbingState::update(double timeDelta) {

}

void StunState::update(double timeDelta) {

}

void DodgeState::update(double timeDelta) {

    
}

void RangeState::update(double timeDelta) {

}

void DropAttackState::update(double timeDelta) {

}

void EatingState::update(double timeDelta) {

}

void Melee2State::update(double timeDelta) {

}

void RunningState::update(double timeDelta) {

}

void GrabbingState::update(double timeDelta) {

}

void JumpingState::update(double timeDelta) {

}

PrimaryState::~PrimaryState() {

}

RunningState::~RunningState() {

}

SecondaryState::~SecondaryState() {

}

