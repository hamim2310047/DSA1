#include<iostream>
using namespace std;
int top=-1;
int arr[100];
int n;
void push(int item){
    if(top>=n-1){
        cout<<"Stack OverFlow"<<endl;
    }
    else
    {
        top++;
        arr[top]=item;
    } 
}
int isEmpty(){
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(){
    if (isEmpty())
    {
        cout<<"Stack underFLow"<<endl;
    }
    int x=arr[top];
    top--;
    return x;
}
int peek(){
    int y=arr[top];
    return y;
}
void display(){
    cout<<"Stack : ";
    for (int i = 0; i <= top; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"Araay Size: ";
    cin>>n;
    push(10);
    display();
    push(15);
    display();
    push(20);
    display();
    push(30);
    cout<<"peek value: "<<peek()<<endl;
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