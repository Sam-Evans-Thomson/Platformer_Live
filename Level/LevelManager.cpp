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
    initialLoadSegments();
}

void LevelManager::initialLoadSegments() {
    double x = player.getX() - SEGMENT_WIDTH;
    double y = player.getY() - SEGMENT_HEIGHT;
    for (int i = 0; i < 25 ; i++) {
        loadedSegments[i] = LevelSegment(
                get_Seg_X_Count(x) + i,
                get_Seg_X_Count(y) + i%5);
    }
}

int LevelManager::platformCount() {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        count += loadedSegments[i].getPlatformCount();
    }
}

RectHitbox* LevelManager::getPlatformHitbox(int i) {
    int count = 0;
    while (i > 0 && count < 25) { i-=loadedSegments[count++].getPlatformCount(); }  
    i+=loadedSegments[count--].getPlatformCount();
    return loadedSegments[count].getPlatformHitbox(i);
}

int LevelManager::playerPlatformCount() {
    return loadedSegments[0].getPlatformCount();
}

RectHitbox* LevelManager::getPlayerPlatformHitbox(int i) {
    if (i<loadedSegments[0].getPlatformCount()) {
        return loadedSegments[0].getPlatformHitbox(i);
    }    
}

int LevelManager::get_Seg_X_Count(double x) { return (int)x/SEGMENT_WIDTH; }

int LevelManager::get_Seg_Y_Count(double y) { return (int)y/SEGMENT_HEIGHT;
}

void LevelManager::addPlatform(BasicPlatform* hb) {
    loadedSegments[0].addPlatform(hb);
}


