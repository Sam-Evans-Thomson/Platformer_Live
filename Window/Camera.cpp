/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: sam
 * 
 * Created on 9 February 2016, 10:28 AM
 */

#include "Camera.h"
#include "../InputComponent.h"

extern Player player;
extern InputComponent inputComponent;

Camera::Camera() {
}

Camera::Camera(const Camera& orig) {
}

Camera::~Camera() {
}



SDL_Rect Camera::getViewport() { 
    return viewport;
}

SDL_Rect Camera::getParallaxViewport(double dist) {
    SDL_Rect rect;
    rect.x = dist*viewport.x;
    rect.y = dist*viewport.y;
    rect.w = viewport.w;
    rect.h = viewport.h;
    return rect;
}


void Camera::updateViewport() {
    zoom = 1.5 + 0.5*inputComponent.rTh_Y;
    viewport.w = (int)(DEFAULT_CAMERA_W/zoom);
    viewport.h = (int)(DEFAULT_CAMERA_H/zoom);
    viewport.x = player.getX() - viewport.w/2.0;
    viewport.y = player.getY() - viewport.h/2.0;
}


void Camera::setZoom(double _zoom) { zoom = _zoom; }

double Camera::getZoom() { return zoom; }




