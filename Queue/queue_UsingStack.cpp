#include<iostream>
using namespace std;
int top1=-1,top2=-1,n=3;
int arr1[10],arr2[10];
void push(int arr[],int &top,int item){
    if (top>=n-1)
    {
        cout<<"OverFlow"<<endl;
    }
    else
    {
        top++;
        arr[top]=item;
    }
}
int pop(int arr[],int &top){
    if (top==-1)
    {
        cout<<"UnderFLow"<<endl;
    }
    int y= arr[top];
    top--;
    return y;
}
void enqueue(int item){
    push(arr1,top1,item);
}
int dequeue(){
    if (top1==-1&&top2==-1)
    {
        cout<<"Empty"<<endl;
    }
    if (top2==-1)
    {
        while (top1!=-1)
        {
            int x= pop(arr1,top1);
            push(arr2,top2,x);
        }
    }
    return pop(arr2,top2);
}
void printQueue() {
    cout << "Queue: ";
    for (int i = 0; i <= top1; ++i) {
        cout << arr1[i] << " ";
    }
    for (int i = top2; i >= 0; --i) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}
int main(){
    enqueue(164);
    enqueue(83);
    printQueue();
    dequeue();
    printQueue();
    enqueue(80);
    printQueue();
    enqueue(75);
    dequeue();
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    return 0;
}