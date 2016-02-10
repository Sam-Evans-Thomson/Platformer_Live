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
    
    for (int i = 0; i < 5 ; i++) {
        for (int j = 0; j < 5 ; j++) {
            loadedSegments[i][j] = new LevelSegment(i,j);
            loadedSegments[i][j]->addBackground(1,"Sprites/background");
        }
    }
    
    renderSegs[0] = loadedSegments[2][2];
    renderSegs[1] = loadedSegments[1][2];
    renderSegs[2] = loadedSegments[2][1];
    renderSegs[3] = loadedSegments[1][1];
}

int LevelManager::platformCount() {
    int count = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++ ) {
            count += loadedSegments[i][j]->getPlatformCount();
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
            count2 = count + loadedSegments[k][j]->getPlatformCount();
            if (count2 > i) {
                return loadedSegments[k][j]->getPlatform(k-count);
            }
            else count = count2;
        }
    } 
}

int LevelManager::playerPlatformCount() {
    return loadedSegments[2][2]->LevelSegment::getPlatformCount();
}

BasicPlatform* LevelManager::getPlayerPlatform(int i) {
    if (i<loadedSegments[2][2]->LevelSegment::getPlatformCount()) {
        return loadedSegments[2][2]->LevelSegment::getPlatform(i);
    }    
}

void LevelManager::update() {
    checkPlayerPos();
}

void LevelManager::checkPlayerPos() {
    checkLoadedSegments();
    checkRenderSegments();
}

void LevelManager::checkLoadedSegments() {
    int x = get_Seg_X_Count(player.getX());
    int y = get_Seg_Y_Count(player.getY());
    
    moveSegments(x-(xOffset+2), y-(yOffset + 2));
}

void LevelManager::moveSegments(int x, int y) {
    
    //shift them all left
    if (x>0) {
        for(int i = 0; i<4; i++) {
            for(int j = 0; j<5; j++) {
                loadedSegments[i][j] = loadedSegments[i+1][j];
            }
        }
        
        xOffset++;
        loadRightSegments();
        
    } else if (x<0) {
        for(int i = 5; i>1; i--) {
            for(int j = 0; j<5; j++) {
                loadedSegments[i][j] = loadedSegments[i-1][j];
            }
        }
        
        xOffset--;
        loadLeftSegments();
    }
    
    //shift them all up
    if (y>0) {
        for(int i = 0; i<5; i++) {
            for(int j = 0; j<4; j++) {
                loadedSegments[i][j] = loadedSegments[i][j+1];
            }
        }
        
        yOffset++;
        loadBottomSegments();
        
    } else if (y<0) {
        for(int i = 0; i<5; i++) {
            for(int j = 5; j>1; j--) {
                loadedSegments[i][j] = loadedSegments[i][j-1];
            }
        }
        
        yOffset--;
        loadTopSegments();
    }
    
    std::cout << "xOffset: " << xOffset+2 << std::endl;
    std::cout << "yOffset: " << yOffset+2 << std::endl;
    std::cout << std::endl;
    
}

void LevelManager::loadBottomSegments() {

}

void LevelManager::loadLeftSegments() {

}

void LevelManager::loadRightSegments() {

}

void LevelManager::loadTopSegments() {

}





void LevelManager::checkRenderSegments() {
    if (player.getX() > ((double)xOffset+2.5)*SEGMENT_WIDTH) {
        if (player.getY() > ((double)yOffset+2.5)*SEGMENT_HEIGHT) {
            renderSegs[1] = loadedSegments[3][2];
            renderSegs[2] = loadedSegments[3][3];
            renderSegs[3] = loadedSegments[2][3];
            renderOffsetX = xOffset;
            renderOffsetY = yOffset;
        } else {
            renderSegs[1] = loadedSegments[2][1];
            renderSegs[2] = loadedSegments[3][1];
            renderSegs[3] = loadedSegments[3][2];
            renderOffsetX = xOffset;
            renderOffsetY = yOffset-1;
        }
    } else {
        if (player.getY() > ((double)yOffset+2.5)*SEGMENT_HEIGHT) {
            renderSegs[1] = loadedSegments[1][2];
            renderSegs[2] = loadedSegments[1][3];
            renderSegs[3] = loadedSegments[2][3];
            renderOffsetX = xOffset-1;
            renderOffsetY = yOffset;
        } else {
            renderSegs[1] = loadedSegments[1][1];
            renderSegs[2] = loadedSegments[2][1];
            renderSegs[3] = loadedSegments[1][2];
            renderOffsetX = xOffset-1;
            renderOffsetY = yOffset-1;
        }
    }
    
    renderSegs[0] = loadedSegments[2][2];
}

void LevelManager::render() {
    for (int i = 0; i < 4; i++) renderSegs[i]->render();
}


int LevelManager::get_Seg_X_Count(double x) { return (int)x/SEGMENT_WIDTH; }

int LevelManager::get_Seg_Y_Count(double y) { return (int)y/SEGMENT_HEIGHT;
}

void LevelManager::addPlatform(BasicPlatform* hb) {
    int segX = get_Seg_X_Count(hb->getX());
    int segY = get_Seg_Y_Count(hb->getY());
    std::cout << segX << std::endl;
    loadedSegments[segX][segY]->LevelSegment::addPlatform(hb); 
}

void LevelManager::addPlatform(BasicPlatform* hb, int segX, int segY) {
    loadedSegments[segX][segY]->LevelSegment::addPlatform(hb);
}

int LevelManager::getCameraXOffset() {
    return (renderOffsetX+2)*SEGMENT_WIDTH;
}

int LevelManager::getCameraYOffset() {
    return (renderOffsetY + 2)*SEGMENT_HEIGHT;
}



