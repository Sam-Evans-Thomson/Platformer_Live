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

extern Player player;
extern LevelManager levelManager;

PrimaryState::PrimaryState() { }

PrimaryState::PrimaryState(const PrimaryState& orig) { }

PrimaryState::~PrimaryState() { 
    
}

void PrimaryState::setStateComponent() { }

void PrimaryState::changeState(PrimaryState* sc) {

}

void PrimaryState::enter() {

}

void PrimaryState::loadGraphics() {
    
}

void PrimaryState::exit() {

}

void PrimaryState::handleInputs(InputComponent* ic) {

}

void PrimaryState::init() {

}

void PrimaryState::update(double timeDelta) {

}

void PrimaryState::resolvePlatformCollisions() {

}

void PrimaryState::resolvePlatformCollision(BasicPlatform* platform) {

}


void PrimaryState::clearFlags() {
    player.fallFlag = 0;
}

