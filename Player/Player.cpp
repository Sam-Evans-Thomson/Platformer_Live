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
#include "PlayerStates/DodgeState.h"
#include "PlayerStates/PrimaryState.h"
#include "PlayerStates/SecondaryState.h"
#include "../Level/LevelObjects/BasicPlatform.h"
#include "../Level/LevelObjects/SlopePlatform.h"

extern InputComponent inputComponent;

Player::Player() {

}

Player::Player(const Player& orig) {
}

Player::~Player() {
    delete statsComp;
    delete running;
    delete jumping;
    delete dodge;
    delete physicsComp;
    delete graphicsComp;
    secondary = nullptr;
    primary =   nullptr;
}

void Player::init() {
    statsComp = new StatsComp();
    statsComp->init();
    statsComp->refresh();
    
    physicsComp = new PhysicsComponent();
    
    direction = FACING_R;

    running = new RunningState();
    jumping = new JumpingState();
    dodge   = new DodgeState();
    primary = running;
    
    graphicsComp = new GraphicsComponent();
    graphicsComp->updatePrimaryState(primary);
    graphicsComp->updateGraphics(); 
}

void Player::render() { 
    graphicsComp->render(getX(), getY(), getZ(), 1.0,  0.0); 
}

void Player::update(double time) { 
    physicsComp->prevPos->setX(physicsComp->pos->getX());
    physicsComp->prevPos->setY(physicsComp->pos->getY());
    
    handleInputs();
    physicsComp->update(time); 
    statsComp->update();
}

void Player::handleInputs() {
    primary->handleInputs(&inputComponent);
}


double Player::getX() { return physicsComp->X(); }

double Player::getY() { return physicsComp->Y(); }

double Player::getPrevX() { return physicsComp->prevX(); }

double Player::getPrevY() { return physicsComp->prevY(); }


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

void Player::move(int dir) {
    physicsComp->useFric(false);
    double runSpeed = PLAYER_RUN_SPEED*dir;
    physicsComp->addForce(runSpeed, 0.0);
}


void Player::run(int dir) {
    physicsComp->useFric(false);
    double runSpeed = PLAYER_RUN_SPEED*dir;
    if (runSpeed*runRatio > 0) physicsComp->addForce(runSpeed, 0.0);
    else physicsComp->addForce(runSpeed, runSpeed*runRatio);
}

void Player::stopRun() {
    physicsComp->useFric(true);
}

void Player::hitWall(int dir) {
    //std::cout << "hitwall " << std::endl;
    physicsComp->pos->setX(physicsComp->prevPos->getX());
    physicsComp->force.setX(0);
    restrictedMovement = direction;
}

void Player::hitRoof() {
    //physicsComp->pos->setY(physicsComp->prevPos->getY());
    physicsComp->force.setY(-0.5*physicsComp->force.getY());
}

void Player::setJumpCount(int i) { jumpCount = i; }
void Player::setFlapCount(int i) { flapCount = i; }

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
    physicsComp->addForce(0.0,-JUMP_FORCE*(15-jumpCount));
}


void Player::flap() {
    if (statsComp->stamina > 0) {
        physicsComp->addForce(0.0,-statsComp->flapPower);
        statsComp->useStamina(statsComp->flapPower);
    }
}

void Player::changePlatform(BasicPlatform* platform) {
    if (currPlatform != platform) {
        currPlatform = platform;
        if (platform->hb->isAA)         runRatio = 0.0; 
        else if(!platform->hb->isAA)    runRatio = platform->getRatio(); 
    }
    physicsComp->correctPosY();
}


void Player::land(BasicPlatform* platform) {
    changePlatform(platform);
    droppingThrough = false;
    double xDelta = physicsComp->force.getY();
    if (xDelta > FALL_FORCE_STAGGER) landStagger(xDelta - FALL_FORCE_STAGGER);
    {
        physicsComp->force = Vec2(physicsComp->force.getX(),0.0);

        changePrimaryState(running);
        physicsComp->correctPosY();
        physicsComp->useGrav(false);
    }
}

void Player::landStagger(double xDelta) {
    statsComp->takeDamage(0.5*xDelta);
    if (statsComp->takeStaggerDamage(xDelta/10.0)) {
        //change state to staggered.
    }
}

void Player::dropThrough() {
    //std::cout << "Drop through: " << currPlatform->isDropThrough << std::endl;
    if(currPlatform->isDropThrough) {
        
        dropPlatform = currPlatform;
        droppingThrough = true;
        changePrimaryState(jumping);
        physicsComp->useFric(false);
        physicsComp->useGrav(true);
    }
}

void Player::climb() {

}

void Player::performDodge() {
    if (statsComp->useStamina(DODGE_STAMINA)) {
        dodge->prevState = primary;
        changePrimaryState(dodge);   
    }
    
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

void Player::changeMelee() {

}

void Player::changeConsumable() {

}

void Player::changeRange() {

}

void Player::dies() {

}

