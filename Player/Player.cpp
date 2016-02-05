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
extern InputComponent inputComponent;

Player::Player() {

}

Player::Player(const Player& orig) {
}

Player::~Player() {
    delete stateComp;
    delete graphicsComp;
}

void Player::init() {
    setPos(100,100);
    setAngle(0.0);
    stateComp = new StateComponent();
    graphicsComp = new GraphicsComponent();

    
    //climbBox = nullptr;
    //grabBox = nullptr;
    //terrainBox = nullptr;
    // platform = nullptr;
}

void Player::render(Canvas* canvas) {
    graphicsComp->render(canvas, 
            getPos().getX(), 
            getPos().getY(),
            getZ(),
            1.0,
            getAngle());
}



    //_________________________________________________________//
    //////////////////// ACTIONS AND STATE CHANGES ////////////// 

    // PRIMARY

void Player::run(int dir) {

}

void Player::jump() {

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
