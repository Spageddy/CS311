// ====================================================
//HW#: HW7 dgraph
//Your name: Eduardo Martinez
//Complier:  g++
//File type: dgraph header file
//=====================================================

// ============ for the dgraph.h file =================================
// INSTRUCTION:
// You need to comment this file completely using the How to Comment file.
// You have seen many examples so far.
// We will check to see how well you have commented it.

// I am using hw3p3.h which is the most up to date slist.h
// You can change it to your "slist.h"

#include <iostream>
#include <string>
#include "hw3p3.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{

 private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

 public:

  class BadVertex {};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
  // Question: If we do not do this, will the llist destructor
  // be called automatically??? Try it.

  // read from the input file table.txt and fill GTable
  void fillTable();  

  // displays in an easy to read format 
  void displayGraph(); 

  // returns the out degree of a given vertex - may throw BadVertex
  int findOutDegree(char);  
  
  // returns the adjacency list of a given vertex - may throw BadVertexx
  slist findAdjacency(char);  

  //mark visit
  void visit(int,char);

  //returns false if not marked
  bool isMarked(char);
};




