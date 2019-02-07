
/*
HW2P2
Name: Eduardo Martinez
Compiler : g++
File Type: combine - client file 
*/

//purpose: to combine two sorted lists into one sorted list
//algorithm/design: user inputs two sorted listes, the two sorted
//lists are then sent by reference to combine. In combine the
//elemnets are compared and sorted int to another list. 

#include <iostream>
#include <vector>
using namespace std;


void combine(int size, vector<int>& A, vector<int>& B, vector<int>& R);

int main()
{

  vector<int> L1,L2,L3;//declare vector
  int Vsize;//decalre size of vector
  int el;// for element to be inserted in list

  cout << "how big do you want to make the list"  << endl;
  cin >> Vsize;// input from user

  
  for(int i= 0; i < Vsize; i++)//fills L1
    {
      cout << "element " << i+1 << ": ";
      cin >> el;
      L1.push_back(el);
    }
 
  cout << endl;
  
  for(int i= 0; i < Vsize; i++)//fills L2
    {
      cout << "element " << i+1 << ": ";
      cin >> el;
      L2.push_back(el);
    }


  combine(Vsize,L1,L2,L3);//sorts L1 and L2 into L3

  cout << "L3: ";

  for(int i= 0; i< L3.size();i++)//display the elements in L3
    {
      cout << L3[i] << " ";
    }

  cout << endl;

  return 0;
}

void combine(int size, vector<int>& A, vector<int>& B, vector<int>& R)
{
  
  while(!A.empty() && !B.empty())//leaves the loop once one vector is empty
    { 
      if(A.front() < B.front())//if front element of B is larger than
	                       //front element of A
	{
	  cout << "/comparison" << endl;
	  R.push_back(A.front());//pushes element to rear of R
	  A.erase( A.begin());//deletes front element of A
	}
      else// if front element of A is larger than front element of B
	{
	  cout << "comparison/" << endl;
	  R.push_back(B.front());//pushes element to the rear of R
	  B.erase( B.begin());//deletes front element of B
	}
    }
  
  while(!B.empty())// if elements are left in B,
                   // pushes element to rear of R
	{
	  R.push_back(B.front());
	  B.erase(B.begin());
	}
  
  {
    while(!A.empty())// if elements are left in A,
                     // pushes element to rear of R 
      {
	R.push_back(A.front());
	A.erase(A.begin());
	cout << R.back() << endl;
	
      }
  }
}

	  
      
