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

#define SEGMENT_WIDTH 1920
#define SEGMENT_HEIGHT 1080

#include <vector>
#include "LevelObjects/BasicPlatform.h"
#include "../Graphics/Graphic.h"

class LevelSegment {
public:
    LevelSegment();
    LevelSegment(int x, int y);
    LevelSegment(const LevelSegment& orig);
    virtual ~LevelSegment();
    
    void render();
    
    void addPlatform(BasicPlatform* hb);
    void addBackground(int frames, std::string path );
    
    int getPlatformCount();
    BasicPlatform* getPlatform(int i);
    
    void loadSegment(int x, int y);
    
private:
    
    int x; int y;
    
    Graphic* background;
    
    //std::vector <Decoration*> decorations;
    std::vector <BasicPlatform*> platforms;
};

#endif /* LEVELSEGMENT_H */

