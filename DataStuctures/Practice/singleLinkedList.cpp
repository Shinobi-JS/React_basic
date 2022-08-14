#include<iostream>
using namespace std;

struct node{

int data;
struct node *next;

}listNode;


int main(){
node head;
head.data = 100;
head.next = NULL;
node * ptr = new node;
node * ptrs = new node;
ptr->data = 500;
ptrs->data = 600;
ptr = ptrs;
delete ptrs;
cout<<ptr->data<<endl;
cout<<ptrs->data<<endl;


return 0;
}




