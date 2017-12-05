Name: Chuong Vu
Class: Computing IV
Professor: Dr. Yelena Rykalova
Assignment: ps2a

Based on the header LFSR.hpp and test.cpp that provided by professor, my LFSR simply using an string input that represent as a binary string to _seed. Also, by following the instruction that from the link provide by professor Yelena (http://www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/lfsr.html)

I know that I have to get the value of tap position and the last position from string using XOR to get the new bit. And then I shift the current string bit to left by 1 and put the new bit to the end. So I will get a new bit string as a linear feedback shift register suppose to be.

Overall, the hardest think for this assignment is how to figure out how the generate function work. To calculate the return number from generate function, first I call the function step() as how many as I want to shift. And then I check if the step() function return 1 or 0, if it return 1, I will calculate the sum of step() that return 1 so I will get the value that generate() function return.

Test Case
1) I use the test case provide by the professor is 00111 with tap = 2 and shift 8 time. So the generate(8) return 198 which is no error.
2^7 + 2^6 + 2^2 + 2^1 = 198

2) I use another two test cases to make sure that my method is correct;
	a) 010111, tap = 3 and shift 4 times. The result is 2^1 = 2. True
	b) 1101010010, tap = 6 and shift 6 times. The result is 2^4 + 2^3 + 2^2 = 28. True
	c) 000, tap = 1. This is short seed strings and I execpt step return is 0 and generate = 0. True