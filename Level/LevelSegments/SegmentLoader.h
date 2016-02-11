/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SegmentLoader.h
 * Author: sam
 *
 * Created on 10 February 2016, 3:35 PM
 */

#ifndef SEGMENTLOADER_H
#define SEGMENTLOADER_H



#include "../../Level/LevelObjects/BasicPlatform.h"



#define SEGPATH "seg_"

#define SPRITE1 "Sprites/ground"


class SegmentLoader {
public:
    SegmentLoader();
    SegmentLoader(const SegmentLoader& orig);
    virtual ~SegmentLoader();
    
    void loadSegment(int x, int y);
    
    BasicPlatform processLine(int i);
    
private:

    std::string path;
    
    std::string platforms[2];
};

#endif /* SEGMENTLOADER_H */

