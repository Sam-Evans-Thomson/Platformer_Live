/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SegmentLoader.cpp
 * Author: sam
 * 
 * Created on 10 February 2016, 3:35 PM
 */

#include "SegmentLoader.h"
#include "../LevelManager.h"

extern LevelManager levelManager;

SegmentLoader::SegmentLoader() {
}

SegmentLoader::SegmentLoader(const SegmentLoader& orig) {
}

SegmentLoader::~SegmentLoader() {
}

void SegmentLoader::loadSegment(int x, int y) {
    path = std::string("Level/LevelSegments/seg_" + std::to_string(x) + "_" + std::to_string(y) +".txt");
    std::ifstream segFile;
    std::string line;
    
    segFile.open(path);
    
    std::cout << segFile.is_open() << std::endl;
    
    int i= 0;
    for (std::string line; std::getline(segFile,line);) { 
        platforms[i] = line;
        i++;
    }
    
}

BasicPlatform SegmentLoader::processLine(int i) {
    std::vector<std::string> info;
    std::istringstream iss(platforms[i]);
    std::string str;
    
    while (iss >> str) {
        info.push_back(str);
    }
    
    if (info.at(0) == "BP") {
        double x = std::stod(info.at(1));
        double y = std::stod(info.at(2));
        int z = std::stod(info.at(3));
        double w = std::stod(info.at(4));
        double h = std::stod(info.at(5));
        
        BasicPlatform bp(x,y,z,w,h);
        bp.setGraphicPath(SPRITE1);
        bp.init(0);
        bp.init(1);
        bp.setGraphicDimensions(0,-3.0,0.0,0.0);
        return bp;
    }
    
}


