//
//  MarkovModel.hpp
//  ps6
//
//  Created by ChuongVu on 11/12/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//  Xcode
/*
* MarkovModel.hpp
* Copyright Fred Martin, fredm@cs.uml.edu
* Tue Apr  7 21:54:53 2015
*/

#ifndef MarkovModel_hpp
#define MarkovModel_hpp

#include <string>
#include <map>

using std::string;

class MarkovModel {
 public:
    MarkovModel(string text, int k);
    ~MarkovModel();
    int order();
    int freq(string kgram);
    int freq(string kgram, char c);
    char randk(string kgram);
    string gen(string kgram, int T);

    friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);

 private:
    int _order;
    std::map <string, int> _kgrams;  // must #include <map>
    string _alphabet;
    string _init;
};


#endif /* MarkovModel_hpp */
