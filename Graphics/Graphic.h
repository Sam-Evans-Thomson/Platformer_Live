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

#define GRAPHIC_CLIP 0
#define GRAPHIC_SCALE 1
#define GRAPHIC_NONE 2

class Graphic {
public:
    Graphic(int frameCount, std::string str);
    Graphic(const Graphic& orig);
    virtual ~Graphic();
    
    void setFrameTime(double time);
    void setClip(int x, int y, int w, int h, int _behaviour);
    
    void start();
    void pauseAnimation();
    void contAnimation();
    void setFirst();
    void setFrame(int i);
    
    void flip();
    void setDirection(bool dir);
    
    void render(double x,double y, int z, double scale, double rotation);
    void renderToCanvas(Texture* tex, double x, double y, int z, double scale, double rotation);

    bool isReversing();
    void setReversing(bool rev);
    void loadTextures();
    
    bool hasFinished();
    
private:
    Timer timer;
    double frameTime;
    
    bool doesReverse;
    bool reversing;
    bool paused;
    
    // facing right is true;
    bool direction;
    
    void incFrame();
    
    int numFrames;
    int currentFrame = 0;
    
    SDL_Rect clip;
    int clipBehaviour = GRAPHIC_NONE;
    
    Texture textures[20];
    
    std::string path;

};

#endif /* GRAPHIC_H */

