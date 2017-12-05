Name: Chuong Vu
Class: Computing IV
Professor: Dr. Yelena Rykalova
Assignment: ps2b

Based on the ps2a, I wrote a PhotoMagic.cpp for encode and decode image. Using png image for encode because it is 8-bits so it can be encode. The program using the same LFSR file from ps2a but I add more function to get picture encode. I note that the generate function from LFSR will determine the running time for encoding. The bigger bit shift, the slower the encode time run. So I set it to 9 is just enough to encode in a short.

For extra credit:
I note that every single character from a string is 6 bits string. So I take every single character from alphanumeric password and compare to the base64 if it is in there or not. If yes then I take that character and using bitset library to convert it to 6 bits binary then I join them together to get the final binary bits string for encode.