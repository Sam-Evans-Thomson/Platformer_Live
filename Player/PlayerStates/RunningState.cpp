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

RunningState::RunningState(StateComponent* sc) : PrimaryState(sc) {
    init();
}

RunningState::~RunningState() {
    graphic = nullptr;
    enterGraphic = nullptr;
    exitGraphic = nullptr;
    stateComp = nullptr;
}

void RunningState::init() {
    graphic = nullptr;
    enterGraphic = nullptr;
    exitGraphic = nullptr;
    loadGraphics();
}

void RunningState::loadGraphics() {

}

void RunningState::enter() {

}

void RunningState::exit() {

}

void RunningState::handleInputs(InputComponent* ic) {
    // Movement Running
    if (ic->L > 0)                      stateComp->p->run(-1);
    else if (ic->R > 0)                 stateComp->p->run(1);
    
    if (ic->A == 1)                     stateComp->p->jump();
    else if (ic->D > 0 && ic->A > 0)    stateComp->p->dropThrough();    
    else if (ic->U   == 1)              stateComp->p->climb();
    else if (ic->B == 1)                stateComp->p->dodge();    
    else if (ic->Y   == 1)              stateComp->p->activate();
    
    // changing items or attacking/dodging/consuming
    if (ic->Sel > 0 ) {
        if(ic->RB > 0 || ic->rTr > 0 )  stateComp->p->changeMelee();
        if(ic->LB > 0 || ic->lTr > 0 )  stateComp->p->changeRange();
        if(ic->X > 0 )                  stateComp->p->changeConsumable();
    } else {
        if (ic->RB  == 1)               stateComp->p->melee1();
        else if (ic->rTr == 1)          stateComp->p->melee2();
        else if (ic->lTr == 1)          stateComp->p->range();
        else if (ic->LB  == 1)          stateComp->p->block();
        if (ic->X   == 1)               stateComp->p->useItem();
    }
}

void RunningState::update(double timeDelta) {

}







