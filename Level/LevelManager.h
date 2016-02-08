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

class LevelManager {
public:
    LevelManager();
    LevelManager(const LevelManager& orig);
    virtual ~LevelManager();
    
    int platformCount();
    int playerPlatformCount();
    RectHitbox* getPlatformHitbox(int i);
    RectHitbox* getPlayerPlatformHitbox(int i);
    
    void render();
    
    void init();
    
    ////////////////////////////////////////
    //testing
    
    void addPlatform(BasicPlatform* hb);
    
private:
    
    void initialLoadSegments();
    
    LevelSegment* getSegment(double x, double y);
    
    int get_Seg_X_Count(double x);
    int get_Seg_Y_Count(double y);
    
    LevelSegment* currentSegment;
    /*
     *  loadedSegment[0] is the central segment
     *  loadedSegment[1] is to it's right.
     *  loadedSegment[2] is to it's right and down.
     *  loadedsegment[9] is two to the right of [0].
     * 
     * Player hitboxes only check loadedSegments[0];
     * graphics render for onl the segments that are on screen.
     */
    
    std::vector <LevelSegment*> loadedSegments;
};

#endif /* LEVELMANAGER_H */

