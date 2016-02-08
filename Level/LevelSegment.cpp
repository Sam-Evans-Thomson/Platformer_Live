/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelSegment.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 2:23 PM
 */

#include "LevelSegment.h"
#include "LevelObjects/BasicPlatform.h"

LevelSegment::LevelSegment() {
    
}

LevelSegment::LevelSegment(int x, int y) {
    loadSegment(x,y);
}

LevelSegment::LevelSegment(const LevelSegment& orig) {
}

LevelSegment::~LevelSegment() {
}

void LevelSegment::loadSegment(int x, int y) {
 
}

void LevelSegment::addPlatform(BasicPlatform* platform) {
    platforms.push_back(platform);
}

int LevelSegment::getPlatformCount() { return platforms.size(); }

RectHitbox* LevelSegment::getPlatformHitbox(int i) { 
    BasicPlatform pf = *platforms.at(i); 
    return pf.hb;
}




