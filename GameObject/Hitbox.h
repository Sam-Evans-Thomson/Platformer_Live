/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hitbox.h
 * Author: sam
 *
 * Created on 3 February 2016, 10:27 AM
 */


#ifndef HITBOX_H
#define HITBOX_H
        
#include "Vec2.h"
#include <vector>



#define PI 3.141592654

class Hitbox;
class HitboxCircle;
class HitboxLine;
class HitboxMulti;
class HitboxPoly;


class Hitbox {
public:
    
    Hitbox();
    Hitbox(double x, double y);
    Hitbox(Vec2 v);
    Hitbox(const Hitbox& orig);
    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////
    
    double getX();
    double getY();
    Vec2 getPos();
    void setX(double x);
    void setY(double y);
    void setPos(Vec2 _pos);
    
    
    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////    
    
    virtual void move(Vec2 v);
    virtual void move(double x, double y);
    virtual void scale(double scale);
    virtual void scaleX(double scale);
    virtual void scaleY(double scale);
    virtual void rotate(double rad);
    virtual void rotate(Vec2 orig, double rad);
    
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    virtual bool collision(Vec2& v) = 0;
    
    virtual bool collision(Hitbox& hb) = 0;
    virtual bool collision(HitboxLine& hbl) = 0;
    virtual bool collision(HitboxCircle& hbc) = 0;
    virtual bool collision(HitboxPoly& hbp) = 0;
    virtual bool collision(HitboxMulti& hbm) = 0;
    
    inline static bool collision(Hitbox& hba, Hitbox& hbb) { 
        return hba.collision(hbb); 
    }
    
    //_________________________________________________________//
    //////////////////// HELPER FUNCTIONS ///////////////////////
    
    /*
     *  Returns the angle in radians when given in degrees.
     */
    inline double rad(double deg);
    
    /*
     *  Return the angle in degrees when given in radians.
     */
    inline double deg(double rad);
    
    
    //_________________________________________________________//
    
    virtual ~Hitbox();
    
protected:
    
    Vec2 pos;
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    static bool collision_Circle_Circle( HitboxCircle& hbc, HitboxCircle& hbc2);
    static bool collision_Circle_Line(   HitboxCircle& hbc, HitboxLine&   hbl);
    static bool collision_Circle_Multi(  HitboxCircle& hbc, HitboxMulti&  hbm);
    static bool collision_Circle_Poly(   HitboxCircle& hbc, HitboxPoly&   hbp);
    static bool collision_Circle_Point(  HitboxCircle& hbc, Vec2&         p);
     
    static bool collision_Line_Line(     HitboxLine&   hbl, HitboxLine&   hbl2);
    static bool collision_Line_Multi(    HitboxLine&   hbl, HitboxMulti&  hbm);
    static bool collision_Line_Poly(     HitboxLine&   hbl, HitboxPoly&   hbp);
    static bool collision_Line_Point(    HitboxLine&   hbl, Vec2& p);
     
    static bool collision_Multi_Multi(   HitboxMulti&  hbm, HitboxMulti&  hbm2);
    static bool collision_Multi_Poly(    HitboxMulti&  hbm, HitboxPoly&   hbp);
    static bool collision_Multi_Point(   HitboxMulti&  hbm, Vec2&         p);
     
    static bool collision_Poly_Poly(     HitboxPoly&   hp,  HitboxPoly&   hbp2);
    static bool collision_Poly_Point(    HitboxPoly&   hp,  Vec2&         p);
    
private:
};



/*
 *  A HitboxCircle is a circular Hitbox. It will register a hit for any
 *      value inside the bounds of the circle.
 */
class HitboxCircle : public Hitbox {
public:
    
    typedef Hitbox super;
    
    HitboxCircle();
    HitboxCircle(Vec2 _pos, double rad);
    HitboxCircle(double x, double y, double rad);
    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////
    
    double getRadius();
    void setRadius(double rad);
    

    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////    
    void scale(double scale);
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    virtual bool collision(Vec2& p)           { return collision_Circle_Point( *this, p); }
    virtual bool collision(Hitbox& hb)        { return hb.collision(*this); }
    virtual bool collision(HitboxCircle& hbc) { return collision_Circle_Circle(*this, hbc); }
    virtual bool collision(HitboxLine& hbl)   { return collision_Circle_Line(  *this, hbl); }
    virtual bool collision(HitboxMulti& hbm)  { return collision_Circle_Multi( *this, hbm); }
    virtual bool collision(HitboxPoly& hbp)   { return collision_Circle_Poly(  *this, hbp); }
      
private:
    double radius;
};



/*
 *  A HitboxLine will register a hit anywhere on one side of the line 
 *      and nowhere on the other. The line extends to +- infinity.
 * 
 *      The line is defined with a Vec2 and an angle. For an pos Vec2 of
 *      (0,0) and an angle of 0 it will register a hit for any x-value
 *      more than 0;
 * 
 *      Angle is defined in radians.
 */
class HitboxLine : public Hitbox {
public:
    
    typedef Hitbox super;
    
    HitboxLine();
    HitboxLine(Vec2 _pos, double _angle);
    HitboxLine(Vec2 _pos1, Vec2 _pos2);
    HitboxLine(double x, double y, double _angle);
    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////
    
    double getAngle();
    double getAngleDeg();
    void   setAngle(double _angle);
    void   setAngleDeg(double _angle);
    
    
    //_________________________________________________________//
    //////////////////// ALTERATIONS         ////////////////////
    
    void move(double amount);
    void rotate(double _angle);
    void rotateDeg(double _angle);
    
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    virtual bool collision(Vec2& p)           { return collision_Line_Point(  *this, p); }
    virtual bool collision(Hitbox& hb)        { return hb.collision(*this); }
    virtual bool collision(HitboxCircle& hbc) { return collision_Circle_Line( hbc, *this); }
    virtual bool collision(HitboxLine& hbl)   { return collision_Line_Line(   *this, hbl); }
    virtual bool collision(HitboxMulti& hbm)  { return collision_Line_Multi(  *this, hbm); }
    virtual bool collision(HitboxPoly& hbp)   { return collision_Line_Poly(   *this, hbp); }
    
private:
    double angle;
};



/*
 *  The HitboxMulti is a container for one or more Hitboxes.
 *      A hit registered on any of the contained hitboxes will register
 *      as a hit for the HitboxMulti. This allows multiple hitboxes
 *      to be controlled as one and more complex shapes be made.
 */
class HitboxMulti : public Hitbox {
public:
    
    typedef Hitbox super;
    
    HitboxMulti();
    HitboxMulti(Hitbox* hbp);
    HitboxMulti(std::vector<Hitbox*> hitboxes);
    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////
    
    Hitbox* getHitbox(int i);
    std::vector<Hitbox*> getHitboxes(int i, int j);
    void setHitbox(int i, Hitbox* hbp);
    void setHitboxes(int i, int j, std::vector<Hitbox*> hitboxes);
    int getNumHitboxes();
    
    void addHitbox(Hitbox* hbp);
    void addHitboxes(std::vector<Hitbox*> hitboxes);
    void removeHitbox(Hitbox* hbp);
    void removeHitboxes(std::vector<Hitbox*> hitboxes);
    void removeHitbox(int i);
    void removeHitboxes(int i, int j);
    
    
    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////    
    
    void move(Vec2 v);
    void move(double x, double y);
    void moveHitbox(Hitbox* hbp, Vec2 v);
    void moveHitbox(Hitbox* hbp, double x, double y);
    void moveHitboxes(std::vector<Hitbox*> hitboxes, Vec2 v);
    void moveHitboxes(std::vector<Hitbox*> hitboxes, double x, double y);
    
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    virtual bool collision(Vec2& p)           { return collision_Multi_Point(  *this, p); }
    virtual bool collision(Hitbox& hb)        { return hb.collision(*this); }
    virtual bool collision(HitboxCircle& hbc) { return collision_Circle_Multi( hbc, *this); }
    virtual bool collision(HitboxLine& hbl)   { return collision_Line_Multi(   hbl, *this); }
    virtual bool collision(HitboxMulti& hbm)  { return collision_Multi_Multi(  *this, hbm); }
    virtual bool collision(HitboxPoly& hbp)   { return collision_Multi_Poly(   *this, hbp); }
    
private:
    int numHitboxes;
    std::vector<Hitbox*> hitboxes;
};



/*
 *  A HitboxPoly is a convex Polygon with each vertex define by a Vec2.
 * 
 *  It will register a hit for any value inside the bounds of the polygon.
 *  Its pos Vec2 will be it's first Vec2.
 */
class HitboxPoly : public Hitbox {
public:
    
    typedef Hitbox super;
    
    HitboxPoly();
    HitboxPoly(Vec2 v[], const int size);
    HitboxPoly(std::vector<Vec2*> vec2s);
    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

    HitboxLine* getLine(int i);
    void setLine(int i, HitboxLine hbl);
    void addLine(HitboxLine hbl);
    void addLines(HitboxLine hbls[], const int size);
    void removeLine(int i);
    void removeLines(int i, int j);
    int getNumSides();
    
    
    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////    
    
    void move(Vec2 v) override;
    void move(double x, double y) override;
    void moveLine(int i, double v);
    void moveLines(int i, int j, double v);
    void moveVertex(int i, Vec2 v);
    void moveVertex(int i, double x, double y);
    void moveVertexes(int i, int j, double x, double y);
    void moveVertexes(int i, int j, Vec2 v);
    
    void rotate(double angle);
    void scale(double scale);
    
    
    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////
    
    virtual bool collision(Vec2& p)           override { return collision_Poly_Point(  *this, p); }
    virtual bool collision(Hitbox& hb)        override { return hb.collision(*this); }
    virtual bool collision(HitboxCircle& hbc) override { return collision_Circle_Poly( hbc, *this); }
    virtual bool collision(HitboxLine& hbl)   override { return collision_Line_Poly(   hbl, *this); }
    virtual bool collision(HitboxMulti& hbm)  override { return collision_Multi_Poly(  hbm, *this); }
    virtual bool collision(HitboxPoly& hbp)   override { return collision_Poly_Poly(   *this, hbp); }
    
private: 
    
    /*
     * createHitboxLines uses the vec2s stored in 'vectors' to create a vector
     * or HitboxLines.
     */
    void createHitboxLines();
    
    int numSides;
    std::vector<HitboxLine> lines;
    std::vector<Vec2> vectors;
};
#endif /* HITBOX_H */

