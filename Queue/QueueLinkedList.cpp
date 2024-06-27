#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
};
node* front= NULL;
node* rear=NULL;
void enqueue(int item){
    node* temp= new node();
    temp->data=item;
    temp->next=NULL;
    if (rear==NULL)
    {
        front=rear=temp;
        return;
    }
    else
    {
        rear->next=temp; 
        rear=temp;
    }
}
int dequeue(){
    if (front==NULL)
    {
        cout<<"UnderFlow"<<endl;
        return -1;
    }
    node* temp=front;
    int y=temp->data;
    front=front->next;
    delete(temp);
    if (front == NULL) {
        rear = NULL;
    }
    return y;
}
int Front(){
    int y= front->data;
    return y;
}
int isEmpty(){
    if (front==NULL&& rear==NULL)
    {
        return 1;
    }
    return 0;
}
void printList(){
    node* cur= front;
    while (cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
}
int main(){
    enqueue(164);
    printList();
    enqueue(83);
    printList();
    dequeue();
    printList();
    enqueue(80);
    printList();
    enqueue(75);
    dequeue();
    printList();
    dequeue();
    printList();
    dequeue();
    printList();
    dequeue();
    return 0;
}