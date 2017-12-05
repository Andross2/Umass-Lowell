//-------------------------------
//Name: Chuong Vu
//Assigment ps3b - N-Body Simulation
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
#include <cmath>
#include <cstring>
#include "Body.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main(int argc, char const** argv)
{
    int wSize = 500;
    double G = 6.67e-11;    //Constant Gravitation
    std::string input;
    int n, i;
    double uSize, totalTime, stepTime, elapsedTime;
    
    if(argc < 3) {
        std::cout << "Missing command line args" << std::endl;
        return 1;
    } else if(argc > 3) {
        std::cout << "Too many command line args" << std::endl;
        return 1;
    }

    // Prepare time variables
    totalTime = atof(argv[1]);
    stepTime = atof(argv[2]);
    elapsedTime = 0.0;
    
    // Prepare the time text
    sf::Font courier_new;
    courier_new.loadFromFile("cour.ttf");

    sf::Text timeText("0.0", courier_new);
    
    // Prepare the image background
    sf::Image backgroundI;
    backgroundI.loadFromFile("starfield.jpg");
    
    sf::Texture backgroundT;
    backgroundT.loadFromImage(backgroundI);
    
    sf::Sprite backgroundP(backgroundT);
    
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
    for(i = 0; i < n; i++) {
        getline(std::cin, input);
        std::istringstream iss(input); //get value between space from file
        iss >> universe[i];
    }
    
    sf::RenderWindow window(sf::VideoMode(wSize, wSize), "The Solar System!");
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            
        }
        // Vector of Force, initialized to 0
        std::vector<double> forceX;
        std::vector<double> forceY;
        
        for(int i = 0; i < n; i++) {
            forceX.push_back(0.0);
            forceY.push_back(0.0);
        }
        
        // Calculate Acceleration
        for(unsigned i = 0; i < universe.size(); i++) {
            for(unsigned j = 0; j < universe.size(); j++) {
                if(i == j) {
                    forceX[i] += 0;
                    forceY[i] += 0;
                } else {
                    double deltaX = universe[j].getxPos() - universe[i].getxPos();
                    double deltaY = universe[j].getyPos() - universe[i].getyPos();
                    double r = sqrt(deltaX * deltaX + deltaY * deltaY);
                    double F = (G * universe[i].getMass() * universe[j].getMass()) / (r * r);
                    double Fx = F * (deltaX / r);
                    double Fy = F * (deltaY / r);
                    forceX[i] += Fx;
                    forceY[i] += Fy;
                }
            }
        }
        
        // Calculate New Velocity
        for(unsigned i = 0; i < universe.size(); i++) {
            double Ax = forceX[i] / universe[i].getMass();
            double Ay = forceY[i] / universe[i].getMass();
            
            universe[i].updateXVel(stepTime * Ax);
            universe[i].updateYVel(stepTime * Ay);
            
            // Update position
            universe[i].step(stepTime);
        }
        
        window.clear();
        
            window.draw(backgroundP);
        
            // Draw each body in the vector
            for(unsigned i = 0; i < universe.size(); i++)
                window.draw(universe[i]);
            
            // Update Time, close if max is reached
            elapsedTime += stepTime;
            if(elapsedTime > totalTime)
                window.close();
            
            // Update timeText
            std::stringstream ss;
            ss << elapsedTime;
            timeText.setString(ss.str());
            
            // Draw Current Time
            window.draw(timeText);
            
        window.display();
        
    }
        
    for(unsigned i = 0; i < universe.size(); i++)
        std::cout << universe[i] << std::endl;
        
    return EXIT_SUCCESS;
}
