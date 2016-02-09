/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RunningState.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 7:57 AM
 */

#include "RunningState.h"
#include "../../InputComponent.h"

extern Player player;
extern LevelManager levelManager;

RunningState::RunningState() {
    init();
}

RunningState::~RunningState() {
    if(graphic != nullptr) delete graphic;
    if(enterGraphic != nullptr) delete enterGraphic;
    if(exitGraphic != nullptr) delete exitGraphic;
}

void RunningState::init() {   
    path = RUNNING_PATH;
    loadGraphics();
}

void RunningState::loadGraphics() {
    graphic = new Graphic(6,path+"/basic");
    graphic->setFrameTime(0.1);
    graphic->loadTextures();
    graphic->start();
}


void RunningState::enter() {
    graphic->setDirection(player.direction == FACING_R);
}

void RunningState::exit() {

}

void RunningState::handleInputs(InputComponent* ic) {
    graphic->contAnimation();
    // Movement Running
    if (ic->L > 0 && player.restrictedMovement != FACING_L) {
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
    else {
        graphic->setFrame(2);
        graphic->pauseAnimation();
        player.stopRun();
    }
        

    if (ic->A == 1)                     player.jumpFirst();
    else if (ic->D > 0 && ic->A > 0)    player.dropThrough();    
    else if (ic->U == 1)                player.climb();
    else if (ic->B == 1)                player.dodge();    
    else if (ic->Y == 1)                player.activate();

    // changing items or attacking/dodging/con.ming
    if (ic->Sel > 0 ) {
        if(ic->RB > 0 || ic->rTr > 0 )  player.changeMelee();
        if(ic->LB > 0 || ic->lTr > 0 )  player.changeRange();
        if(ic->X > 0 )                  player.changeConsumable();
    } else {
        if (ic->RB  == 1)               player.melee1();
        else if (ic->rTr == 1)          player.melee2();
        else if (ic->lTr == 1)          player.range();
        else if (ic->LB  == 1)          player.block();
        if (ic->X   == 1)               player.useItem();
    }
    
}

void RunningState::resolvePlatformCollisions() {
    clearFlags();
    for (int i = 0; i<levelManager.playerPlatformCount(); i++) {
        resolvePlatformCollision(levelManager.getPlayerPlatform(i));
    }
    
    if (player.fallFlag == FLAG_FALLING) player.falling();
}

void RunningState::resolvePlatformCollision(BasicPlatform* platform) {
    RectHitbox* feet = player.physicsComp->underFeetHB;
    RectHitbox* plfm = platform->hb;
    RectHitbox* body = player.physicsComp->bodyHB;
    
    if ( plfm->collision(*feet) ) {  player.fallFlag = FLAG_ONGROUND; }
    if ( plfm->collision(*body) ) {  player.hitWall(-1); }
}


void RunningState::update(double timeDelta) {

}







