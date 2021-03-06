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


#include "../Utilities/Timer.h"
#include "../Window/Canvas.h"
#include "../Window/Texture.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Graphic {
public:
    Graphic(int frameCount, std::string str);
    Graphic(const Graphic& orig);
    virtual ~Graphic();
    
    void loadTextures();
    
    void setFirst();
    void setFrame(int i);
    void setFrameTime(double time);
    void setClip(int x, int y, int w, int h);
    void setReversing(bool rev);
    void setDirection(bool dir);
    void flip();
    
    void start();
    void pause();
    void resume();

    void render(double x,double y, int z, double scale, double rotation);
    void renderAsOverlay(double x, double y, double scale, double rot);

    bool isReversing();
    bool hasFinished();
    
private:
    
    void renderToCanvas(Texture* tex, double x, double y, int z, double scale, double rotation);
    void incFrame();
    
    
    // HEAP
    std::vector<Texture*> textures;
    Timer* timer;
    
    // STACK
    std::string path;
 
    double frameTime;
    int numFrames;
    int currentFrame = 0;
    
    bool doesReverse;
    bool reversing;
    bool paused;
    bool direction;     // facing right is true;

    SDL_Rect clip;

};

#endif /* GRAPHIC_H */

