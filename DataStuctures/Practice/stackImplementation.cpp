#include<iostream>
using namespace std;
struct node{
int data;
struct node *next;
};
 struct node *top= NULL;

void push(int data){
node *new_node=new node;
new_node->data=data;
new_node->next= top;
top= new_node;
}

void displayList(){
cout<<"Display list"<<endl;
node *ptr= top;
while(ptr!=NULL)
{
cout<<ptr->data<<" ";
ptr=ptr->next;
}
cout<<endl;
}

 void pop(){
 top= top->next;
 }
 int main()
{
int x,ch;
cout << "LINKED LIST IMPLEMENTATION \n\n";
  do

    {
cout << "\n\n1.push 2.pop 3. DISPLAY \n";
cout<<"enter choice:";
 cin >> ch;
 switch (ch)
	{

	case 1:
	cout << "Enter the element to be pushed:: ";
	cin >> x;
	push(x);
	break;
	case 2:
        cout << "deleted";
	pop();
	break;

	case 3:
	displayList();
	break;

   }
    }
  while (ch < 4);

}
 
