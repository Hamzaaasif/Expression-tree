#include<iostream>
using namespace std;

class stack
{
  public:
  void push(char val,stack **top)
  {
    stack *ptr=new stack;
    ptr->value=val; 
        
    if(*top==NULL)
    {
      ptr->next=NULL;
      *top=ptr;
    } 
    else
    {
      ptr->next=*top;
      *top=ptr;
    }
  }

  char pop(stack **top)
  {
    if(*top==NULL)
    {
      return 'a';
    }
    else
    {
      stack *curr=*top;
      *top=curr->next;
      char temp=curr->value;
      curr=NULL;
      delete[]curr;
      return temp;
    }
  }
  char peak(stack *top)
  {
    if(top==NULL)
    {
      return 'a';
    }
    else
    {
      return top->value;
    }
  }

int priority(char operate)
{
  if(operate=='|')
  {
    return 1;
  }
  else if(operate=='&')
  {
    return 2;
  }
  else if(operate=='<' || operate=='>' || operate=='~' || operate=='=')
  {
    return 3;
  }
  else if(operate=='+' || operate=='-')
  {
    return 4;
  }
  else if(operate=='*' || operate=='/')
  {
    return 5;
  }
  else
  {
    return 0;
  }
}
  private:
  char value;
  stack *next;
};