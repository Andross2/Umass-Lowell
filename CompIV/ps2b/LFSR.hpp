/*
 * LFSR.hpp
 *
 *  Created on: Sun Mar  2 09:27:35 2014
 *  Author: Fred Martin, fredm@cs.uml.edu
 *  ed: Y. Rykalova fall 2016
 */
#ifndef _LFSR_H
#define _LFSR_H
#include <iostream>
#include <string>

class LFSR {
    public:
        LFSR(std::string seed, int tap);
        ~LFSR();
        int step();
        int generate(int k);
        friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);
  
    private:
        std::string _seed;		//string data
        int _tap;				//index location
};

#endif
