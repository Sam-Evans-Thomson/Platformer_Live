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

LevelSegment::LevelSegment(int x, int y) : x(x), y(y) {
    loadSegment(x,y);
}

LevelSegment::LevelSegment(const LevelSegment& orig) {
    
}

LevelSegment::~LevelSegment() {
    delete background;
    //delete &decorations;
    delete &platforms;
}

void LevelSegment::render() {
    //for ( Decoration* d : decorations) d->render();
    for ( BasicPlatform* bp : platforms) bp->render();
    background->render((double)x*SEGMENT_WIDTH,(double)y*SEGMENT_HEIGHT,Z_BACKGROUND,1.0,0.0);
}


void LevelSegment::loadSegment(int x, int y) {

}



void LevelSegment::addPlatform(BasicPlatform* platform) {
    platforms.push_back(platform);
}

void LevelSegment::addBackground(int frames, std::string path) {
    background = new Graphic(frames, path);
    background->setFrameTime(0.2);
    background->loadTextures();
    background->start();
}



int LevelSegment::getPlatformCount() { return platforms.size(); }

BasicPlatform* LevelSegment::getPlatform(int i) { 
    return platforms.at(i);
}




