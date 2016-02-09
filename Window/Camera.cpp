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

extern Player player;

Camera::Camera() {
}

Camera::Camera(const Camera& orig) {
}

Camera::~Camera() {
}

SDL_Rect Camera::getViewport() {
    SDL_Rect viewPort;
    viewPort.w = (int)((double)DEFAULT_CAMERA_W/zoom);
    viewPort.h = (int)((double)DEFAULT_CAMERA_H/zoom);
    viewPort.x = player.getX() - viewPort.w/2;
    viewPort.y = player.getY() - viewPort.h/2;
    return viewPort;
}

void Camera::setZoom(double _zoom) { zoom = _zoom; }

double Camera::getZoom() { return zoom; }




