#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* top = NULL;

void push(int item){
    node* newnode= new node();
    newnode->data=item;
    newnode->next=top;
    top=newnode;
}
int pop(){
    node* temp = new node();
    if (top==NULL)
    {
        cout<<"UnderFLow"<<endl;
    }
    temp = top;
    int y = temp->data;
    top=top->next;
    delete(temp);
    return y;
}
int isEmpty(){
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek(){
    int y = top->data;
    return y;
}
void display(){
    node* cur=top;
    while (cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
}
int main(){
    push(10);
    display();
    push(15);
    display();
    push(20);
    display();
    cout<<"peek value"<<peek()<<endl;
    cout<<"deleted Item : "<<pop()<<endl;
    display();
    cout<<"Peeked Item : "<<peek()<<endl;
    push(25);
    display();
    cout<<"deleted Item : "<<pop()<<endl;
    cout<<"deleted Item : "<<pop()<<endl;
    cout<<"deleted Item : "<<pop()<<endl;
    pop();
    return 0;
}