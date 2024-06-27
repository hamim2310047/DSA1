#include<iostream>
using namespace std;
int n=3;
int front=-1,rear=-1;
int arr[10];
void enqueue(int item){
    if (front==-1&&rear==-1)
    {
        front++;
        rear++;
        arr[rear]=item;
    }
    else if ((rear+1)%n==front)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        rear = (rear+1)%n;
        arr[rear]=item;
    }
}
int dequeue(){
    int y;
    if (front==rear)
    {
        y=arr[front];
        front=-1;
        rear=-1;
    }
    else if (front==-1&&rear==-1)
    {
        cout<<"UnderFlow"<<endl;
    }
    else
    {
        y=arr[front];
        front=(front+1)%n;
    }
    return y;
}
int Front(){
    return arr[front];
}
int isEmpty(){
    if (front==-1&&rear==-1)
    {
        return 1;
    }
    return 0;
}
int isFULL(){
    if((rear+1)%n==front){
        return 1;
    }
    return 0;
}
void printArray(){
    if(front<=rear){
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
    else{
        for(int i=front;i<n;i++){
        cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    enqueue(164);
    printArray();
    enqueue(83);
    printArray();
    cout<<"front : "<<Front()<<endl;
    dequeue();
    printArray();
    enqueue(80);
    printArray();
    enqueue(75);
    dequeue();
    printArray();
    enqueue(75);
    cout<<"front : "<<Front()<<endl;
    return 0;
}