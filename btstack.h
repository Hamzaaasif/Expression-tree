#include<iostream>
using namespace std;
#include"BT.h"
class btstack
{
  public:
  void push(BT* val,btstack **top)
  {
    btstack *ptr=new btstack;
    ptr->node=val; 
        
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
  BT* pop(btstack **top)
  {
    if(*top==NULL)
    {
      return NULL;
    }
    else
    {
      btstack *curr=*top;
      *top=curr->next;
      BT* temp=curr->node;
      //temp->data = curr->value;
      curr=NULL;
      delete[]curr;
      return temp;
    }
  }
  void print(BT *root)
  {
    if(root==NULL)
    {
      return;
    }
    cout<<root->data<< " ";
    print(root->leftchild);
    print(root->rightchild);
    
  }
  private:
  BT * node;
  btstack *next;

};