/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DodgeState.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 11:47 AM
 */

#include "DodgeState.h"
#include "../../InputComponent.h"
#include "../../Level/LevelObjects/BasicPlatform.h"

extern Player player;
extern LevelManager levelManager;

DodgeState::DodgeState() {
    init();
}

DodgeState::~DodgeState() {
    if(graphic != nullptr) delete graphic;
    if(enterGraphic != nullptr) delete enterGraphic;
    if(exitGraphic != nullptr) delete exitGraphic;
    delete timer;
}

void DodgeState::init() {   
    path = DODGE_PATH;
    timer = new Timer();
    loadGraphics();
}

void DodgeState::loadGraphics() {
    graphic = resourceManager.dodge;
}


void DodgeState::enter() {
    graphic->setDirection(player.direction == FACING_R);
    graphic->setFrame(1);
    timer->start();
}

void DodgeState::exit() {

}

void DodgeState::handleInputs(InputComponent* ic) {
    graphic->resume();

    if (timer->getSeconds() > INVIN_START) {
        player.physicsComp->force.setY(0.0);
        player.physicsComp->force.setX(0.0);
        int dir = 1;
        if (player.direction != FACING_R) dir = -1;
        double dodgeSpeed = PLAYER_DODGE_FORCE*dir;
        if (dodgeSpeed*player.runRatio == 0) player.physicsComp->applyMove(Vec2(dodgeSpeed, 0.0), false);
        else player.physicsComp->applyMove(Vec2(dodgeSpeed, dodgeSpeed*player.runRatio), false);
        if (prevState == player.running) player.physicsComp->correctPosY();
    }
}

void DodgeState::resolvePlatformCollisions() {
    if (timer->getSeconds() > DODGE_LENGTH) player.changePrimaryState(prevState);
    
    for (int i = 0; i<levelManager.playerPlatformCount(); i++) {
        if (levelManager.getPlayerPlatform(i)->getZ() == player.getZ()) {
            resolvePlatformCollision(levelManager.getPlayerPlatform(i));
        }
    }
    
}

void DodgeState::resolvePlatformCollision(BasicPlatform* platform) {
    
    if (!(platform == player.dropPlatform && player.droppingThrough)) {
    
        RectHitbox* feet = player.physicsComp->underFeetHB;
        RectHitbox* plfm = platform->hb;
        RectHitbox* body = player.physicsComp->bodyHB;

        bool feetC = plfm->collision(*feet);
        bool bodyC = plfm->collision(*body);

        
        

        if ( bodyC ) {  

            int face = plfm->getCollisionFace(*body, *player.physicsComp->prevPos);
            
        if (timer->getSeconds() < INVIN_START || !platform->isDropThrough) {
            if ( feetC ) {
                if (face == 3) {
                    player.changePlatform(platform);
                    //std::cout << "hit top" << std::endl;
                }            
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


void DodgeState::update(double timeDelta) {

}






