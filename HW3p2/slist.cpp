// ====================================================
//HW#: HW3P2 slist
//Your name: Eduardo Martinez
//Complier:  g++
//File type: slist implementation file
//=====================================================
using namespace std;

#include<iostream>
#include"slist.h"

slist::slist()
{
  /*- initialize Front and Rear to be NULL and Count = 0.
    - This does not create any node.  The new list is empty.
  */

  cout << "Contstructor" << endl;
  Front = NULL;//initialize front to NULL
  Rear = NULL;//initilize rear to N
  Count = 0;//initlize count to 0
}
//Purpose: To search for an elem in list
//parameter: provide the element you want to search for
//in the list. If found the position will be returned, if not
//found 0 will be returned
//algorithm: 
int slist::search(el_t Key)
{
  Node* q;//for searching 
  int p = 1; //position counter
  q = Front;//q set to front

  for(int k = 1; k <= Count; k++)//loop through the whole list
    {
      if(q->Elem == Key)//if key is found
	return p;//returns position
      
      q=q->Next;//goes to the elem
      p++;//increment counter 
    }
  return 0;//if not found
  
}
//purpose: To replace the element of the Ith term will an element provided
//parameter: Provide element and position that wants to be replaced.
//algorithm: checks if position is in range, then a new node initliaized at
// front goes into a loop until I position. Element is replaced. 
void slist::replace(el_t Elem,int I)
{
  Node* p;//node used to find Ith position
  p = Front;//intialized to front

  if( I > Count || I < 1)//if out of range
    throw OutOfRange();//throw exception
  for(int k = 1; k <= I-1; k++)//loops until I-1 position
    p=p->Next;
  
  cout << p->Elem << " was replaced with ";
  p->Elem = Elem;//replaces the element
  cout << p->Elem << endl;
}
