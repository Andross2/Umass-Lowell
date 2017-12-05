1;3201;0c/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name:Chuong Vu
Login: Chuong_Vu@student.uml.edu


Hours to complete assignment (optional): 3 hours



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/

I based on what professor went over in class how to get the alignment.
And also I use the idea from princeton to calculate the alignment. To
find the alignment itself, I check from the top-left to bottom-right. At
the top-left, if both letters is same, I will go diogonal, else, it will
check to find the smallest number from bottom-left to bottom-right and top-right.
Finally, it based on where it so it can either get penalty or gap and final
will calulate the edit distance. The method mostly come from priceton website

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: ./ED < ./sequence/endgaps7.txt

Expected output:
				Edit distance = 4
				a - 2
				t t 0
				a a 0
				t t 0
				t t 0
				a a 0
				t t 0

What happened: My output is same as the expected output.


/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/

I'm not really sure how many GB I have since I'm run on the Computer Science Server. 
But when I type command cat /proc/meminfo then I got 4GB from the command

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
N^2 is the matrix table, 4 is size of an integer in bytes.

a = 4
b = 2
largest N = ~44721

Calculate: 4 * N^2 = 8,000,000,000 ==> N = ~44721
==> 4 * 44721^2 = 7,999,871,364 just under 8GB of memory

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
Yes

cvu@cs3:~/Comp4/ps4$ valgrind --tool=massif ./ED < ./sequence/example10.txt
==30771== Massif, a heap profiler
==30771== Copyright (C) 2003-2013, and GNU GPL'd, by Nicholas Nethercote
==30771== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==30771== Command: ./ED
==30771==
Edit distance = 7
A T 1
A A 0
C - 2
A A 0
G G 0
T G 1
T T 0
A - 2
C C 0
C A 1

Execution time is 0.045136 seconds
==30771==


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		 118				0.452787		41.54	
ecoli5000.txt		 160				0.803106		161
ecoli7000.txt		 194				1.18509			225.8		
ecoli10000.txt		 223				4.28865			642.136
ecoli20000.txt		 3135				20.1217			2562.7
ecoli28284.txt		 Can't run... not enough memory


Fill out the data here first, then go to the assignment web page for
instructions on sharing your data on iSENSE.

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730


/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/

a = 0.00000002
b = 2
largest N = 3.972253768 x 10*7

Explain: if Total Time t = 0.00000002 * N^2, we can apply sqrt(t/0.00000002)
So the answer above is the calulation for 31557600 seconds in a day.

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

Princeton page only

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

Some how the vector.size() return the unsigned value to I have to cast
it to (int) so it wont have any problems when it subject.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

