//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Eduardo Martinez
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: to check if the list is empty
  //parameters: If list is empty returns true, else returns false
  bool isEmpty();
    
  //Purpose: displays all elements in the list within brackets
  void displayAll();

  //Purpose: adds and element to the front of the list
  //Parameters: send element to be added to the front of list
  void addFront(el_t);
   
  //Purpose: adds all element to the front ogf the list 
  //Pararmeters: send element to be added to the rear of list
  void addRear(el_t);

  //Purpose: to delete the front element of the list
  //Parameters: provided a variable to recieve deleted 
  //by pass by reference
  void deleteFront(el_t&);
    
  //Purpose: to delete the rear element of the list
  //Parameters: provided a variable to recieve deleted
  //by pass by reference
  void deleteRear(el_t&);
    
  //Purpose: to delete the Ith element of the list
  //Parameters: provided an interger for the Ith term in the list
  // provided a variable to recieve deleted by pass by reference
  void deleteIth(int, el_t&);

  //Purpose: to add an element before the Itht term in the list
  //Parameters: provided interger for I, 
  //provided a variable to recieve deleted by pass by reference
  void addbeforeIth(int, el_t);
    
};
