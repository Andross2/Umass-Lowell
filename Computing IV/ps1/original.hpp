//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Draw Squres
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: original.hpp
//-------------------------------

// Header files


#ifndef ORIGINAL_HPP_
#define ORIGINAL_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Original : public sf::Drawable {
    public:

        //top left right points and depth
        Original(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4, int depth);

        //side length and depth
        Original(int side, int depth);

        //destructor
        ~Original();

    private:
        void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Vector2f _point1, _point2, _point3, _point4;
        int _depth;

        Original* _child1;
        Original* _child2;
        Original* _child3;
        Original* _child4;
        Original* _child5;
};

#endif
