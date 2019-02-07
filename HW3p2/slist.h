// =======================================================
// HW#: HW3P2 slist
// Your name: Eduardo Martinez
// Compiler:  g++
// File type: headher file
//=======================================================
#include <iostream>
#include "llist.h"

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be integer

class slist: public llist
{
 public:
  slist();

  //Purpose: To search for an elem in list
  //parameter: provide the element you want to search for 
  //in the list. If found the position will be returned, if not 
  //found 0 will be returned
  int search(el_t Key);

  //purpose: To replace the element of the Ith term will an element provided
  //parameter: Provide element and position that wants to be replaced.
  void replace(el_t Elem,int I);
};
