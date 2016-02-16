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
#include "../../Level/LevelObjects/BasicPlatform.h"

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
    graphic = resourceManager.running;
}


void RunningState::enter() {
    graphic->setDirection(player.direction == FACING_R);
}

void RunningState::exit() {

}

void RunningState::handleInputs(InputComponent* ic) {
    graphic->resume();
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
        graphic->pause();
        player.stopRun();
    }
        

    if (ic->A == 1 && ic->D < 1)        player.jumpFirst();
    else if (ic->D > 0 && ic->A == 1)   player.dropThrough();    
    else if (ic->U == 1)                player.climb();
    else if (ic->B == 1)                player.performDodge();    
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
        if (levelManager.getPlayerPlatform(i)->getZ() == player.getZ()) {
            resolvePlatformCollision(levelManager.getPlayerPlatform(i));
        }
    }
    
    if (player.fallFlag == FLAG_FALLING) player.falling();
}

void RunningState::resolvePlatformCollision(BasicPlatform* platform) {
    
    if (!(platform == player.dropPlatform && player.droppingThrough)) {
    
        RectHitbox* feet = player.physicsComp->underFeetHB;
        RectHitbox* plfm = platform->hb;
        RectHitbox* body = player.physicsComp->bodyHB;

        bool feetC = plfm->collision(*feet);
        bool bodyC = plfm->collision(*body);

        if ( feetC ) {  player.fallFlag = FLAG_ONGROUND; }

        if ( bodyC ) {  

            int face = plfm->getCollisionFace(*body, *player.physicsComp->prevPos);

            if ( feetC ) {
                if (face == 3) {
                    player.changePlatform(platform);
                    //std::cout << "hit top" << std::endl;
                }            
            }

            if (!platform->isDropThrough) {
                if (face == 0 || face == 2) {
                    player.hitWall(-1); 
                    //std::cout << "hit side" << std::endl;
                }
            }
        } 
    }
}


void RunningState::update(double timeDelta) {

}







