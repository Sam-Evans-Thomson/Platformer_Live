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
#include "../Player.h"
#include "../StateComponent.h"
#include "../../InputComponent.h"

extern Player player;

RunningState::RunningState(StateComponent* sc) : PrimaryState(sc) {
    init();
}

RunningState::~RunningState() {
    if(graphic != nullptr) delete graphic;
    if(enterGraphic != nullptr) delete enterGraphic;
    if(exitGraphic != nullptr) delete exitGraphic;
    stateComp = nullptr;
}

void RunningState::init() {   
    path = RUNNING_PATH;
    loadGraphics();
}

void RunningState::loadGraphics() {
    graphic = new Graphic(6,path+"/basic");
    graphic->setFrameTime(0.1);
    graphic->loadTextures();
}


void RunningState::enter() {

}

void RunningState::exit() {

}

void RunningState::handleInputs(InputComponent* ic) {
    // Movement Running
    if (ic->L > 0)                      player.run(-1);
    else if (ic->R > 0)                 player.run(1);

    if (ic->A == 1)                     player.jump();
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

void RunningState::update(double timeDelta) {

}







