#include<iostream>
#include<cstdio>
using namespace std;
#include"stack.h"
#include"btstack.h"

int main()
{
  stack s;
  stack *top=new stack;
  top=NULL;
  char prefix[]="a+b-c*d/e";
  char postfix[9];
  int i=0,j=0;
  //cout<<"Enter prefix expression (9 characters)"<<endl;
  //gets(prefix);
  while(i<9)
  {
    int prio1 = s.priority(prefix[i]);
    if(prio1 == 0)
    {
      postfix[j]=prefix[i];
      j++;
    }
    else if(prio1 > 0)
    {
      if(s.peak(top) == 'a')
      {
        s.push(prefix[i] , &top);
      }
      else
      {
        int prio2= s.priority(s.peak(top));
        if(prio2 >= prio1)
        {
          while(s.priority(s.peak(top)) >= prio1)
          {
            postfix[j]=s.pop(&top);
            j++;

          }
        }
         s.push(prefix[i] , &top);
      }
    }
    i++;
  }
 while(j<=i)
  {
    postfix[j]=s.pop(&top);
    j++;
  }
  cout<<"PostFix : ";
  for(i=0;i<9;i++)
  {
    cout<<postfix[i]<< " ";
  }
  BT *btpostfix[9];
  BT temp;
  for(i=0;i<9;i++)
  {
   btpostfix[i] = temp.insert(postfix[i]);
  }
  btstack temp1;
  btstack *toop=new btstack;
  toop=NULL;
  for(i=0;i<9;i++)
  {
    if(btpostfix[i]->data == 'a' || btpostfix[i]->data == 'b' || btpostfix[i]->data == 'c'|| btpostfix[i]->data == 'd'|| btpostfix[i]->data == 'e')
    {
      temp1.push(btpostfix[i] , &toop);
    }
    else
    {
    btpostfix[i]->leftchild = temp1.pop(&toop);
    btpostfix[i]->rightchild = temp1.pop(&toop);
    temp1.push(btpostfix[i],&toop);
    }
  }
  cout<<endl<<"Expression Tree : ";
  temp1.print(temp1.pop(&toop));

  cout<<endl<<endl;
  system("pause");
}