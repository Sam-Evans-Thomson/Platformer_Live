/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphicsComponent.h
 * Author: sam
 *
 * Created on 3 February 2016, 1:10 PM
 */

#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H


class Graphic;
class PrimaryState;
class SecondaryState;
class Canvas;

class GraphicsComponent {
public:
    GraphicsComponent();
    GraphicsComponent(const GraphicsComponent& orig);
    ~GraphicsComponent();
    
    void render(double x, double y, int z, double scale, double rot);
    void renderBars();
    
    void updatePrimaryState(PrimaryState* ps);
    void updateSecondaryState(SecondaryState* ss);
    void updateGraphics();
    void exit();
    
private:
    
    ////// STACK 
    
    Graphic* playerGraphic; // this gets renderred.
    
    // these hold graphics
    Graphic* enterGraphic;
    Graphic* graphic;
    Graphic* exitGraphic;

};

#endif /* GRAPHICSCOMPONENT_H */

