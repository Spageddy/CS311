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
  //- initialize Front and Rear to be NULL and Count = 0.
  //- This does not create any node.  The new list is empty.
  cout << "Contstructor" << endl;
  Front = NULL;//initialize front to NULL
  Rear = NULL;//initilize rear to N
  Count = 0;//initlize count to 0
}

			    
// Note that the Original is being passed to the constructor by reference
// to create a new object this-> as a copy of the Original
slist::slist(const slist& Original)
{
  //  this->'s data members need to be initialized first
  Front=NULL;
  Rear = NULL;
  Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  //  copy here the (**) lines in Operator Overloading of =.
  // this-> object has to be built up by allocating new cells (**)
  Node* P;  // local pointer for Originial
  P = Original.Front;
  while (P != NULL)  // This uses a loop which repeats until you reach the end of Original 
    {
      this->addRear(P->Elem);    //P.s element is added to this->
      P = P->Next;               // Go to the next node in Original   
    } 
//  Nothing to return.
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

// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference
slist& slist::operator=(const slist& OtherOne)
{
  el_t x;//to hold element from delete rear
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P.s element is added to this->
	  P = P->Next;               // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.
} 
