#include <stdio.h>
#include<string.h>
#include<ctype.h>
//#include<conio.h>
#include<math.h>
#define STACK_SIZE 30

double compute (char symbol, double op1, double op2)
{
  switch(symbol)
	{
		case '+': return (op1 + op2);
		case '-': return (op1 - op2);
		case '*': return (op1 * op2);
		case '/': return (op1 / op2);
		case '$': 
		case '^': return pow(op1,op2);
	}
}


void main( )
{

 double s[STACK_SIZE], res , op1,op2;
 
 int top, i;

 char postfix[30], sym;

 //clrscr();

 printf("Enter a valid postfix expression\n");
 scanf("%s",postfix);

 top=-1;

 for(i=0; i< strlen(postfix); i++)
 {

  sym = postfix[i];

  if( isdigit(sym))
   {
	top=top+1;
	s[top] = sym -'0';  //48-> '0' , 49 to 57 for 1 to 9 res
   }
  else
   {
  	op2 = s[top--];
	op1 = s[top--];
	res = compute(sym,op1,op2);
	s[++top] = res;
   }

 }// end of for
 res = s[top];
 printf("The result of postfix expression is:%lf",res);
 
 //getch();
}
