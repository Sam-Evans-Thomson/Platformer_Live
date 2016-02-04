/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Canvas.h
 * Author: sam
 *
 * Created on 3 February 2016, 3:26 PM
 */

#ifndef CANVAS_H
#define CANVAS_H

class Texture;

class Canvas {
public:
    Canvas();
    Canvas(const Canvas& orig);
    virtual ~Canvas();
    
    void addTexture(Texture* tex, double x, double y, int z, double scale, double rot);
private:
    
    

};

#endif /* CANVAS_H */

