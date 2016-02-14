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
#include "../ResourceManager.h"
#include "LevelObjects/BasicPlatform.h"
#include "LevelObjects/SlopePlatform.h"

extern ResourceManager resourceManager;
extern LevelManager levelManager;

LevelSegment::LevelSegment() { }

LevelSegment::LevelSegment(int x, int y) : x(x), y(y) { loadSegment(); }

LevelSegment::LevelSegment(const LevelSegment& orig) { }

LevelSegment::~LevelSegment() {
    for (BasicPlatform* bp : platforms) delete bp;
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
    std::cout << "LevelSegment - loadSegment " << x << " " << y << std::endl;
    
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
                Graphic* gr = resourceManager.background;
                addBackground(gr);
                std::getline(segFile, line);
            }
            if (line == "BP") {
                while (line != "SP" && std::getline(segFile, line)) {
                    std::istringstream iss(line);
                    int X; int Y; int z; int w; int h; int img;
                    iss >> X; iss >> Y; iss >> z; iss >> w; iss >> h; iss >> img;
                    addPlatform(X,Y,z,w,h,img);
                }
            }
            if (line == "SP") {
                while (std::getline(segFile, line)) {
                    std::istringstream iss(line);
                    int X; int Y; int z; int w; int h; int img; double angle;
                    iss >> X; iss >> Y; iss >> z; iss >> w; iss >> h; iss >> img;
                    iss >> angle;
                    addSlopePlatform(X,Y,z,w,h,img, angle);
                }
            }
        }
        segFile.close();
    }
    
}


void LevelSegment::addPlatform(int X, int Y, int z, int w, int h, int img) {
    BasicPlatform* pfrm = 
            new BasicPlatform((double)X,(double)Y, z, (double)w, (double)h);
    
    pfrm->setGraphic(resourceManager.platforms.at(0)); // resource manager.
    pfrm->setGraphicDimensions(0,0,0,0);
    pfrm->init();
    platforms.push_back(pfrm);
    
}

void LevelSegment::addSlopePlatform(int X, int Y, int z, int w, int h, int img, double angle) {
    SlopePlatform* pfrm = 
            new SlopePlatform((double)X,(double)Y, z, (double)w, (double)h, angle);
    
    pfrm->setGraphic(resourceManager.platforms.at(0)); // resource manager.
    pfrm->setGraphicDimensions(0,0,0,0);
    pfrm->init();
    platforms.push_back(pfrm);
    
}

void LevelSegment::addBackground(Graphic* gr) {
    background = gr;
    background->start();
}









