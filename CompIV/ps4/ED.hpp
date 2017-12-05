//
//  ED.hpp
//  ps4
//
//  Created by ChuongVu on 10/16/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//

#ifndef ED_hpp
#define ED_hpp

#include <iostream>
#include <cstring>
#include <vector>

class ED {
public:
    ED(std::string _stringX, std::string _stringY);
    int getEditDistance() const;
	std::string getEditString() const;
	void print() const;
	
private:
    // Input Variables
    std::string strX;
    std::string strY;
    
    // Constructed Variables
    std::vector< std::vector<int> > opt;    //2-d vector opt[i][j] for X and Y

    // Private Functions
    int OptDistance();
	int editDistance;	// value return distance opt[0][0]
    int penalty(char a, char b);
    int min(int a, int b, int c);
	
    std::string Alignment() const;
    std::string editStr;

    
};
#endif /* ED_hpp */
