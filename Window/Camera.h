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

#define DEFAULT_CAMERA_W 1920
#define DEFAULT_CAMERA_H 1080

class Camera {
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    SDL_Rect getViewport();
    void setZoom(double _zoom);
    double getZoom();
    
private:
    
    double zoom = 1.2;

};

#endif /* CAMERA_H */

