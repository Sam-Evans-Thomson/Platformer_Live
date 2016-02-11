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
#include "LevelManager.h"
#include "LevelObjects/BasicPlatform.h"


extern LevelManager levelManager;

LevelSegment::LevelSegment() { }

LevelSegment::LevelSegment(int x, int y) : x(x), y(y) { loadSegment(); }

LevelSegment::LevelSegment(const LevelSegment& orig) { }

LevelSegment::~LevelSegment() {
    delete background;
    delete &platforms;
    //delete &decorations;
}

void LevelSegment::setXY(int _x, int _y) { x=  _x; y = _y; }

int LevelSegment::getPlatformCount() { return platforms.size(); }

BasicPlatform* LevelSegment::getPlatform(int i) { return platforms.at(i); }

void LevelSegment::render() {
    //for ( Decoration* d : decorations) d->render();
    for ( BasicPlatform* bp : platforms) bp->render();
    background->render((double)x*SEGMENT_WIDTH,(double)y*SEGMENT_HEIGHT,Z_BACKGROUND,1.0,0.0);
}


//////////// SEGMENT LOADING //////////////////////

void LevelSegment::loadSegment() {
    std::string path = std::string("Level/LevelSegments/seg_" + 
            std::to_string(x) + "_" + std::to_string(y) +".txt");
    
    std::ifstream segFile;
    std::string line;
    
    //path = "Level/LevelSegments/seg_0_0.txt"; // remove this later.
    
    segFile.open(path);
    
    if (segFile.is_open()) {
        while(std::getline(segFile, line)) {
            if (line == "BGD") {
                std::getline(segFile, line);
                std::istringstream iss(line);
                int X; int Y;
                iss >> X; iss >> Y;
                std::string path = "bgd_"; 
                path+=std::to_string(X);
                path+="_";
                path+=std::to_string(Y);
                path+="_";
                addBackground(1,path);
                std::getline(segFile, line);
            }
            if (line == "BP") {
                while (std::getline(segFile, line)) {
                    std::istringstream iss(line);
                    int X; int Y; int z; int w; int h; int img;
                    iss >> X; iss >> Y; iss >> z; iss >> w; iss >> h; iss >> img;
                    addPlatform(X,Y,z,w,h,img);
                }
            }
        }
    }
    segFile.close();
}


void LevelSegment::addPlatform(int X, int Y, int z, int w, int h, int img) {
    BasicPlatform* pfrm = 
            new BasicPlatform((double)X,(double)Y, z, (double)w, (double)h);
    
    pfrm->setGraphicPath("Sprites/ground");
    pfrm->init(1);
    pfrm->init(0);
    pfrm->setGraphicDimensions(0,0,0,0);
    platforms.push_back(pfrm);
    
}

void LevelSegment::addBackground(int frames, std::string path) {
    background = new Graphic(frames, path);
    background->setFrameTime(0.2);
    background->loadTextures();
    background->start();
}








