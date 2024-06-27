#include<iostream>
using namespace std;
int front=-1, rear=-1;
int n=3;
int arr[10];
void enqueue(int item){
    if (rear>=n-1)
    {
        cout<<"OverFlow"<<endl;
    }
    else
    {
       if (front==-1&&rear==-1)
       {
        front++;
        rear++;
        arr[rear]=item;
       }
       else
       {
        rear++;
        arr[rear]=item;
       }
    }
}
int dequeue(){
    if (front==-1&&rear==-1||front>rear)
    {
        cout<<"UnderFlow"<<endl;
    }
    else
    {
        int y= arr[front];
        front++;
        return y;
    }
}
int Front(){
    return arr[front];
}
int isEmpty(){
    if (front==-1&&rear==-1||front>rear)
    {
        return 1;
    }
    return 0;
}
void printArray(){
    for (int i = front; i <= rear; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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