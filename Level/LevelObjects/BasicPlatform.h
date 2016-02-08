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
    
    void render();
    
    // init needs to be called until it returns -1;
    int init(int i);

    void setGraphicPath(std::string _path);
    void setGraphicPath(int frameCount, std::string _path);
    
    // These are in relation to the pos and w,h of the hitbox.
    void setGraphicDimensions(double x, double y, double _w, double _h, int behaviour);
    
    Vec2 getPos();
    double getX();
    double getW();
    double getY();
    double getH();
    
    RectHitbox* hb;
    Graphic* graphic;
    
private:
    
    int numFrames = 0;
    
    void loadHitbox();
    void loadGraphic();
    
    int initFirst();
    int initLast();
    
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

