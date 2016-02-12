/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelManager.h
 * Author: sam
 *
 * Created on 6 February 2016, 2:19 PM
 */

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "LevelSegment.h"

#define SEG_X_COUNT 1
#define SEG_Y_COUNT 1

class BasicPlatform;

class SegArray {
public:
    SegArray();
    SegArray(const SegArray& orig);
    virtual ~SegArray();
    
    LevelSegment* at(int x, int y);
    void set(int x, int y, LevelSegment* ls);
    
    LevelSegment* vec2D[25];
    int sizeX = 5;
    int sizeY = 5;
private:
};

class LevelManager {
public:
    LevelManager();
    LevelManager(const LevelManager& orig);
    virtual ~LevelManager();
    
    void init();
    
    int getCameraXOffset();
    int getCameraYOffset();
    int getSegCountX(double x);
    int getSegCountY(double y);
    
    int platformCount();
    BasicPlatform* getPlatform(int i);
    
    int playerPlatformCount();
    BasicPlatform* getPlayerPlatform(int i);
    
    void update();
    void render();
  
private:
    
    void initialLoadSegments();
    
    LevelSegment* getSegment(double x, double y);
    
    void checkLoadedSegments();
    void checkRenderSegments();
    
    void moveSegments(int x, int y);
    
    void loadRightSegments();
    void loadBottomSegments();
    void loadLeftSegments();
    void loadTopSegments();
    
    void printSegment();
    
    /// HEAP
    SegArray loadedSegments; // Owned by this object
    
    
    /// STACK
    
    int xOffset = 0;  // number of segments left of loaded.
    int yOffset = 0;  // number of segments above loaded
    
    int renderOffsetX = 0;
    int renderOffsetY = 0;
    
    LevelSegment* renderSegs[4];

};

#endif /* LEVELMANAGER_H */

