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

ResourceManager::ResourceManager() {
}

ResourceManager::ResourceManager(const ResourceManager& orig) {
}

ResourceManager::~ResourceManager() {
    delete background;
    for (Graphic* grptr : platforms) delete grptr;
    delete running;
    delete column;
    delete stamina;
    delete health;
}

void ResourceManager::init() {
    
    Graphic* pfm = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/ground");
    pfm->setFrameTime(0.1);
    pfm->loadTextures();
    pfm->start();
    platforms.push_back(pfm);
    
    Graphic* bgd = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/bgd_0_0_");
    bgd->loadTextures();
    background = bgd;

    
    running = new Graphic(6,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Running/basic");
    running->setFrameTime(0.1);
    running->loadTextures();
    running->start();
    
    column = new Graphic(1,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/column");
    column->loadTextures();
    
    stamina = new Graphic(10,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/stam");
    stamina->setFrameTime(0.1);
    stamina->loadTextures();
    stamina->start();
    
    health = new Graphic(10,"/home/sam/NetBeansProjects/Platformer_Live/Sprites/Bars/health");
    health->setFrameTime(0.1);
    health->loadTextures();
    health->start();
}


