//
//  MarkovModel.cpp
//  ps6
//
//  Created by ChuongVu on 11/12/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "MarkovModel.hpp"

using std::string;

// create a Markov model of order k from given text
// Assume that text has length at least k.
MarkovModel::MarkovModel(string text, int k) : _order(k), _init(text) {
    int i, j;
    srand(static_cast<unsigned int>(time(NULL)));

    // Collect characters for a list of the alphabet
    for (i = 0; i < static_cast<int>(text.size()); i++) {
        if (string::npos == _alphabet.find(text[i])) {
            _alphabet.push_back(text[i]);
        }
    }

    // Create a map of all the kgrams
    for (i = 0; i < static_cast<int>(text.size()); i++) {
        string temp1;
        string temp2;

        // Build up a string of k consecutive characters
        for (j = i; j < i + k; j++) {
            if (j >= static_cast<int>(text.size())) {
                temp1.push_back(text[j - text.size()]);
            } else {
                temp1.push_back(text[j]);
            }
        }
        // Put the occurance of the string into the kgram map
        if (_kgrams.end() == _kgrams.find(temp1)) {
            _kgrams[temp1] = 1;
        } else {
            _kgrams[temp1] += 1;
        }

        // Put in all possible k+1 strings (regardless of existence)
        for (j = 0; j < static_cast<int>(_alphabet.size()); j++) {
            if (_kgrams.end() == _kgrams.find(temp1 + _alphabet[j])) {
                _kgrams[temp1 + _alphabet[j]] = 0;
            }
        }

        // Build up a string of k+1 consecutive characters
        for (j = i; j < i + k + 1; j++) {
            if (j >= static_cast<int>(text.size())) {
                temp2.push_back(text[j - text.size()]);
            } else {
                temp2.push_back(text[j]);
            }
        }
        // Put the occurance of the string into the kgram map
        _kgrams[temp2] += 1;
    }
}

MarkovModel::~MarkovModel() { }

// order k of Markov model
int MarkovModel::order() {
    return _order;
}

// number of occurrences of kgram in text
// (throw an exception if kgram is not of length k)
int MarkovModel::freq(string kgram) {
    if (static_cast<int>(kgram.size()) != _order) {
        throw std::runtime_error("kgram is not size k");
    }

    if (_order == 0) {
        return static_cast<int>(_init.size());
    } else {
        return _kgrams[kgram];
    }
}

// number of times that character c follows kgram
// if order=0, return num of times char c appears
// (throw an exception if kgram is not of length k)
int MarkovModel::freq(string kgram, char c) {
    int i;

    if (static_cast<int>(kgram.size()) != _order) {
        throw std::runtime_error("kgram is not size k");
    }

    if (_order ==0) {
        int count = 0;
        for (i = 0; i < static_cast<int>(_init.size()); i++) {
            if (_init[i] == c) {
                count++;
            }
        }
        return count;
    } else {
        return  _kgrams[kgram + c];
    }

    return 0;
}

// random character following given kgram
// (Throw an exception if kgram is not of length k.
//  Throw an exception if no such kgram.)
char MarkovModel::randk(string kgram) {
    if (static_cast<int>(kgram.size()) != _order ||
        _kgrams.end() == _kgrams.find(kgram)) {
        throw std::runtime_error("Error: randk kgram not valid");
    }

    int i, j;
    string temp;

    for (i = 0; i < static_cast<int>(_alphabet.size()); i++) {
        for (j = 0; j < _kgrams[kgram + _alphabet[i]]; j++) {
            temp.push_back(_alphabet[i]);
        }
    }

    return temp[rand() % temp.size()];
}

// generate a string of length T characters
// by simulating a trajectory through the corresponding
// Markov chain.  The first k characters of the newly
// generated string should be the argument kgram.
// Throw an exception if kgram is not of length k.
// Assume that T is at least k.
string MarkovModel::gen(string kgram, int T) {
    string temp = kgram;
    string rValue = kgram;
    char c;
    int i;

    for (i = 0; i < T - _order; i++) {
        c = randk(temp);
        rValue.push_back(c);
        temp.erase(temp.begin());
        temp.push_back(c);
    }

    return rValue;
}

// overload the stream insertion operator and display
// the internal state of the Markov Model. Print out
// the order, the alphabet, and the frequencies of
// the k-grams and k+1-grams.
std::ostream& operator<<(std::ostream& os, MarkovModel& mm) {
    int i;
    os << "\n" << "Original: \"" << mm._init << "\"" << std::endl;
    os << "Order: " << mm._order << std::endl;
    os << "Alphabet: \"" << mm._alphabet << "\"" << "\n" << std::endl;

    os << "MarkovModel Map" << std::endl;
    std::map <string, int> temp = mm._kgrams;
    for (std::map<string, int>::iterator ma = temp.begin();
         ma != temp.end(); ++ma) {
        os << ma->first << " " << ma->second << " => ";
        for (i = 0; i < static_cast<int>(mm._alphabet.size()); i++) {
            ma++;
            os << ma->first << " " << ma->second << " ";
        }
        os << std::endl;
    }
    return os;
}
