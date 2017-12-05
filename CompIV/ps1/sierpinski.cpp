//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Sierpinski's Triangle
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: sierpinski.cpp
//-------------------------------

// This is file to write functions for header


#include "sierpinski.hpp"
#include <iostream>
#include <cmath>

//Calucalte mid-point
sf::Vector2f calmid(sf::Vector2f start, sf::Vector2f end) {
    return sf::Vector2f((start.x + end.x) / 2, (start.y + end.y) /2);
}

//Generate sf::Color color
sf::Color randomcolor(int _depth) {
    return sf::Color((_depth * 110) % 255, (_depth * 200) % 255, (_depth * 20) % 255);
}

Sierpinski::Sierpinski(sf::Vector2f top, sf::Vector2f left, sf::Vector2f right, int depth) : _top (top), _left (left), _right (right), _depth (depth) {
    int newdepth = _depth - 1;
    
    if(newdepth > 0) {
        sf::Vector2f p1 = calmid(_top, _left);
        sf::Vector2f p2 = calmid(_right, _left);
        sf::Vector2f p3 = calmid(_top, _right);

        //create 3 triangles that around it's own triangles if depth > 0  (recursive)
        _child1 = new Sierpinski(_top, p1, p3, newdepth);
        _child2 = new Sierpinski(p1, _left, p2, newdepth);
        _child3 = new Sierpinski(p3, p2, _right, newdepth);
    } else {
        _child1 = NULL;  //point to null
        _child2 = NULL;  //point to null
        _child3 = NULL;  //point to null
    }
}

//calculate vector of triangle
Sierpinski::Sierpinski(int side, int depth) : _top (sf::Vector2f(side / 2, 0)), _depth (depth) {
    _top = sf::Vector2f(side / 2, 0);
    
    float height = 0.5 * sqrt(3.) * (float)side;
    
    _left = sf::Vector2f(0, height);
    _right = sf::Vector2f(side - 1, height);
    
    //the 3 childs in the triangles
    
    int newdepth = _depth - 1;
    
    if(newdepth > 0) {
     
        sf::Vector2f p1 = calmid(_top, _left);
        sf::Vector2f p2 = calmid(_right, _left);
        sf::Vector2f p3 = calmid(_top, _right);
        
        //create 3 triangles that around it's own triangles if depth > 0
        _child1 = new Sierpinski(_top, p1, p3, newdepth);
        _child2 = new Sierpinski(p1, _left, p2, newdepth);
        _child3 = new Sierpinski(p3, p2, _right, newdepth);
    } else {
        _child1 = NULL;  //point to null
        _child2 = NULL;  //point to null
        _child3 = NULL;  //point to null
    }
}

Sierpinski::~Sierpinski() {
    //std::cout << "Delete Destructor" << std::endl;
    delete(_child1);
    delete(_child2);
    delete(_child3);
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    if(_depth == 1) {
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, _top);
        triangle.setPoint(1, _left);
        triangle.setPoint(2, _right);
        triangle.setFillColor(randomcolor(_depth+190));
        target.draw(triangle, states);
    } else {
        sf::Vector2f p1 = calmid(_top, _left);
        sf::Vector2f p2 = calmid(_right, _left);
        sf::Vector2f p3 = calmid(_top, _right);
        
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, p1);
        triangle.setPoint(1, p2);
        triangle.setPoint(2, p3);
        triangle.setFillColor(randomcolor(_depth));
        target.draw(triangle, states);
    }
    
    //draw triangles
    if(_child1 != NULL) {
        _child1->draw(target, states);
        _child2->draw(target, states);
        _child3->draw(target, states);
    }
}
