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

class LevelManager {
public:
    LevelManager();
    LevelManager(const LevelManager& orig);
    virtual ~LevelManager();
    
    int platformCount();
    int playerPlatformCount();
    
    BasicPlatform* getPlatform(int i);
    BasicPlatform* getPlayerPlatform(int i);
    
    void render();
    void update();
    void checkPlayerPos();
    void checkLoadedSegments();
    void checkRenderSegments();
    void moveSegments(int x, int y);
    
    void loadRightSegments();
    void loadBottomSegments();
    void loadLeftSegments();
    void loadTopSegments();
    
    void init();
    
    ////////////////////////////////////////
    //testing
    
    void addPlatform(BasicPlatform* hb);
    void addPlatform(BasicPlatform* hb, int segX, int segY);
    int getCameraXOffset();
    int getCameraYOffset();
    

private:

    int xOffset = 0;
    int yOffset = 0;
    
    int renderOffsetX = 0;
    int renderOffsetY = 0;
    
    void initialLoadSegments();
    
    LevelSegment* getSegment(double x, double y);
    
    int get_Seg_X_Count(double x);
    int get_Seg_Y_Count(double y);
    
    LevelSegment* renderSegs[4];
    
    
    
    /*
     * Player hitboxes only check loadedSegments[2][2];
     * graphics render for only the segments that are on screen.
     */
    
    //// ABSOLUTELY NEED TO USE SMART POINTERS FOR SEGMENTS///
    /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    
    LevelSegment* loadedSegments[5][5];
};

#endif /* LEVELMANAGER_H */

