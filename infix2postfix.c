#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_SIZE 30

char infix[30], postfix[30];//global declaration

int SP(char symbol) //stack precedence values
{   switch(symbol)
     {
       case '+':
       case '-': return 2;

       case '*':
       case '/':  return 4;

       case '^':
       case '$':  return 5;

       case '(':  return 0;

       case '#':  return -1;

       default:   return 8;
     }
}

int IP(char symbol) //input precedence of infix string
 {
  switch(symbol)
  {
       case '+':
       case '-': return 1;

       case '*':
       case '/': return 3;

       case '^':
       case '$': return 6;

       case '(':  return 9;

       case ')': return 0;

       default:   return 7;
   }
}

void infix_to_postfix()
{
int top, i, j;
char s[STACK_SIZE],symbol;

//prerequisits
top = -1;
s[++top] = '#'; // starting of the conversion 
j = 0;

for(i=0;i<strlen(infix);i++)         //scan for all symbols from input string
{
   symbol = infix[i];
   while( SP( s[top] ) > IP( symbol ) )  // stack precedence is greater, pop out
                                       // & place into postfix
    {
      postfix[ j ] = s[top--];
      j++;
    }

   if( SP( s[ top ] ) != IP( symbol ) )   // stack precendence is unequal
					  // push the input symbol to stack
        s[++top] = symbol;
   else  
        top--;                      //discard  '(' from stack

}//end of for


while ( s[top] != '#')      //pop out remaining symbols & place it into postfix
{
 postfix[ j++ ] = s[top--];
}

postfix[ j ] ='\0';       //NULL to make end of postfix

}//end of infix_postfix()

void main( )
{
  printf("Enter a valid infix expression\n");
  scanf("%s",infix);

  infix_to_postfix(); // function call

  printf("The postfix expression is:\n");
  printf("%s",postfix);
  
}
