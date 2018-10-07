#include<iostream>
using namespace std;
class BT
{
  public:
   BT* insert(char value)  //to convert char -> BT*
  {
   BT * temp=new BT;
   temp-> data = value;
   temp->leftchild=NULL;
   temp->rightchild=NULL;
   return temp;
  }
  char data;
  BT* leftchild;
  BT* rightchild;
};