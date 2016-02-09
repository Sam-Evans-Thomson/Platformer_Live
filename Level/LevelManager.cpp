/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelManager.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 2:19 PM
 */

#include "LevelManager.h"
#include "../Player/Player.h"

extern Player player;

LevelManager::LevelManager() {
    
}

LevelManager::LevelManager(const LevelManager& orig) {
}

LevelManager::~LevelManager() {
}

void LevelManager::init() {
    loadedSegments.reserve(25);
    initialLoadSegments();
}

void LevelManager::initialLoadSegments() {
    for (int i = 0; i < 25 ; i++) {
        loadedSegments[i] = new LevelSegment(i%5,i/5);
    }
}

int LevelManager::platformCount() {
    int count = 0;
    for (int i = 0; i < 25; i++) {
        count += loadedSegments[i]->getPlatformCount();
    }
    return count;
}

BasicPlatform* LevelManager::getPlatform(int i) {
    int count = 0;
    while (i > 0 && count < 25) { i-=loadedSegments[count++]->LevelSegment::getPlatformCount(); }  
    i+=loadedSegments[count--]->LevelSegment::getPlatformCount();
    return loadedSegments[count]->LevelSegment::getPlatform(i);
}

int LevelManager::playerPlatformCount() {
    return loadedSegments[12]->LevelSegment::getPlatformCount();
}

BasicPlatform* LevelManager::getPlayerPlatform(int i) {
    if (i<loadedSegments[12]->LevelSegment::getPlatformCount()) {
        return loadedSegments[12]->LevelSegment::getPlatform(i);
    }    
}

void LevelManager::render() {
    loadedSegments[12]->LevelSegment::render();
}


int LevelManager::get_Seg_X_Count(double x) { return (int)x/SEGMENT_WIDTH; }

int LevelManager::get_Seg_Y_Count(double y) { return (int)y/SEGMENT_HEIGHT;
}

int LevelManager::get_Seg_Num(int x, int y) {
    return x+5*y;
}


void LevelManager::addPlatform(BasicPlatform* hb) {
    int segX = get_Seg_X_Count(hb->getX());
    int segY = get_Seg_Y_Count(hb->getY());
    int plat = get_Seg_Num(segX,segY);
    
    loadedSegments[plat]->LevelSegment::addPlatform(hb);
    std::cout << "levelManager addPlatform in segment: " << plat <<std::endl; 
}

void LevelManager::addPlatform(BasicPlatform* hb, int segX, int segY) {
    int plat = get_Seg_Num(segX,segY);
    
    loadedSegments[plat]->LevelSegment::addPlatform(hb);
}

int LevelManager::getCameraXOffset() {
    return (xOffset+2)*SEGMENT_WIDTH;
}

int LevelManager::getCameraYOffset() {
    return (yOffset + 2)*SEGMENT_HEIGHT;
}



