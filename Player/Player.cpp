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

#include "../InputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "PlayerStates/JumpingState.h"
#include "PlayerStates/RunningState.h"
#include "PlayerStates/PrimaryState.h"
#include "PlayerStates/SecondaryState.h"
#include "../Level/LevelObjects/BasicPlatform.h"

extern InputComponent inputComponent;

Player::Player() {

}

Player::Player(const Player& orig) {
}

Player::~Player() {
    delete running;
    delete jumping;
    delete physicsComp;
    delete graphicsComp;
    secondary = nullptr;
    primary =   nullptr;
}

void Player::init() {
    physicsComp = new PhysicsComponent();
    
    direction = FACING_R;

    running = new RunningState();
    jumping = new JumpingState();
    primary = running;
    
    graphicsComp = new GraphicsComponent();
    graphicsComp->updatePrimaryState(primary);
    graphicsComp->updateGraphics(); 
}

void Player::render() { 
    graphicsComp->render(getX(), getY(), getZ(), 1.0,  0.0); 
}

void Player::update(double time) { 
    handleInputs();
    physicsComp->update(time); 
}

void Player::handleInputs() {
    primary->handleInputs(&inputComponent);
}


double Player::getX() { return physicsComp->X(); }

double Player::getY() { return physicsComp->Y(); }

int Player::getZ() { return physicsComp->Z(); }

void Player::changePrimaryState(PrimaryState* primeState) {
    primary->exit();
    
    primary = primeState;
    graphicsComp->updatePrimaryState(primary);
    
    primary->enter();
}

void Player::changeSecondaryState(SecondaryState* secondState) {
    if (secondary != nullptr) secondary->exit();
    secondary = secondState;
    if (secondary != nullptr) secondary->enter();
}

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

void Player::hitWall(int dir) {
    physicsComp->pos->setX(physicsComp->prevPos->getX());
    //physicsComp->force.setX(-2.0*physicsComp->force.getX());
    physicsComp->force.setX(0);
    restrictedMovement = direction;
}

void Player::hitRoof() {

}


void Player::setJumpCount(int i) { jumpCount = i; }

void Player::jumpFirst() {
    changePrimaryState(jumping);
    setJumpCount(0);
    physicsComp->useFric(false);
    physicsComp->useGrav(true);
}

void Player::falling() {
    changePrimaryState(jumping);
    physicsComp->useFric(false);
    physicsComp->useGrav(true);
}


void Player::jump() {
    if (jumpCount < 10) {
        physicsComp->addForce(0.0,-JUMP_FORCE*(10-jumpCount));
    }
}

void Player::land(BasicPlatform* platform) {
    double xDelta = physicsComp->pos->getY() - physicsComp->prevPos->getY();
    if (xDelta > FALL_DELTA_STAGGER) landStagger(xDelta);
    else {
        physicsComp->force = Vec2(physicsComp->force.getX(),0.0);
        physicsComp->applyMoveTo( Vec2(
            physicsComp->pos->getX(), 
            platform->hb->getY() - physicsComp->bodyHB->getH() - 1));
        changePrimaryState(running);
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
