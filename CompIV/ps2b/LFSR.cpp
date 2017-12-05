#include <cstdlib>
#include <sstream>	// std::ostringstream
#include <cmath>
#include "LFSR.hpp"


//default contructor of the class
LFSR::LFSR(std::string seed, int tap) : _seed(seed), _tap(tap)
{
}

LFSR::~LFSR()
{
}

//get return value, either 0 or 1
int LFSR::step()
{
	std::ostringstream _str;

	//Shiff the bit to left by 1
	unsigned i = 1;
	while(i < _seed.length())
	{
		_str << _seed[i];
		i++;
	}

	//XOR for the last bit after shift
	int bit = (_seed[0] - 48) ^ (_seed[_seed.length() - (_tap + 1)] - 48);
	
	//Add last bit to shifted bits
	_str << bit;
	
	//Store back shifted bits to _seed
	_seed = _str.str();
	
	//Return XOR bit, either 0 or 1
	return bit;
}

//get return value, either 0 or 1
//convert binary to decimal
int LFSR::generate(int k)
{
	int num = 0;
	int i = k - 1;
	while(i >= 0)
	{
		if(step() == 1)
			num += pow(2, i);
		i--;
	}
	//std::cout << num << std::endl;;
	return num;
}

//print the output
std::ostream& operator<< (std::ostream &out, LFSR &lfsr)
{
	out << lfsr._seed;
	return out;
}
