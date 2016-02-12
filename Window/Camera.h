/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.h
 * Author: sam
 *
 * Created on 9 February 2016, 10:28 AM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "../Player/Player.h"
#include <SDL.h>
#include "../GameObject/Vec2.h"

// lower number is more lag
#define CAMERA_X_LAG 0.05
#define CAMERA_Y_LAG 0.3

#define DEFAULT_CAMERA_W 1920.0
#define DEFAULT_CAMERA_H 1080.0

#define BACKGROUND_DIST 0.9
#define FOREGROUND_DIST 1.1

class Camera {
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void updateViewport();
    SDL_Rect getViewport(int xOff, int yOff);
    SDL_Rect getParallaxViewport(double dist, int xOff, int yOff);
    
    void setZoom(double _zoom);
    double getZoom();
    
private:
    SDL_Rect viewport;
    
    double zoom;
    
    double camSpeedX;
    double camSpeedY;
    
    Vec2 camPos; // this is the centre of the screen.

};

#endif /* CAMERA_H */

