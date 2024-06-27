#include<iostream>
using namespace std;
int top=-1;
int arr[100],arr1[10];
int n;
void push(int item){
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
int pop(){
    if (top==-1)
    {
        cout<<"UnderFlow"<<endl;
    }
    int y= arr[top];
    top--;
    return y;
}
void reverse(){
    int arr2[100];
    for (int i = 0; i < n; i++)
    {
        push(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr2[i]=pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    reverse();
    return 0;
}