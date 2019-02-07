//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Eduardo Martinez
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

llist::llist()
{
  /*- initialize Front and Rear to be NULL and Count = 0.
    - This does not create any node.  The new list is empty.
  */
  cout << "Contstructor" << endl;
  Front = NULL;//initialize front to NULL
  Rear = NULL;//initilize rear to NULL
  Count = 0;//initlize count to 0
}
llist::~llist()
{ 
  /*- while the list is not empty, call deleteFront repeatedly to delete all nodes.
    - Please place a cout in this function "calling the llist desctructor."
  */
  int OldNum;//recieve element that ar being deleted
  cout << "destructor" << endl;
  while(!isEmpty())//loop until list is empty
    deleteFront(OldNum);
}
//Purpose: to check if the list is empty
//parameters: If list is empty returns true, else returns false
//algorithm: checks conditions and returns ture or false
bool llist::isEmpty()
{
  /* - return true if Front and Rear are both pointing to NULL and Count is 0.
     - (all 3 conditions must be checked)
  */
  if(Front == NULL && Rear == NULL & Count == 0)//checks if emepty,
    return true;//returns true if empty
  else//returns false if  not empty
    return false;
}
//Purpose: displays all elements in the list within brackets
//algotithm: gooes through list and displays element 
void llist::displayAll()
{
  /*- Special case: if the list is empty, display [ empty ] ).
    - Regular: 
    displays each element of the list horizontally starting from Front in [ ].
  */
  cout << "[ ";
  if(isEmpty())//checks if empty
    cout << " the list is EMPTY ";
  else//if list is not mpty
    {
      Node* display;
      display = Front;
      for(int i=0; i< Count; i++)//loops through the list and displays lements
	{
	  cout << display->Elem << " ";
	  display = display->Next;
	}
    }  
  cout << "]";
}
//Purpose: adds all element to the front ogf the list
//Pararmeters: send element to be added to the rear of list
//algorithm: checks contions and depending ont the case add to rear 
void llist::addRear(el_t NewNum) 
{
  /*2 cases:
    - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
    - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
  */
  if (isEmpty())//if empty then its the first element in list
    {
      Front = Rear = new Node;//first node 
      Rear->Elem = NewNum;
      Count++;//update count
    }
  else
    {
      //Regular case:
      Rear->Next = new Node;
      Rear = Rear->Next;//new rear
      Rear->Elem = NewNum;//rear gets elemene
      Rear->Next = NULL;//Rear next point to NULL, the end of the list
      Count++;
    }

}

//Purpose: adds and element to the front of the list
//Parameters: send element to be added to the front of list
//algorithm: checsk condiont to detemerint he case and adds to front 
//depending on the case
void llist::addFront(el_t NewNum)
{
  /*2 cases:
    - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
    - Regular: add a new node to the front of the list and 
    Count is updated.
  */
  if(isEmpty())//if list is empty then its the first element 
    {
      Front =  new Node;//new node
      Rear = Front;//points to the same element
      Front->Elem = NewNum;
      Count++;
    }
  //Regular case:
  else
    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++; 
    }
}
//Purpose: to delete the front element of the list
//Parameters: provided a variable to recieve deleted
//by pass by reference
void llist::deleteFront(el_t& OldNum)
{
  /*3 cases:
    - Error case: if the List is empty, throw Underflow
    - Special case: if currently only one Node,
    give back the front node element through OldNum (pass by reference) and
    make sure both Front and Rear become NULL. Count is updated.
    - Regular: give back the front node element through OldNum (pass by reference)
    and also removes the front node.  Count is updated.
  */
  if (isEmpty())//if list empty cant removes 
                //so thro underflow excpetion
    {
      throw Underflow();
    }
  else if (Count == 1)//if count is one, then list will become empty
    {
      OldNum = Front->Elem;
      Front = NULL;//sets front to null
      Rear = NULL;//set rear to null
      Count--;
    }
    else
      {
	// Regular case:
	OldNum = Front->Elem;
	Node *Second;
	Second = Front->Next;
	delete Front;//deletes front
	Front = Second;//makes second new front
	Count--;
      }
}
//Purpose: to delete the rear element of the list
//Parameters: provided a variable to recieve deleted
//by pass by reference
//algorithm: checks and determines the case and deletes element from rear
void llist::deleteRear(el_t& OldNum)
{
  /* 3 cases:
     - Error case: if empty, throw Underflow
     - Special case: if currently only one node,
     give back the rear node element through OldNum (pass by reference) and
     make sure both Front and Rear become NULL. Count is updated.
     - Regular: give back the rear node element through OldNum (pass by reference)
     and also remove the rear node. Count is updated.
  */
  //Regular case:
  
  if (isEmpty())
    {
      throw Underflow();
    }
  else if (Count == 1)//only one element in list and will become empty
    {
      OldNum = Front->Elem;
      Front = NULL;//sets front to NUll
      Rear = NULL;//sets rear to NULL
      Count--;
    }
  else
    {

      OldNum = Rear->Elem;
      Node *p= Front;
 //Make p go to the one right before rear (using while)
      while(p->Next != Rear)
	{p=p->Next;}
      delete Rear;
      Rear = new Node;
      Rear = p;
      Count--;
    }
}
//Purpose: to delete the Ith element of the list
//Parameters: provided an interger for the Ith term in the list
// provided a variable to recieve deleted by pass by reference
void llist::deleteIth(int I, el_t& OldNum)
{
  /*4 cases:
    - Error case: 
    If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
    - Special cases: this should simply call deleteFront when I is 1 or 
    deleteRear when I is Count
    - Regular: delete the Ith node (I starts out at 1).  Count is updated.
    <see the template loops in the notes to move 2 pointers to the right nodes;
    and make sure you indicate the purposes of these local pointers>
  */
  
  if( I > Count || I < 1)//OUT OF RANGE
    {
      throw OutOfRange();
    }
  else if(I == 1)
    deleteFront(OldNum);//first element in list to be deleted
  else if(I == Count)
    deleteRear(OldNum);//last element in list to be deleted
  else
    {
      Node* q;//gets the Ith term
      Node* p;//set to front 
      p = Front;
      for(int k = 1; k <= I-1; k++)//find I-i term
	{p=p->Next;}
      OldNum = p->Next->Elem;
      q = p->Next;
      p->Next = p->Next->Next;
      delete q;
      Count--;
    }
}

//Purpose: to add an element before the Itht term in the list
//Parameters: provided interger for I,
//provided a variable to recieve deleted by pass by reference
void llist::addbeforeIth(int I, el_t newNum)
{
  /*4 cases:
    -  Error case:
    If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
    -  Special cases: this should simply call addFront when I is 1 or addRear when
    I is Count+1
    -  Regular: add right before the Ith node. Cout if updated.
    <see the template loops in the notes to move 2 pointers to the right nodes
    and make sure you indicate the purposes of these local pointers>
  */
  if( I > Count+1 || I < 1)//checks if out of range
    {
      throw OutOfRange();
    }
  else if(I == 1)//add to front
    addFront(newNum);
  else if(I == Count+1)//add to rear
    addRear(newNum);

  else
    {
      Node* q;
      Node* p;//to find the i-1 term
      q = new Node;
      p=Front;
      for(int k= 1; k<=I-1; k++)//finds the I-1 term
	{
	  p=p->Next;
	}
      q->Elem = newNum;
      q->Next = p->Next;
      p->Next = q;
      Count++;
    }
}
