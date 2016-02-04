/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphicsComponent.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 1:10 PM
 */

#include "GraphicsComponent.h"
#include "../Graphics/Graphic.h"
#include "../Player/PlayerStates/PrimaryState.h"

GraphicsComponent::GraphicsComponent(Player* p) : p(p) {
    playerGraphic = nullptr;
    enterGraphic = nullptr;
    graphic = nullptr;
    exitGraphic = nullptr;
}

GraphicsComponent::GraphicsComponent(const GraphicsComponent& orig) {
}

GraphicsComponent::~GraphicsComponent() {
}

void GraphicsComponent::updatePrimaryState(PrimaryState* ps) {
    enterGraphic = ps->enterGraphic;
    graphic      = ps->graphic;
    exitGraphic  = ps->exitGraphic;
}

void GraphicsComponent::updateGraphics() {
    if(playerGraphic == enterGraphic && enterGraphic->hasFinished()) {
        playerGraphic = graphic;
    } 
    else if (playerGraphic == exitGraphic && exitGraphic->hasFinished()) {
        if(enterGraphic != nullptr ) playerGraphic = enterGraphic;
    }
}

void GraphicsComponent::exit() {
    if(exitGraphic != nullptr) playerGraphic = exitGraphic;
    else playerGraphic = graphic;
}

void GraphicsComponent::render(Canvas* canvas, double x, double y, int z, double scale, double rot) {
    playerGraphic->render(canvas,x,y,z,scale,rot);
}






