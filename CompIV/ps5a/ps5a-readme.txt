Name: Chuong Vu
Login: Chuong_Vu@student.uml.edu

Hours to complete assignment (optional): 3 hours

I pretty much using header template that provided by Prof. Rykalova after
I read the assignment on the princeton.edu website and also I have watch
some video from Prof. Fred in prevous semester so it helped me have more
idea how to write a cyclic wrap around buffer.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

The problem first I got is I use the push_back in enqueue so after a certain
enqueue, I will get error because the size of vector keep growth and dequeue
can't delete in peek() so I got stuck at error where the size keep growth and
I can't use pop_back for dequeue

Later, I realize that I need to create cyclic-wrap around buffer it means that
the size and the capacity is fixed. The only thing is change is the first and last
index in the buffer so in the constructor method, I revserve the capacity and also
initial all element in the vector 0 so it will have fixed size with all 0 element.
And then keep follow the princeton.edu cation website with the test file that provide
by the Prof. Rykalova, fixed all the error.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


