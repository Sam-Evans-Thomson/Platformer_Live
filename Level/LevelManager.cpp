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

SegArray::SegArray() { }

SegArray::SegArray(const SegArray& orig) { }

SegArray::~SegArray() { 
    for (LevelSegment* segptr : vec2D) {
        if (segptr != nullptr) delete segptr;
    } 
}

LevelSegment* SegArray::at(int x, int y) { 
    LevelSegment* segptr = vec2D[x*sizeX + y];
    return segptr;
}

void SegArray::set(int x, int y, LevelSegment* ls) {
    vec2D[x*sizeX + y];
    vec2D[x*sizeX + y] = ls;
}



LevelManager::LevelManager() { }

LevelManager::LevelManager(const LevelManager& orig) { }

LevelManager::~LevelManager() {
}

void LevelManager::init() { 
    initialLoadSegments(); 
}

int LevelManager::getSegCountX(double x) { return (int)x/SEGMENT_WIDTH; }

int LevelManager::getSegCountY(double y) { return (int)y/SEGMENT_HEIGHT;}

int LevelManager::getCameraXOffset() { return (renderOffsetX+2)*SEGMENT_WIDTH; }

int LevelManager::getCameraYOffset() { return (renderOffsetY+2)*SEGMENT_HEIGHT; }

int LevelManager::getBackgroundXOffset() { return (xOffset+1)*SEGMENT_WIDTH; }

int LevelManager::getBackgroundYOffset() { return (yOffset+1)*SEGMENT_HEIGHT; }



int LevelManager::platformCount() {
    int count = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++ ) {
            count += loadedSegments.at(i,j)->getPlatformCount();
        }
    }

    return count;
}

BasicPlatform* LevelManager::getPlatform(int i) {
    int count = 0;
    int count2;
    int k = 0;
    int j = 0;
    for (k = 0; k < 5; k++) {
        for (j = 0; j < 5; j++ ) {
            count2 = count + loadedSegments.at(k,j)->getPlatformCount();
            if (count2 > i) {
                return loadedSegments.at(k,j)->getPlatform(i-count);
            }
            else count = count2;
        }
    } 
}

int LevelManager::playerPlatformCount() {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        count += renderSegs[i]->getPlatformCount();
    }
    return count;
}

BasicPlatform* LevelManager::getPlayerPlatform(int i) {
    int count = 0;
    int count2;
    int k = 0;
    for (k = 0; k < 4; k++) {
        count2 = count + renderSegs[k]->getPlatformCount();
        if (count2 > i) {
            return renderSegs[k]->getPlatform(i-count);
        }
        else count = count2;
    }  
}

void LevelManager::update() { 
    // CHECK PLAYER POSITION
    checkLoadedSegments();
    checkRenderSegments();
    
}

void LevelManager::render() {
    for (int i = 0; i < 4; i++) renderSegs[i]->render();
    
    for (int i = 1; i < 4 ; i++) {
        for (int j = 1; j < 4 ; j++) {
            loadedSegments.at(i,j)->renderBackground();
        }
    }
}

///////// PRIVATE ///////////////////////////

void LevelManager::initialLoadSegments() {
    
    for (int i = 0; i < 5 ; i++) {
        for (int j = 0; j < 5 ; j++) {
            loadedSegments.set(i,j, new LevelSegment(i,j));
        }
    }
    
    renderSegs[0] = loadedSegments.at(2,2);
    renderSegs[1] = loadedSegments.at(1,2);
    renderSegs[2] = loadedSegments.at(2,1);
    renderSegs[3] = loadedSegments.at(1,1);

}

void LevelManager::checkLoadedSegments() {
    int x = getSegCountX(player.getX()) - 2;
    int y = getSegCountY(player.getY()) - 2;
    
    if (x-xOffset != 0 || y-yOffset != 0) {
        moveSegments(x-xOffset, y-yOffset);
    }
}

void LevelManager::checkRenderSegments() {
    if (player.getX() > ((double)xOffset+2.5)*SEGMENT_WIDTH) {
        if (player.getY() > ((double)yOffset+2.5)*SEGMENT_HEIGHT) {
            renderSegs[1] = loadedSegments.at(3,2);
            renderSegs[2] = loadedSegments.at(3,3);
            renderSegs[3] = loadedSegments.at(2,3);
            renderOffsetX = xOffset;
            renderOffsetY = yOffset;
        } else {
            renderSegs[1] = loadedSegments.at(2,1);
            renderSegs[2] = loadedSegments.at(3,1);
            renderSegs[3] = loadedSegments.at(3,2);
            renderOffsetX = xOffset;
            renderOffsetY = yOffset-1;
        }
    } else {
        if (player.getY() > ((double)yOffset+2.5)*SEGMENT_HEIGHT) {
            renderSegs[1] = loadedSegments.at(1,2);
            renderSegs[2] = loadedSegments.at(1,3);
            renderSegs[3] = loadedSegments.at(2,3);
            renderOffsetX = xOffset-1;
            renderOffsetY = yOffset;
        } else {
            renderSegs[1] = loadedSegments.at(1,1);
            renderSegs[2] = loadedSegments.at(2,1);
            renderSegs[3] = loadedSegments.at(1,2);
            renderOffsetX = xOffset-1;
            renderOffsetY = yOffset-1;
        }
    }
    
    renderSegs[0] = loadedSegments.at(2,2);
}

void LevelManager::moveSegments(int x, int y) {
    
    //shift them all left
    if (x>0) {
        for(int i = 0; i<4; i++) {
            for(int j = 0; j<5; j++) {
                loadedSegments.set(i,j,loadedSegments.at(i+1,j));
               // std::cout << i+xOffset << " = " << i+1 + xOffset << std::endl;
            }
        }
        
        xOffset++;
        loadRightSegments();
        
        
    } else if (x<0) {
        for(int i = 4; i>0; i--) {
            for(int j = 0; j<5; j++) {
                loadedSegments.set(i,j,loadedSegments.at(i-1,j));
                //std::cout << i+xOffset << " = " << i-1 + xOffset << std::endl;
            }
        }
        
        xOffset--;
        loadLeftSegments();
        
    }
    
    //shift them all up
    if (y>0) {
        for(int i = 0; i<5; i++) {
            for(int j = 0; j<4; j++) {
                loadedSegments.set(i,j,loadedSegments.at(i,j+1));
            }
        }
        
        yOffset++;
        loadBottomSegments();
        
        
    } else if (y<0) {
        for(int i = 0; i<5; i++) {
            for(int j = 4; j>0; j--) {
                loadedSegments.set(i,j,loadedSegments.at(i,j-1));
            }
        }
        
        yOffset--;
        loadTopSegments();
        
    }
    
//    std::cout << "xOffset: " << xOffset+2 << std::endl;
//    std::cout << "yOffset: " << yOffset+2 << std::endl;
//    std::cout << std::endl;
    
}

void LevelManager::loadTopSegments() {
    for (int i = 0; i < 5; i++) {
        loadedSegments.set(i,0,new LevelSegment(i+xOffset, yOffset + 4));
    }
    printSegment();
}

void LevelManager::loadBottomSegments() {
    for (int i = 0; i < 5; i++) {
        loadedSegments.set(i,0,new LevelSegment(i+xOffset, yOffset));
    }
    printSegment();
}

void LevelManager::loadLeftSegments() {
    for (int i = 0; i< 5; i++) {
        loadedSegments.set(0,i,new LevelSegment(xOffset+0,i+yOffset));
    }
    printSegment();
           
}

void LevelManager::loadRightSegments() {
    for (int i = 0; i<5; i++) {
        loadedSegments.set(4,i,new LevelSegment(xOffset+4,i + yOffset));
    }
    printSegment();
}

void LevelManager::printSegment() {
//    std::cout << "SEGMENT: " << xOffset + 2 << " " <<yOffset + 2 <<std::endl;
//    std::cout << "SEGMENT: " << loadedSegments.at(2,2) << std::endl;
}











