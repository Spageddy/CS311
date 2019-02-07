//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Eduardo Martinez
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: to calculate postfix expressions
//Algorithm: user enters expression, then expression goes through
// while loop and pushes onto the stack if the expression contains 
// integer, when expression contains an operator. then it pope two operands
// does operation. Then the result is pushed back onto the stack. if stack is not
// empty by the end of program the outputs error message.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result; // recieves result  

  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  if(item <=57 && item >= 48)	  //2.  if it is an operand (number), 
	    postfixstack.push((int)item-48);// push it (you might get Overflow exception)
	    
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      else if(item == '+') result = box1+box2;
	      else if (item == '*') result = box1*box2;// ** also do the + and * cases 
	      
	      postfixstack.push(result);// ** Finally push the result
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
    {
      cout << "overflow" << endl;
    }
  catch (stack::Underflow) // for too few operands
    {
      cout << "too few operands" << endl;
    }
  catch (char const* errorcode) // for invalid item
    {
      cout << "invalid item" << endl;
    }
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
// After the loop successfully completes: 
// The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(result);
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if(!postfixstack.isEmpty())
    cout << "incomplete expression" << endl;
  else
    cout << "The answer is: " << result << endl;
  
  return 0;
  
}// end of the program

