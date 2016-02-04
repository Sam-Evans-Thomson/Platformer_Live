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
class Player;
class PrimaryState;
class SecondaryState;
class Canvas;

class GraphicsComponent {
public:
    GraphicsComponent(Player* p);
    GraphicsComponent(const GraphicsComponent& orig);
    ~GraphicsComponent();
    
    void render(Canvas* canvas, double x, double y, int z, double scale, double rot);
    
    void updatePrimaryState(PrimaryState* ps);
    void updateSecondaryState(SecondaryState* ss);
    void updateGraphics();
    void exit();
    
private:
    // this gets renderred.
    Graphic* playerGraphic; 
    
    // these hold graphics
    Graphic* enterGraphic;
    Graphic* graphic;
    Graphic* exitGraphic;
    
    Player* p;

};

#endif /* GRAPHICSCOMPONENT_H */

