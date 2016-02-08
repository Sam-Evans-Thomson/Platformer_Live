/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelSegment.h
 * Author: sam
 *
 * Created on 6 February 2016, 2:23 PM
 */

#ifndef LEVELSEGMENT_H
#define LEVELSEGMENT_H

#define SEGMENT_PATH

#include <vector>
#include "LevelObjects/BasicPlatform.h"

class LevelSegment {
public:
    LevelSegment();
    LevelSegment(int x, int y);
    LevelSegment(const LevelSegment& orig);
    virtual ~LevelSegment();
    
    void addPlatform(BasicPlatform* hb);
    
    int getPlatformCount();
    RectHitbox* getPlatformHitbox(int i);
    
    void loadSegment(int x, int y);
    
private:
    
    std::vector <BasicPlatform*> platforms;
};

#endif /* LEVELSEGMENT_H */

