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
#include "../../InputComponent.h"

extern Player player;
extern LevelManager levelManager;

JumpingState::JumpingState() {
    init();
}

JumpingState::~JumpingState() {
    if(graphic != nullptr) delete graphic;
    if(enterGraphic != nullptr) delete enterGraphic;
    if(exitGraphic != nullptr) delete exitGraphic;
}

void JumpingState::init() {
    path = JUMPING_PATH;
    loadGraphics();    
    player.jumpCount = 0;
}

void JumpingState::loadGraphics() {
    graphic = new Graphic(1,path+"/basic");
    graphic->setFrameTime(0.2);
    graphic->loadTextures();
    graphic->start();
}

void JumpingState::handleInputs(InputComponent* ic) {

    if (ic->A > 1) {
        if (player.jumpCount < JUMP_COUNT_MAX) {
            player.jumpCount++;
            player.jump();
        }
    }
    else if (ic->A == 0) {
        player.jumpCount = JUMP_COUNT_MAX + 1;
        player.restrictedMovement = NO_RESTRICTION;
    }
    
    graphic->contAnimation();
    // Movement Running
    if (ic->L > 0&& player.restrictedMovement != FACING_L) {
        player.run(-1);
        player.restrictedMovement = NO_RESTRICTION;
        if(player.direction == FACING_R) {
            graphic->flip();
            player.direction = FACING_L;
        }
    }
    else if (ic->R > 0 && player.restrictedMovement != FACING_R) {
        player.run(1);
        player.restrictedMovement = NO_RESTRICTION;
        if(player.direction == FACING_L) {
            graphic->flip();
            player.direction = FACING_R;
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

void JumpingState::resolvePlatformCollisions() {
    for (int i = 0; i<levelManager.playerPlatformCount(); i++) {
        resolvePlatformCollision(levelManager.getPlayerPlatform(i));
    }
}

void JumpingState::resolvePlatformCollision(BasicPlatform* platform) {
    RectHitbox* feet = player.physicsComp->underFeetHB;
    RectHitbox* platfrm = platform->hb;
    RectHitbox* body = player.physicsComp->bodyHB;
    
    if ( platfrm->collision(*feet) && platfrm->collision(*body) ) { 
        std::cout << "landing " << std::endl;
        player.land(platform); 
    }
    if ( platfrm->collision(*body) )  { 
        int side = platfrm->getCollisionFace(*body,*player.physicsComp->prevPos);
        std::cout << "jumping state  side: " << side << std::endl;   
        if (side == 0) player.hitWall(FACING_R); 
        else if (side == 2) player.hitWall(FACING_L);
        else if (side = 1) player.hitRoof();
    }
}

void JumpingState::enter() {
    graphic->setDirection(player.direction == FACING_R);
}

void JumpingState::exit() {

}

void JumpingState::update(double timeDelta) {

}




