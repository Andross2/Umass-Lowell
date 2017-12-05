/**********************************************************************
 *  readme.txt template                                                   
 *  PS7b: Kronos log parsing
 **********************************************************************/

Name: Chuong Vu


Hours to complete assignment (optional): 10 hours


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

100% sucessful because my file exactly as the sample file.

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

 *************
    string sstart("(.*Starting Service.)");
    string ssuccess("(.*Service started successfully.)");
    string sruntime("\\((.*)\\)");
	string slogging("(..Logging.*)");
This is for seaching start and successful start for each states in device
services. I pretty much explain through my code.

 *****************
    //  Softload start
    string softdate("(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)");
    string softdate1(".([0-9]{2}).");
    string softload(".*(SOFTLOADSERVICE.*)");
    string softstart("(.*Install started.*)");
    regex e_softload_start(softdate + softdate1 + stime + softload + softstart);

    //  Softload original
    string softori1("(.*removing intouch-application-base-)");
    string softori2("(.*)(.armv6jel_vfp.rpm.*)");
    regex e_soffser_orgi(softori1 + softori2);
    
    //  Softload newverion
    string softnew1("(.*Processing.[0-9]{1,2}.of.[0-9]{1,2}.)");
    string softnew2("(intouch-application-base-)(.*)(.armv6jel_vfp.rpm.*)");
    regex e_softload_new(softnew1 + softnew2);
    
    //  Softload done
    string softdone1("(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec).");
    string softdone2("([0-9]{2}).([0-9]{2}):([0-9]{2}):([0-9]{2})");
    string softdone3("(.*ExitValue from install command.*)");
    regex e_softload_done(softdone1 + softdone2 + softdone3);

    These regex is use for search the softload when it start, end and which
    version that the device is installed.

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

N/A

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

Getting the right regex is challenge since I need to make sure I get
the correct group to I can pass it to my class to make return a correct string
It took me like most of the time for do this assignment.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
