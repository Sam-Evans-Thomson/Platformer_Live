/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MeleeAttack.cpp
 * Author: sam
 * 
 * Created on 17 February 2016, 2:29 PM
 */

#include "MeleeAttack.h"
#include "../Graphics/Graphic.h"
#include "../GameObject/Hitboxes/RectHitbox.h"
#include "../Player/Player.h"
#include "../GameObject/Actor/Actor.h"
#include "ItemEffects.h"
#include "../Player/StatsComp.h"
#include "../ResourceManager.h"

extern ResourceManager resourceManager;

extern Player player;

MeleeAttack::MeleeAttack() {
}

MeleeAttack::MeleeAttack(const MeleeAttack& orig) {
}

MeleeAttack::~MeleeAttack() {
    delete hb;
}

void MeleeAttack::init() {

}


RectHitbox* MeleeAttack::getHitbox(double _time) {
    if ( _time > timeHBStart && _time < timeHBEnd ) {
        float hbX = player.getX() + attackStartX + _time*attackPathX;

        float hbY = player.getY() + attackStartY;
        if (attackPathCurve) {
            if (_time > time/2.0) hbY += (_time - time/2.0)*2.0*attackPathY;
        }
        else hbY += _time*attackPathY;

        hb->moveTo(hbX,hbY);
        return hb;
    }
    return nullptr;
}

void MeleeAttack::applyHit(StatsComp* holder, StatsComp* target) {
    for (int i = 0; i < effectID.size(); i++) {
        resourceManager.itemEffects.applyEffect(holder, target, effectID.at(i), effectAmount.at(i));
    }
}


void MeleeAttack::render() {
    graphic->render(player.getX(), player.getY(), player.getZ(), 1.0, 0.0);
}



void MeleeAttack::loadAttack(std::string path) {
    std::ifstream aFile;
    aFile.open(path);
    std::cout << aFile.is_open() << std::endl;
    std::string attackFile;
    while(std::getline(aFile, attackFile)) {}
    aFile.close();
    
    std::cout << attackFile << std::endl;
    if (attackFile.size()>0) {
        int grNum;
        std::istringstream iss(attackFile); iss >> grNum;
        graphic = resourceManager.meleeAttackGraphic.at(grNum);
        
        double hbW, hbH;
        iss >> hbW;
        iss >> hbH;
        hb = new RectHitbox(0,0, hbW, hbH);
        
         // start of effects
        int numEffects;
        iss >> numEffects;
        for (int i = 0; i < numEffects; i++) {
            int ID; float amnt;
            iss >> ID; iss >> amnt;
            effectID.push_back(ID);
            effectAmount.push_back(amnt);
        }
        
        iss >> attackStartX;
        std::cout << "attackStart X " << attackStartX << std::endl;
        iss >> attackStartY;
        iss >> attackPathX;
        iss >> attackPathY;
        iss >> attackPathCurve;
        iss >> stagger;
        iss >> stamina;
        iss >> damage;
        iss >> time;
        iss >> timeHBStart;
        iss >> timeHBEnd;

    }
    
}
