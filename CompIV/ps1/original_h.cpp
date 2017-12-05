//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Draw Squres
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: original_h.cpp
//-------------------------------
// Functions for header

#include "original.hpp"
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

Original::Original(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4, int depth): _point1 (point1), _point2 (point2), _point3 (point3), _point4 (point4), _depth (depth) { 
	int newdepth = _depth - 1;
    if (newdepth > 0){
        sf::Vector2f p1 = calmid(_point1, _point2);
        sf::Vector2f p2 = calmid(_point2, _point3);
        sf::Vector2f p3 = calmid(_point3, _point4);
        sf::Vector2f p4 = calmid(_point4, _point1);
        
        //draw 4 squares around it's own square if depth > 0 (recursive)
        _child1 = new Original(p1, p2, p3, p4, newdepth);
        _child2 = new Original(calmid(_point1, p1), calmid(p1, p4), calmid(p4, _point1), _point1, newdepth);
        _child3 = new Original(calmid(p1, _point2), _point2, calmid(_point2, p2), calmid(p1, p2), newdepth);
        _child4 = new Original(calmid(p2, _point3), _point3, calmid(_point3, p3), calmid(p2, p3), newdepth);
        _child5 = new Original(calmid(p3, _point4), _point4, calmid(_point4, p4), calmid(p3, p4), newdepth);
    } else {
        _child1 = NULL;  //point to null
        _child2 = NULL;
        _child3 = NULL;
        _child4 = NULL;
        _child5 = NULL;
    }
    
}

Original::Original(int side, int depth) : _depth (depth) {
    _point1 = sf::Vector2f(side / 2, 1);
    _point2 = sf::Vector2f(0, side / 2);
    _point3 = sf::Vector2f(side / 2, side);
    _point4 = sf::Vector2f(side, side / 2);
    
    int newdepth = _depth - 1;
    if (newdepth > 0){
        sf::Vector2f p1 = calmid(_point1, _point2);
        sf::Vector2f p2 = calmid(_point2, _point3);
        sf::Vector2f p3 = calmid(_point3, _point4);
        sf::Vector2f p4 = calmid(_point4, _point1);
        
        //draw 4 squares around it's own square
        _child1 = new Original(p1, p2, p3, p4, newdepth);
        _child2 = new Original(calmid(_point1, p1), calmid(p1, p4), calmid(p4, _point1), _point1, newdepth);
        _child3 = new Original(calmid(p1, _point2), _point2, calmid(_point2, p2), calmid(p1, p2), newdepth);
        _child4 = new Original(calmid(p2, _point3), _point3, calmid(_point3, p3), calmid(p2, p3), newdepth);
        _child5 = new Original(calmid(p3, _point4), _point4, calmid(_point4, p4), calmid(p3, p4), newdepth);
    } else {
        _child1 = NULL;  //point to null
        _child2 = NULL;
        _child3 = NULL;
        _child4 = NULL;
        _child5 = NULL;
    }
    
}

Original::~Original() {
    //std::cout <<"Delete destructor" << std::endl;
    delete(_child1);
    delete(_child2);
    delete(_child3);
    delete(_child4);
    delete(_child5);
}

void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(_depth == 1) {
        sf::ConvexShape square;
        square.setPointCount(4);
        square.setPoint(0, _point1);
        square.setPoint(1, _point2);
        square.setPoint(2, _point3);
        square.setPoint(3, _point4);
        square.setOutlineColor(randomcolor(_depth + 20));
        square.setOutlineThickness(2.0);
        target.draw(square, states);
    } else {
        sf::Vector2f p1 = calmid(_point1, _point2);
        sf::Vector2f p2 = calmid(_point2, _point3);
        sf::Vector2f p3 = calmid(_point3, _point4);
        sf::Vector2f p4 = calmid(_point4, _point1);
        
        sf::ConvexShape square;
        square.setPointCount(4);
        square.setPoint(0, p1);
        square.setPoint(1, p2);
        square.setPoint(2, p3);
        square.setPoint(3, p4);
        square.setOutlineColor(randomcolor(_depth));
        square.setOutlineThickness(4.0);
        target.draw(square, states);
    }
    
    //draw from function
    if(_child1 != NULL) {
        _child1->draw(target, states);
        _child2->draw(target, states);
        _child3->draw(target, states);
        _child4->draw(target, states);
        _child5->draw(target, states);
    }
}
