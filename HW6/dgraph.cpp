// ====================================================
//HW#: HW6 dgraph
//Your name: Eduardo Martinez
//Complier:  g++
//File type: dgraph implementation file
//=====================================================

using namespace std;
#include<iostream>
#include "dgraph.h"
#include <string>
#include<fstream>
// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

dgraph::dgraph()
{ 
  countUsed=0;//intialize count to 0 
  Gtable[countUsed].vertexName = ' ';// initaliaze vertex name to ''
  Gtable[countUsed].visit = 0;
}
dgraph::~dgraph()
{
}
//purpose: to fill gtable from "table.txt"
//algorithm: goes through the file and adds to gtable
void dgraph::fillTable()
{
// note that Gtable[i].adjacnentOnes is a slist, so you can use
//any slist function on it
//Hint on filltable::
//Set up fin stream to read from table.txt
  ifstream fin ("table.txt",ios::in);
  char x;
  while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
    {
      fin >> Gtable[countUsed].outDegree;
      // Then for the outDegree times do the following: (use a for-loop)
      for(int i = 0; i< Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x); 
	  // this uses a slist function from HW3
	}//end of for
      countUsed++;// increment the countUsed
    }//end of while
  fin.close();
}
//purpose: displays the table
//algorithm: goes through 
void dgraph::displayGraph()
{
//Hint on displaygraph::

//Make the following couts better with labels.
  for (int i = 0; i < countUsed; i++)//goes through gtable
    {  
      cout << "Vertex name:" <<  Gtable[i].vertexName << endl;
      cout << "out degree: " << Gtable[i].outDegree << endl;
      (Gtable[i].adjacentOnes).displayAll();//displays from slist
    }  
}
//Instruction on findOutDegree and findAdjacency::

//purpose: return out degree
//parameter: send a vertex name that want to search for
//           returns an integer
//algorithm: searchs for the vertex name, if found returns out degree
//           else vertex name is a bad vertex and exception is thrown
int dgraph::findOutDegree(char vName)
{
  for(int i= 0; i <= countUsed; i++)//searches for vertex name in gtable
    {
      if(Gtable[i].vertexName == vName)//if vertex name is found
	return Gtable[i].outDegree;//returns out degree
    }
  throw BadVertex();//exception thrown
}
//purpose: find  the adjancent nodes
//parameters: send a vertex name to search for
//            reurns slist
//algorithm: searchs for the vertex name in gtable, 
//           if found retursn slist else throws exception
slist dgraph:: findAdjacency(char vName)
{
  for(int i =0 ; i <= countUsed;i++)//used to search for vertex name
    {
      if(Gtable[i].vertexName == vName)//if vertex name is found
	return Gtable[i].adjacentOnes;//returns slist
    }
  throw BadVertex();//throws exception
}
//For this HW, you must use a loop.
  //Do not go through all the slots of the table
  //Just go through the used slots.

 

