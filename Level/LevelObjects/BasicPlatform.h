/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicPlatform.h
 * Author: sam
 *
 * Created on 6 February 2016, 3:14 PM
 */

#ifndef BASICPLATFORM_H
#define BASICPLATFORM_H

#include "../../GameObject/Hitboxes/RectHitbox.h"
#include "../../Graphics/Graphic.h"

/*
 * This is a Axis ALigned Rectangular object that the player will
 * Collide with at each side.
 */

class BasicPlatform {
public:
    BasicPlatform(Vec2 pos, int z, double w, double h);
    BasicPlatform(double x, double y, int z, double w, double h);
    BasicPlatform(const BasicPlatform& orig);
    virtual ~BasicPlatform();
    
    void setGraphicPath(std::string _path);
    void setGraphicPath(int frameCount, std::string _path);
    void setGraphicDimensions(double x, double y, double _w, double _h);
    
    int init(int i);
    void render();
    
    Vec2 getPos();
    double getX();
    double getW();
    double getY();
    double getH();
    
    // HEAP
    RectHitbox* hb;
    Graphic* graphic;
    
private:
    
    void loadHitbox();
    void loadGraphic();
    
    int initFirst();
    int initLast();
    
    int numFrames = 0;

    std::string path;
    Vec2 pos;
    double w;
    double h;
    int z;
    
    double graphX;
    double graphY;
    double graphW;
    double graphH;

};

#endif /* BASICPLATFORM_H */

