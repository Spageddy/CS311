/*
HW2P1
Name: Eduardo Martinez
Compiler Used: g++
File Type: Binary search program
 */
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int binarySearch(int L[],int x,int first,int last);
//purpose of the program: The prupose of the program is
// find poistion(number) that the user input number is in theordered array
//Algorithm/Design: starts with an array with an ordered list of integers
//then user inputs nummber that wants to be found, that number is then sent
// to binary search tree, where it compares the middle element of the list 
// with first and last, then if error was foun outputs error message else it
//outputs position 
int main()
{
  int myList[] ={1,3,5,7,9,11,13,15,17,19};
  int findthis;//item that being looked for
  
  int myfirst = 0;//first elemen
  int mylast = 9;//last element (n-1)
  cout << "what are you looking for?" << endl;
  cin >> findthis;//user input that wants to be found
  
  
  int resultloc = binarySearch(myList, findthis, myfirst, mylast);//gets position of number in list
  if(resultloc == -1)//catches error
    cout << "not found" << endl;//error message
    else    
      cout << "found in position " << resultloc+1 << endl;
  
  
  return 0;
}
int binarySearch(int L[],int x,int first,int last)
{
  
  int middle = (first+last)/2;//gets middle 
    cout << L[middle] << "<---mid" << endl;
  cout << first << "<-first| " << middle << "<-mid| " << last << "<-last" << endl;  
 
  if(x == L[middle]) return middle; //if found then returns middle
  else if (first == last)return -1;//if first = last then  returns -1, 
                                   //for error to be caught  
  else if(x < L[middle]) last = middle - 1;//if element is less than middle
                                           //then last is subracted by 1 
  else if(x > L[middle]) first = middle + 1;//if element is greater than middle 
                                            //then first is added by 1
  
  return binarySearch(L,x,first,last);//recursive call
}
