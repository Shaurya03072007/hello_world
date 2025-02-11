#include<iostream>
using namespace std;
class Node{
  public:
    Node* next,*prev;
    int data;
  public:
    Node(int value):next(nullptr),prev(nullptr),data(value){}
};
class dll{
  private:
    Node* head,*tail;
  public:
     dll():head(nullptr),tail(nullptr){}
     void insert(int value){
          Node* newnode=new Node(value);
          if(head==nullptr){
              head=newnode;
              tail=newnode;
              return;
          }
          tail->next=newnode;
          newnode->prev=tail;
          tail=newnode;
    }
    void display(){
          Node* temp1=head;
          Node* temp2=tail;
          while(temp1!=nullptr){
             cout<<temp1->data<<" ";
             temp1=temp1->next;
          }cout<<endl;
          while(temp2!=nullptr){
             cout<<temp2->data<<" ";
             temp2=temp2->prev;
          }cout<<endl;
    }
};
int main(){
    dll l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.display();
    return 0;
}