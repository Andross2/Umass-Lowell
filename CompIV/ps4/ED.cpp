//
//  ED.cpp
//  ps4
//
//  Created by ChuongVu on 10/16/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include "ED.hpp"


ED::ED(std::string _stringX, std::string _stringY) : strX(_stringX), strY(_stringY)
{
    //create a temp vector
    std::vector<int> temp;
    
    //fill matrix table with value 0
    for(int i = 0; i < static_cast<int>(strY.length()) + 1; i++)
        temp.push_back(0);
    for(int i = 0; i < static_cast<int>(strX.length()) + 1; i++)
        opt.push_back(temp);
    
	//Call optDistance to calculate the matrix values
	editDistance = OptDistance();	
	editStr = Alignment();
	//print();
	
}


//Fill matrix table
int ED::OptDistance()
{
	//fill from bottom right to left and upper
	
	for(int i = opt.size() - 1; i >= 0; i--)
	{
		for(int j = opt[i].size() - 1; j >= 0; j--)
		{
			if((i == static_cast<int>(opt.size() - 1)) && (j == static_cast<int>(opt[i].size() - 1)))
				opt[i][j] = 0;					//base case
			else if(i == static_cast<int>(opt.size() - 1))
				opt[i][j] = opt[i][j + 1] + 2;	//Y col + grap
			else if (j == static_cast<int>(opt[i].size() - 1))
				opt[i][j] = opt[i + 1][j] + 2;	//Y col + grap
			else
				opt[i][j] = min(static_cast<int>(opt[i+1][j+1] + penalty(strX[i], strY[j])), static_cast<int>(opt[i + 1][j] + 2), static_cast<int>(opt[i][j + 1] + 2));
		}
	}
	
	//Get Edit Distance value
	return opt[0][0];

}

//get penalty
int ED::penalty(char a, char b)
{
	return a == b ? 0 : 1;
}

//Get min value
int ED::min(int a, int b, int c)
{
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}


std::string ED::Alignment() const
{
	int i = 0, j = 0;
	std::stringstream ss;

	while(i < static_cast<int>(opt.size() - 1) || j < static_cast<int>(opt[0].size() - 1))
	{
		if((i < static_cast<int>(opt.size() - 1)) && (j < static_cast<int>(opt[0].size() - 1)) && (opt[i+1][j+1] <= opt[i+1][j] + 1) && (opt[i+1][j+1] <= opt[i][j+1] + 1))
		{
			ss << strX[i] << " " << strY[j] << " " << opt[i][j] - opt[i+1][j+1] << '\n';
			i++;
			j++;
		} 
		else if(((i < static_cast<int>(opt.size() - 1)) && (opt[i+1][j] <= opt[i][j+1])) || (j == static_cast<int>(opt[0].size() - 1))) 
		{
			ss << strX[i] << " " << "-" << " " << opt[i][j] - opt[i+1][j] << '\n';
			i++;
		} 
		else
		{
			ss << "-" << " " << strY[j] << " " << opt[i][j] - opt[i][j+1] << '\n';
			j++;
		}
	} 
  
	return ss.str();
}


int ED::getEditDistance() const {
	return editDistance;
}

std::string ED::getEditString() const {
	return editStr;
}


void ED::print() const
{
	//print table test
    for(unsigned i = 0; i < opt.size(); i ++)
    {
        for(unsigned j = 0; j < opt[i].size(); j++)
        {
            std::cout << "\t" << opt[i][j];
        }
		std::cout << std::endl;
    }
}


