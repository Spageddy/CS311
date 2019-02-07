
// ====================================================
  //HW#: HW7 
  //Your name: Eduardo Martinez
  //Complier:  g++
  //File type: hw7p2 client file
  //=====================================================

// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.


#include <iostream>
#include "dgraph.h"
#include <string>
#include <stack>
int main()
{
  // 0.Declare table object
  dgraph d;
  int vNum=1;  //for visit number

  //1.fillTable()
  d.fillTable();//fills the table
  //2.displayGraph()
  d.displayGraph();
  cout << "*************************************" << endl;
 
  d.visit(vNum,'A');//mark a 
  stack <char> a;//stack
  stack <char> b;//display stack
  
  slist s = d.findAdjacency('A');//make a copy of adjacency list

  while(!s.isEmpty())//adds adjacency list to stack
    {
      char rTemp;
      s.deleteRear(rTemp);
      cout << endl;
      a.push(rTemp);
    }

  cout << "stack is: " << endl;
  
  b=a; //copy to display stack
  while(!b.empty())
    {
      char sTemp = b.top();
      b.pop();
      cout << sTemp << endl;
    }
  
  while(!a.empty())
    {   
      char Vname = a.top();
      a.pop();
      cout << "vertex : " << Vname << endl;
      if(!d.isMarked(Vname))//if not marked
	{
	  vNum++;//update vNum
	  d.visit(vNum,Vname);
	  s = d.findAdjacency(Vname);

	  while(!s.isEmpty())//adds adjacency list to stack
	    {
	      char rTemp;
	      s.deleteRear(rTemp);
	      cout << endl;
	      a.push(rTemp);
	    }
	}
	  cout << "stack is: " << endl;
	  
	   b=a; //copy to display stack
	   while(!b.empty())//display stack
	     {
	       char sTemp = b.top();
	       b.pop();
	       cout << sTemp << endl;
	     }
	   cout << "-------------------" << endl;
	
    }
  
  cout << "*******************************************" << endl;

  d.displayGraph();//display graph

return 0;
}
