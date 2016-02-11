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

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "../Graphics/Graphic.h"

#define SEGMENT_WIDTH 1920
#define SEGMENT_HEIGHT 1080

class SegmentLoader;

class LevelSegment {
public:
    LevelSegment();
    LevelSegment(int x, int y);
    LevelSegment(const LevelSegment& orig);
    virtual ~LevelSegment();
    
    void setXY(int _x, int _y);

    int getPlatformCount();
    BasicPlatform* getPlatform(int i);
    
    void render();
    
    ////// SEGMENT CREATION
    
    void loadSegment();
    void addPlatform(int X, int Y, int z, int w, int h, int img);
    void addBackground(int frames, std::string path );
    // void addDecoration();)
    
    

private:
    
    // HEAP
    Graphic* background;
    std::vector <BasicPlatform*> platforms;
    //std::vector <Decoration*> decorations;
    
    // STACK
    
    // segment number || NOT world coordinates
    int x; 
    int y;
    
};

#endif /* LEVELSEGMENT_H */

