//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Sierpinski's Triangle
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: sierpiniski.hpp
//-------------------------------

// Header file

#ifndef SIERPINSKI_HPP_
#define SIERPINSKI_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Sierpinski : public sf::Drawable {
	public:
    
		//top left right points and depth
		Sierpinski(sf::Vector2f top, sf::Vector2f left, sf::Vector2f right, int depth);
		
		//side length and depth
        Sierpinski(int side, int depth);
		
		//destructor
		~Sierpinski();

	private:
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
		sf::Vector2f _top, _left, _right;
		int _depth;
    
		Sierpinski* _child1;
		Sierpinski* _child2;
		Sierpinski* _child3;
};

#endif
