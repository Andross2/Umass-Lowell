/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Chuong Vu


Hours to complete assignment (optional): 6 hours


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
100% sucessful because I was able to printout to the output file
exactly as the assignment require


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
At first I create a string that contain the regex expression

string sdate("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
// Time format
string stime("([0-9]{2}):([0-9]{2}):([0-9]{2})");
// boot start
string sboot("(.*log.c.166.*)");
// boot start success
string sdone("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

then I create a regex by join them together.

regex e_begin_boot(sdate + stime + sboot);
Out put will be:
 "([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ([0-9]{2}):([0-9]{2})(.*log.c.166.*)*"

So let break it down:
([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})  check date which in format YYYY-MM-DD
which is contain 4 number and '-' character between YYYY, MM and DD.
"(.*log.c.166.*)" : Look at the line if it contain 'log.c.166' and this is 
use to determind 'server started'

"(.*oejs.AbstractConnector:Started SelectChannelConnector.*)" : Same as 
log.c.166 and this use for determind the boot is successful

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

My method is just use if and a bool value to hold true false so it will
fall to these cases:
	1. Detect start state ==> Boot started
		set boot = true
	2. a) Detect complete boot ==> Boot completed
		Set boot = false (to back to loop)
	   b) Detect start state again ==> Incomplete boot
	
So all I do is ned to keep track the state of booting, and depend on the 
next boot state to determind is it a sucessful started or incomplete started.
And I write it to .rpt file.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Get help from Grinberg's lecture
https://echoess.uml.edu:8443/ess/echo/presentation/ae4b9ad0-e1f8-4f1b-8104-1a9e858094e8?ec=true


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A

