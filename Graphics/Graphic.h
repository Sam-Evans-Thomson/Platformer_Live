/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graphic.h
 * Author: sam
 *
 * Created on 3 February 2016, 1:16 PM
 */

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "../Window/Texture.h"
#include "../Utilities/Timer.h"
#include "../Window/Canvas.h"

#include <iostream>
#include <string>
#include <vector>

class Graphic {
public:
    Graphic(int frameCount, std::string str);
    Graphic(const Graphic& orig);
    virtual ~Graphic();
    
    void setFrameTime(double time);
    
    void start();
    
    void render(Canvas* canvas, double x,double y, int z, double scale, double rotation);
    
    void loadTextures();
    
    bool hasFinished();
    
private:
    Timer timer;
    double frameTime;
    
    void incFrame();
    
    int const numFrames = 6;
    int currentFrame = 0;
    
    std::string path;
    std::vector<Texture*> textures;
    Texture* currentTexture;

};

#endif /* GRAPHIC_H */

