/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MeleeWeapon.cpp
 * Author: sam
 * 
 * Created on 17 February 2016, 1:22 PM
 */

#include "MeleeWeapon.h"

#include "../Player/Player.h"
#include "../GameObject/Actor/Actor.h"
#include "../ResourceManager.h"
#include "../Graphics/Graphic.h"

extern Player player;
extern ResourceManager resourceManager;

MeleeWeapon::MeleeWeapon() {
}

MeleeWeapon::MeleeWeapon(const MeleeWeapon& orig) {
}

MeleeWeapon::~MeleeWeapon() {

}

void MeleeWeapon::init() {

}


void MeleeWeapon::update() {
    if (attackState == ATTACK_NONE) return;
    
    if (attack->time < timer.getSeconds() ||
        attackState == ATTACK_DROP && player.primary != player.jumping ) {
        attackState = ATTACK_NONE;
        graphic = carrying;
        graphic->setFrame(0);
    } 
}

void MeleeWeapon::updateValues() {
    // Base Damage
    damage =  attack->damage + 
                    STAT->damageBasePower +
                    STAT->damageBaseControl;
    // Scaling
    damage += (attack->damage + STAT->damageBasePower)*(STAT->power*powerScale);
    damage += (attack->damage + STAT->damageBaseControl)*(STAT->control*controlScale);
}



void MeleeWeapon::render() {
    graphic->setDirection(player.direction);
    if (player.direction == 0) {
        graphic->render(player.getX() - 70, player.getY() - 50, player.getZ(), 1.0, 0.0);
    } 
    else graphic->render(player.getX() + 30, player.getY() - 50, player.getZ(), 1.0, 0.0);
}


void MeleeWeapon::attackWeak(Actor* target) {
    if (attackState != ATTACK_NONE) return;
    timer.start();
    attackState = ATTACK_WEAK;
    attack = attack_Weak;
    graphic = attack_Weak->graphic;
    graphic->setFrame(0);
}

void MeleeWeapon::attackStrong(Actor* target) {
    if (attackState != ATTACK_NONE) return;
    timer.start();
    attackState = ATTACK_STRONG;
    attack = attack_Strong;
    graphic = attack_Strong->graphic;
    graphic->setFrame(0);
}

void MeleeWeapon::attackDrop(Actor* target) {
    attackState = ATTACK_DROP;
    attack = attack_Drop;
    graphic = attack_Drop->graphic;
    graphic->setFrame(0);
}


void MeleeWeapon::applyHit(StatsComp* target) {
    attack->applyHit(holder->statsComp, target);
    //target->takeDamage(damage);
}

RectHitbox* MeleeWeapon::getHitbox() {
    float time = timer.getSeconds();
    if (time < attack->time) return attack->getHitbox(time);
    else return nullptr;
}

// these need to be in their own class.
void MeleeWeapon::applyStats() {
    for (int i = 0; i < effectID.size(); i++) {
        resourceManager.itemEffects.applyEffect(STAT, STAT, effectID.at(i), effectAmount.at(i));
    }
}

void MeleeWeapon::removeStats() {
    for (int i = 0; i < effectID.size(); i++) {
        resourceManager.itemEffects.applyEffect(STAT, STAT, -effectID.at(i), effectAmount.at(i));
    }
}

void MeleeWeapon::loadWeapon(std::string path) {
    
    std::ifstream wFile;
    wFile.open(path);
    std::string weapFile;
    while(std::getline(wFile, weapFile)) {}
    wFile.close();
    
    if (weapFile.size()>0) {
        std::istringstream iss(weapFile);
        iss >> weaponName;
        int wType;
        iss >> wType;
        switch (wType) {
            case 0 : weaponType = W_FIST; break;
            case 1 : weaponType = W_DAGGER; break;
            case 2 : weaponType = W_SWORD; break;
            case 3 : weaponType = W_CLUB; break;
            case 4 : weaponType = W_AXE; break;
            case 5 : weaponType = W_STAFF; break;
        }
        
        iss >> powerScale;
        iss >> controlScale;
        int grNum;
        iss >> grNum;
        carrying = resourceManager.meleeCarryGraphic.at(grNum);
        
        // start of effects
        int numEffects;
        iss >> numEffects;
        for (int i = 0; i < numEffects; i++) {
            int ID; float amnt;
            iss >> ID; iss >> amnt;
            effectID.push_back(ID);
            effectAmount.push_back(amnt);
        }
        
        int wAttackID, sAttackID, dAttackID;
        iss >> wAttackID;
        iss >> sAttackID;
        iss >> dAttackID;

        attack_Weak = resourceManager.meleeAttacks.at(3*wAttackID);
        attack_Strong = resourceManager.meleeAttacks.at(3*sAttackID + 1);
        attack_Drop = resourceManager.meleeAttacks.at(3*dAttackID + 2);

    }
    
    attack = attack_Weak;
    attackState = ATTACK_NONE;
    graphic = carrying;

}