/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: sam
 * 
 * Created on 2 February 2016, 2:19 PM
 */

#include "Player.h"
#include "GraphicsComponent.h"
#include "StateComponent.h"

#include "../InputComponent.h"
#include "../Player/PhysicsComponent.h"

extern InputComponent inputComponent;

Player::Player() {

}

Player::Player(const Player& orig) {
}

Player::~Player() {
    delete stateComp;
    delete graphicsComp;
    delete physicsComp;
}

void Player::init() {
    
    physicsComp = new PhysicsComponent();

    
    // makes new running state which makes graphics succesfully.
    stateComp = new StateComponent(); 
    
    graphicsComp = new GraphicsComponent();
    graphicsComp->updatePrimaryState(stateComp->primary);
    graphicsComp->updateGraphics();

    
    //climbBox = nullptr;
    //grabBox = nullptr;
    //terrainBox = nullptr;
    // platform = nullptr;
}

void Player::render() {
    
    graphicsComp->render(physicsComp->X(), 
            physicsComp->Y(),
            physicsComp->Z(),
            1.0,
            physicsComp->getAngle());
}

void Player::update(double time) {
    stateComp->handleInputs(&inputComponent);
    physicsComp->update(time);
    //graphicsComp->updateGraphics();
}

void Player::changeState(PrimaryState* state) {
    stateComp->changePrimaryState(state);
    graphicsComp->updatePrimaryState(state);
    graphicsComp->updateGraphics();
}


double Player::getX() { return physicsComp->X(); }

double Player::getY() { return physicsComp->Y(); }

int Player::getZ() { return physicsComp->Z(); }



    //_________________________________________________________//
    //////////////////// ACTIONS AND STATE CHANGES ////////////// 

    // PRIMARY

void Player::run(int dir) {
    physicsComp->useFric(false);
    physicsComp->addForce(Vec2(50.0*dir,0.0)); 
}

void Player::stopRun() {
    physicsComp->useFric(true);
}


void Player::jumpFirst() {
    changeState(stateComp->jumping);
    stateComp->setJumpCount(0);
    physicsComp->useFric(false);
    physicsComp->useGrav(true);
}

void Player::falling() {
    changeState(stateComp->jumping);
    physicsComp->useFric(false);
    physicsComp->useGrav(true);
}


void Player::jump(int i) {
    physicsComp->addForce(0.0,-JUMP_FORCE*(10-i));
}

void Player::land(double xDelta) {
    if (xDelta > FALL_DELTA_STAGGER) landStagger(xDelta);
    else {
        changeState(stateComp->running);
        physicsComp->useGrav(false);
    }
    
}

void Player::landStagger(double xDelta) {
    std::cout << "Player staggers: "<< xDelta << std::endl;
}




void Player::dropThrough() {
//    if(platform->isDropThrough) {
//        move(0,-10);
//    }
}

void Player::climb() {

}

void Player::dodge() {

}

void Player::activate() {

}

void Player::melee1() {

}

void Player::melee2() {

}

void Player::range() {

}

void Player::block() {

}

void Player::useItem() {

}

void Player::flap() {

}

void Player::changeMelee() {

}

void Player::changeConsumable() {

}

void Player::changeRange() {

}
