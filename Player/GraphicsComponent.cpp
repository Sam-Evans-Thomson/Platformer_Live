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
#include "Player.h"

extern Player player;

GraphicsComponent::GraphicsComponent() {

}

GraphicsComponent::GraphicsComponent(const GraphicsComponent& orig) {
}

GraphicsComponent::~GraphicsComponent() {
}

void GraphicsComponent::updatePrimaryState(PrimaryState* ps) {
    enterGraphic = ps->enterGraphic;
    graphic      = ps->graphic;
    exitGraphic  = ps->exitGraphic;
    if (enterGraphic == nullptr) playerGraphic = graphic;
    updateGraphics();
}

void GraphicsComponent::updateGraphics() {
    if(playerGraphic == enterGraphic && enterGraphic->hasFinished()) {
        playerGraphic = graphic;
    } 
    else if (playerGraphic == exitGraphic && exitGraphic->hasFinished()) {
        if(enterGraphic != nullptr ) playerGraphic = enterGraphic;
    }
    else if(playerGraphic != graphic) playerGraphic = graphic;
}

void GraphicsComponent::exit() {
    if(exitGraphic != nullptr) playerGraphic = exitGraphic;
    else playerGraphic = graphic;
}

void GraphicsComponent::render(double x, double y, int z, double scale, double rot) {
    playerGraphic->render(x,y,z,scale,rot);
    renderBars();
}

void GraphicsComponent::renderBars() {
    resourceManager.health->renderAsOverlay(
            220 - (1 - player.statsComp->health/player.statsComp->healthMax)*540,
            -210,
            0.5,90);
    resourceManager.stamina->renderAsOverlay(
            1920 - 320 + (1 - player.statsComp->stamina/player.statsComp->staminaMax) * 540,
            -280,
            0.5,-90);
    resourceManager.column->renderAsOverlay(220,-212,0.5,90 );
    resourceManager.column->renderAsOverlay(1920-320,-280,0.5,-90 );
}





