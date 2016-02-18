/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResourceManager.cpp
 * Author: sam
 * 
 * Created on 11 February 2016, 3:31 PM
 */

#include "ResourceManager.h"
#include "Graphics/Graphic.h"
#include "Items/MeleeWeapon.h"
#include "Items/MeleeAttack.h"


ResourceManager::ResourceManager() {
}

ResourceManager::ResourceManager(const ResourceManager& orig) {
}

ResourceManager::~ResourceManager() {
    delete background;
    for (Graphic* grptr : platforms) delete grptr;
    for (Graphic* grptr : decorations) delete grptr;
    delete running;
    delete column;
    delete stamina;
    delete health;
    delete stair;
    delete dodge;
    for (Graphic* grptr : meleeCarryGraphic) delete grptr;
    for (Graphic* grptr : meleeAttackGraphic) delete grptr;
    for (Graphic* grptr : rangeCarryGraphic) delete grptr;
    for (Graphic* grptr : rangeAttackGraphic) delete grptr;

    for (MeleeWeapon* grptr : meleeWeapons) delete grptr;
    for (MeleeAttack* grptr : meleeAttacks) delete grptr;
}

void ResourceManager::init() {
    initGraphics();
    initSounds();
    initAttacks();
    initWeapons();
}

void ResourceManager::initGraphics() {
    Graphic* pfm = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/ground");
    pfm->setFrameTime(0.1);
    pfm->loadTextures();
    pfm->start();
    platforms.push_back(pfm);
    
    Graphic* bgd = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/bgd_0_0_");
    bgd->loadTextures();
    background = bgd;

    dodge = new Graphic(2,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Dodge/basic");
    dodge->setFrameTime(0.1);
    dodge->loadTextures();
    
    running = new Graphic(6,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Running/basic");
    running->setFrameTime(0.1);
    running->loadTextures();
    running->start();
    
    column = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/column");
    column->loadTextures();
    
    stair = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/stair_30_");
    stair->loadTextures();
    
    stamina = new Graphic(10,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/stam");
    stamina->setFrameTime(0.1);
    stamina->loadTextures();
    stamina->start();
    
    health = new Graphic(10,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/health");
    health->setFrameTime(0.1);
    health->loadTextures();
    health->start();
    
    Graphic* vine = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/vine");
    vine->loadTextures();
    decorations.push_back(vine);
    
    Graphic* cf = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/cliffFace");
    cf->loadTextures();
    decorations.push_back(cf);
    
    Graphic* swordAttack  = new Graphic(7,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/attack/attack");
    swordAttack->setFrameTime(0.05);
    swordAttack->loadTextures();
    swordAttack->start();
    meleeAttackGraphic.push_back(swordAttack);
    Graphic* swordCarry  = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/attack/attack");
    swordCarry->loadTextures();
    meleeCarryGraphic.push_back(swordCarry);
}

void ResourceManager::initSounds() {

}

void ResourceManager::initAttacks() {
    MeleeAttack* basicSwordWeak = new MeleeAttack();
    MeleeAttack* basicSwordStrong = new MeleeAttack();
    MeleeAttack* basicSwordDrop = new MeleeAttack();
    basicSwordWeak->loadAttack("/home/sam/NetBeansProjects/Platformer_Live/Items/MeleeWeapons/BasicSwordDrop");
    basicSwordStrong->loadAttack("/home/sam/NetBeansProjects/Platformer_Live/Items/MeleeWeapons/BasicSwordDrop");
    basicSwordDrop->loadAttack("/home/sam/NetBeansProjects/Platformer_Live/Items/MeleeWeapons/BasicSwordDrop");
    meleeAttacks.push_back(basicSwordWeak);
    meleeAttacks.push_back(basicSwordStrong);
    meleeAttacks.push_back(basicSwordDrop);
    
}

void ResourceManager::initWeapons() {
    MeleeWeapon* basicSword = new MeleeWeapon();
    basicSword->loadWeapon("/home/sam/NetBeansProjects/Platformer_Live/Items/MeleeWeapons/Basic_Sword");
    meleeWeapons.push_back(basicSword);
    
}
