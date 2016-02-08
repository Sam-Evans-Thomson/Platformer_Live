/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JumpingState.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 12:28 PM
 */

#include "JumpingState.h"
#include "../Player.h"
#include "../StateComponent.h"
#include "../../InputComponent.h"

extern Player player;

JumpingState::JumpingState(StateComponent* sc) : PrimaryState(sc) {
    init();
}

JumpingState::~JumpingState() {
    if(graphic != nullptr) delete graphic;
    if(enterGraphic != nullptr) delete enterGraphic;
    if(exitGraphic != nullptr) delete exitGraphic;
    stateComp = nullptr;
}

void JumpingState::init() {
    path = JUMPING_PATH;
    loadGraphics();    
    jumpCount = 0;
}

void JumpingState::loadGraphics() {
    graphic = new Graphic(1,path+"/basic");
    graphic->setFrameTime(0.2);
    graphic->loadTextures();
    graphic->start();
}

void JumpingState::handleInputs(InputComponent* ic) {

    if (ic->A > 1) {
        if (jumpCount < JUMP_COUNT_MAX) {
            jumpCount++;
            player.jump(jumpCount);
        }
    }
    else if (ic->A == 0) jumpCount = JUMP_COUNT_MAX + 1;
    
    graphic->contAnimation();
    // Movement Running
    if (ic->L > 0) {
        player.run(-1);
        if(stateComp->direction == FACING_R) {
            graphic->flip();
            stateComp->direction = FACING_L;
        }
    }
    else if (ic->R > 0) {
        player.run(1);
        if(stateComp->direction == FACING_L) {
            graphic->flip();
            stateComp->direction = FACING_R;
        }
    }
        
    
    if (ic->A == 1)                     player.flap();
    
//    else if (ic->D > 0 && ic->A > 0)    player.dropThrough();    
//    else if (ic->U == 1)                player.climb();
//    else if (ic->B == 1)                player.dodge();    
//    else if (ic->Y == 1)                player.activate();
//
//    // changing items or attacking/dodging/con.ming
//    if (ic->Sel > 0 ) {
//        if(ic->RB > 0 || ic->rTr > 0 )  player.changeMelee();
//        if(ic->LB > 0 || ic->lTr > 0 )  player.changeRange();
//        if(ic->X > 0 )                  player.changeConsumable();
//    } else {
//        if (ic->RB  == 1)               player.melee1();
//        else if (ic->rTr == 1)          player.melee2();
//        else if (ic->lTr == 1)          player.range();
//        else if (ic->LB  == 1)          player.block();
//        if (ic->X   == 1)               player.useItem();
//    }
    
}

void JumpingState::enter() {
    jumpCount = 0;
}

void JumpingState::exit() {

}

void JumpingState::update(double timeDelta) {

}




