/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vec2.h
 * Author: sam
 *
 * Created on 3 February 2016, 10:28 AM
 */

#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
    
    Vec2();
    Vec2(const Vec2& orig);
    
    Vec2(double x, double y);
    Vec2(float x, float y);
    Vec2(int x, int y);
    
    Vec2(double angle, double magnitude, bool b);
    
    void setX(double x);
    void setY(double y);
    
    double getX();
    double getY();
    
    Vec2 operator-() const;
    Vec2 operator+(const Vec2& v);
    Vec2 operator-(const Vec2& v);
    Vec2 operator*(const Vec2& v);
    Vec2 operator*(const double d);
    Vec2 operator/(const Vec2& v);
    Vec2 operator/(const double d);
    Vec2& operator+=(const Vec2& v);
    Vec2& operator-=(const Vec2& v);
    Vec2& operator*=(const Vec2& v);
    Vec2& operator*=(const double d);
    Vec2& operator/=(const Vec2& v);
    Vec2& operator/=(const double d);
    
    /* 
     *  Returns the length of the vector from (0,0) to (x,y);
     */
    double length();
    
    /* 
     *  Returns the angle of the vector from (0,0) to (x,y);
     *      The angle will be between -PI and PI;
     */
    double angle();
    
    /*
     *  Returns a Vec2 with the same angle as this and unit magnitude.
     */
    Vec2 normalize();
    
    /*
     *  Return a new Vec2 (y,x);
     */
    Vec2 invert();
    
    /*
     *  Returns a Vec2 with the same magnitude rotated 'angle' radians.
     */
    Vec2 rotate(double angle);
    
    /*
     *  Returns the dot product between this Vec2 and Vec2 'v'.
     */
    double dot(const Vec2& v) const;
    
    /*
     *  Returns the length of the Vec2 between this Vec2 and Vec2 'v'.
     */
    double length(const Vec2& v) const;
    
    /*
     *  Return the angle from this Vec2 to Vec2 'v'.
     */
    double angle(const Vec2& v) const;
    
    /*
     *  Returns a the resultant Vec2 from rotating this Vec2 'angle' radians
     *      about the Vec2 'v'.
     */
    Vec2 rotate(double angle, const Vec2& v) const;
    
    /*
     *  Returns a Vec2 that is the position of this Vec2 from the reference 
     * frame of 'v'.
     */
    Vec2 changeReference(double angle, const Vec2& v) const;
    
    virtual ~Vec2();
private:
    double x;
    double y;
};

#endif /* VEC2_H */


