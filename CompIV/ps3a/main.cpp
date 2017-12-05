//-------------------------------
//Name: Chuong Vu
//Assigment ps3a - N-Body Simulation
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Filename: main.cpp
//-------------------------------

//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//  Prof. Yelena Rykalova
//
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "Body.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main(int argc, char const** argv) { 
    int wSize = 500;
    std::string input;
    int n, i;
    unsigned y;
    double uSize;
    
    //read integer to n
    getline(std::cin, input);
    n = (atoi(input.c_str()));
    
    //read double to universeSize
    getline(std::cin, input);
    uSize = (atof(input.c_str()));
    
    
    Body temp;
    temp.setWindowSize(wSize);
    temp.setUniverseSize(uSize);

    
    std::vector<Body> universe;
    
    //fill universe with n size
    for(i = 0; i < n; i++)
        universe.push_back(temp);
    
    //read value from text file to universe
    for(i = 0; i < n; i++)
    {
        getline(std::cin, input);
        std::istringstream iss(input); //get value between space from file
        iss >> universe[i];
        
    }
    sf::RenderWindow window(sf::VideoMode(wSize, wSize), "The Solar System!");
    
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        
        for(y = 0; y < universe.size(); y++)
        {
            window.draw(universe[y]);
        }
        window.display();
        
    }
    
    return EXIT_SUCCESS;
}
