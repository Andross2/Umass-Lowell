//test.cpp
#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

/*
six bit tap a three
010111  0
101110  1   
011100  2
111001  3  
110010  4 
*/
BOOST_AUTO_TEST_CASE(sixBitsTapAtThree) {

  LFSR l3("010111", 3);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);

  LFSR l4("010111", 3);
  BOOST_REQUIRE(l4.generate(4) == 2);
}


/*
Ten bits tap at six
1101010010  0
1010100100  1
0101001001  2
1010010011  3
0100100111  4
1001001110  5
0010011100  6
*/
BOOST_AUTO_TEST_CASE(tenBitsTapAtSix){

  LFSR l5("1101010010", 6);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 1);
  BOOST_REQUIRE(l5.step() == 1);
  BOOST_REQUIRE(l5.step() == 1);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 0);

  LFSR l6("1101010010", 6);
  BOOST_REQUIRE(l5.generate(4) == 1);
}


BOOST_AUTO_TEST_CASE(threeBitsTapAtOne){

  LFSR l5("000", 1);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 0);

  LFSR l6("000", 1);
  BOOST_REQUIRE(l5.generate(4) == 0);
}