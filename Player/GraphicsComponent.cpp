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
            0 ,
            10 + (1 - player.statsComp->health/player.statsComp->healthMax)* 1000,
            1.0,0.0);
    resourceManager.stamina->renderAsOverlay(
            1920 - 60,
            10 + (1 - player.statsComp->stamina/player.statsComp->staminaMax)* 1000,
            1.0,0.0);
    resourceManager.column->renderAsOverlay(0,0,1.0,0.0 );
    resourceManager.column->renderAsOverlay(1920 - 65,0,1.0,0.0 );
}





