//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: **
//Complier:  **
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.h"

//Purpose of the program: Keeps adding a, b, c to queue until queue is full
//Algorithm: a, b, c are added to queue, then removes from queue and adds, 
//a,b,c  until queue is full/
int main()
{ 
  queue abc;
  string removed;
  abc.add("a");//addd a, b, c to queue
  abc.add("b");
  abc.add("c");
 
   while(1>0)// loop -- indefinitely
     {
       try
	 {
	   //	   abc.displayAll();
	   abc.remove(removed);//removes from queue
	   cout << removed << endl; 
	   if(abc.isFull()) throw 1;// throws exception when queue is full
	   else 
	     abc.add((removed + "a"));//adds a
	   if(abc.isFull()) throw 1;// throws exception when queue is full
           else  
	     abc.add((removed + "b"));//adds b
	   if(abc.isFull()) throw 1;// throws exception when queue is full
           else  
	     abc.add((removed + "c"));//adds c
	   
	 }
     
   catch(int num)
     {
       cout << "cannot add" << endl;//error message
       exit(1);//ends program
     }
}
return 0;
}
	       
