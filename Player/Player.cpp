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
    primary = running;
    
    graphicsComp = new GraphicsComponent();
    graphicsComp->updatePrimaryState(primary);
    graphicsComp->updateGraphics(); 
}

void Player::render() { 
    graphicsComp->render(getX(), getY(), getZ(), 1.0,  0.0); 
}

void Player::update(double time) { 
    std::cout << "player update: " << statsComp->stamina << std::endl;
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

void Player::run(int dir) {
    physicsComp->useFric(false);
    physicsComp->addForce(Vec2(50.0*dir,50.0*dir*tan(runAngle)));
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
    std::cout<< "flap" <<std::endl;
    if (statsComp->stamina > 0) {
        physicsComp->addForce(0.0,-statsComp->flapPower);
        statsComp->useStamina(statsComp->flapPower);
    }
    
}

void Player::land(BasicPlatform* platform) {
    double xDelta = physicsComp->force.getY();
    if (xDelta > FALL_FORCE_STAGGER) landStagger(xDelta - FALL_FORCE_STAGGER);
    {
        physicsComp->force = Vec2(physicsComp->force.getX(),0.0);
        
        if (platform->hb->isAA) { 
            runAngle = 0.0;
            physicsComp->applyMoveTo( 
            Vec2(
                physicsComp->pos->getX(), 
                platform->hb->getY() - physicsComp->bodyHB->getH() - 1));
        } 
        
        else if(!platform->hb->isAA) {
            runAngle = platform->getAngle();
            double moveX = getX();
            double moveY;
            double checkX;
            
            if (platform->getAngle() > 0) checkX = moveX;
            else checkX = moveX + physicsComp->bodyHB->getW();
                
            moveY = platform->getYatX(checkX) - physicsComp->bodyHB->getH() - 1;
            physicsComp->applyMoveTo( Vec2(moveX, moveY) );
        }
        
        changePrimaryState(running);
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

void Player::changeMelee() {

}

void Player::changeConsumable() {

}

void Player::changeRange() {

}

void Player::dies() {

}

