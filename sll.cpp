#include<iostream>
using namespace std;
class Node{
   public:
    Node* next;
    int data;
   public:
     Node(int value):next(nullptr),data(value){}
};
class sll{
  private:
    Node* head;
  public:
    sll():head(nullptr){}
    void insert_end(int value){
       Node* newnode=new Node(value);
       if(head==nullptr){
           head=newnode;
           return;
       }
       Node* temp=head;
       while(temp->next!=nullptr)
         temp=temp->next;
       temp->next=newnode;
     }
     void insert_front(int value){
         Node* newnode=new Node(value);
         newnode->next=head;
         head=newnode;
     }
     void insert_at(int value,int pos){
       Node* newnode=new Node(value);
       Node* temp=head;
       int position=1;
       while(position!=pos-1 && temp->next!=nullptr){
            temp=temp->next;
            position+=1;
       }
       if(temp->next==nullptr){
            temp->next=newnode;
            return;
       }
       newnode->next=temp->next;
       temp->next=newnode;

     }
     void deleted(int key){
        if(head->data==key){
          head=head->next;
          return;
        }
        Node* temp=head;
        Node* prev=temp;
        while(temp!=nullptr && temp->data!=key){
           prev=temp;
           temp=temp->next;
        }
        if(temp==nullptr){
          cout<<key<<" not found in linkedlists"<<endl;
          return;
        }
        prev->next=temp->next;
     }
     void display(){
        Node* temp=head;
        while(temp!=nullptr){
          cout<<temp->data<<" ";
          temp=temp->next;
        }
        cout<<endl;
      }
      void reversed(){
        Node* temp=head;
        Node* reverse=nullptr;
        while(temp!=nullptr){
            Node* newnode=new Node(temp->data);
            newnode->next=reverse;
            reverse=newnode;
            temp=temp->next;
        }head=reverse;
       }
};
int main(){
     sll l;
     l.insert_end(1);
     l.insert_end(2);
     l.insert_end(3);
     l.insert_front(10);
     l.insert_end(4);
     l.insert_front(100);
     l.insert_at(69,3);
     l.deleted(69);
     l.display();
     l.reversed();
     l.display();
     return 0;
}