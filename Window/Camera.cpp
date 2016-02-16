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
    camPos.setX(player.getX());
    camPos.setY(player.getY());
    camSpeedX = 0;
    camSpeedY = 0;
}

Camera::Camera(const Camera& orig) {
}

Camera::~Camera() {
}

void Camera::update() {
    updateViewport();
}

SDL_Rect Camera::getViewport(int xOff, int yOff) { 
    SDL_Rect temp;
    temp.x = viewport.x - xOff;
    temp.y = viewport.y - yOff;
    temp.w = viewport.w;
    temp.h = viewport.h;
    return temp;
}

SDL_Rect Camera::getParallaxViewport(double dist, int xOff, int yOff) {

    SDL_Rect temp;
    temp.x = (viewport.x - xOff) + (1.0-dist)*DEFAULT_CAMERA_W/2.0;
    temp.y = (viewport.y - yOff) + (1.0-dist)*DEFAULT_CAMERA_H/2.0;
    temp.w = viewport.w*dist;
    temp.h = viewport.h*dist;
    return temp;
}


void Camera::updateViewport() {
    zoom = 1.6 - 0.3*inputComponent.rTh_Y*inputComponent.rTh_Y;
    
    double xSpeed = player.getX() - player.getPrevX();
    double ySpeed = player.getY() - player.getPrevY();

    if( xSpeed > camSpeedX) { camSpeedX += (xSpeed-camSpeedX)*CAMERA_X_LAG; }
    else if( xSpeed < camSpeedX) { camSpeedX -= (camSpeedX-xSpeed)*CAMERA_X_LAG; }
    
    if( ySpeed > camSpeedY) { camSpeedY += (ySpeed-camSpeedY)*CAMERA_Y_LAG; }
    else if( ySpeed < camSpeedY) { camSpeedY -= (camSpeedY-ySpeed)*CAMERA_Y_LAG; }
    
    camPos += Vec2(camSpeedX,camSpeedY);
    
    viewport.w = (int)(DEFAULT_CAMERA_W/zoom);
    viewport.h = (int)(DEFAULT_CAMERA_H/zoom);
    viewport.x = camPos.getX() - viewport.w/2.0;
    viewport.y = camPos.getY() - viewport.h/2.0;
}


void Camera::setZoom(double _zoom) { zoom = _zoom; }

double Camera::getZoom() { return zoom; }




