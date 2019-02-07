// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.


#include <iostream>
#include "dgraph.h"
#include <string>


int main()
{
  // 0.Declare table object
  dgraph d;
  int option;
  
  //1.fillTable()
  d.fillTable();//fills the table
  //2.displayGraph()
  d.displayGraph();

  cout << "=========================================" << endl;
  cout << "Do you want to find the out degree" << endl;
  cout << "0: YES" << endl;
  cout << "1: NO" << endl;
  cin >> option;

  while (option == 0)
    {
      //  a.the user will specify which vertex     
      //b.findOutDegree of the vertex and display the result
      char vName;//for vertex name
      cout << "Enter vertex name: ";
      cin >> vName;
      cout << endl;
      try{
	int outD= d.findOutDegree(vName);
	cout <<" the out degree of " << vName << " is :" << outD <<endl;
      }
      catch(dgraph::BadVertex& e){
	cerr << "bad vertex" << endl;
      }//c.catch exception but do not exit
      cout << "=========================================" << endl;
      cout << "Do you want to  find another out degree?" << endl;
      cout << "0: YES" << endl;
      cout << "1: NO" << endl;
      cin >> option;
    }

  cout << "=========================================" << endl;
  cout << "Do you want to  find adjancency?" << endl;
  cout << "0: YES" << endl;
  cout << "1: NO" << endl;
  cin >> option;
  
  while (option == 0)
    {
      //a.the user will specify which vertex
      //b.findAdjacency of the vertex and display the result (see Hint)
      try{
	char vName;
	cout << "Enter vertex name: ";
	cin >> vName;
	cout << endl;
	d.findAdjacency(vName).displayAll();
      }
      catch(dgraph::BadVertex& e){
	cerr << "bad vertex" << endl;
      } //c.catch exception but do not exit

      cout << "=========================================" << endl;      
      cout << "Do you want to  find adjancency?" << endl;
      cout << "0: YES" << endl;
      cout << "1: NO" << endl;
      cin >> option;
    }
  return 0;
}
