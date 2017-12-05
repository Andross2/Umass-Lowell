//
//  main.cpp
//  ps4
//
//  Created by ChuongVu on 10/16/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "ED.hpp"
#include <SFML/System.hpp>      //for time clock

int main(int argc, const char * argv[]) {

    sf::Clock clock;
    sf::Time t;
    
    std::string stringX;
    std::string stringY;
    
    std::cin >> stringX;
    std::cin >> stringY;
    

	ED DNA(stringX, stringY);
 
	// Get what we want from the class
	std::cout << "Edit distance = " << DNA.getEditDistance() << std::endl;
	std::cout << DNA.getEditString() << std::endl;
  	std::cout << "Edit distance = " << DNA.getEditDistance() << std::endl;
	
	
	t = clock.getElapsedTime();

	std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

    return 0;
}
