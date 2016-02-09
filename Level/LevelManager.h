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

#define SEGMENT_WIDTH 1920
#define SEGMENT_HEIGHT 1080

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
    
    void initialLoadSegments();
    
    LevelSegment* getSegment(double x, double y);
    
    int get_Seg_X_Count(double x);
    int get_Seg_Y_Count(double y);
    int get_Seg_Num(int x, int y);
    
    LevelSegment* currentSegment;
    /*
     *  [00][01][02][03][04]
     *  [05][06][07][08][09]
     *  [10][11][12][13][14]
     *  [15][16][17][18][19]
     *  [20][21][22][23][24] 
     * 
     * Player hitboxes only check loadedSegments[12];
     * graphics render for onl the segments that are on screen.
     */
    
    std::vector <LevelSegment*> loadedSegments;
};

#endif /* LEVELMANAGER_H */

