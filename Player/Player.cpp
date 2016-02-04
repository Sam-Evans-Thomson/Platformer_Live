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

Player::Player(InputComponent* ic) : inputComp(ic){
    init();
}

Player::Player(const Player& orig) {
}

Player::~Player() {
    //delete stateComp;
    //delete graphicsComp;
}

void Player::init() {
    //stateComp = new StateComponent(this, inputComp);
    //graphicsComp = new GraphicsComponent(this);

    
    //climbBox = nullptr;
    //grabBox = nullptr;
    //terrainBox = nullptr;
    // platform = nullptr;
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
