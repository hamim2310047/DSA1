#include<iostream>
using namespace std;
int top=-1;
int n;
int arr[100];
string str;
void push(int item){
    if (top>=n-1)
    {
        cout<<"Overflow"<<endl;
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
    int c = arr[top];
    top--;
    return c;
}
void PostFix(){
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]>='0'&&str[i]<='9')
        {
            push(str[i]-'0');
        }
        else
        {
            int b=pop();
            int a=pop();
            if (str[i]=='*')
            {
                push(a*b);
            }
            else if (str[i]=='/')
            {
                if (b==0)
                {
                    return;
                }
                push(a/b);
            }
            else if (str[i]=='+')
            {
                push(a+b);
            }
            else if(str[i]=='-')
            {
                push(a-b);
            }
        }
    }
    cout<<"Result: "<<pop()<<endl;
}
int main(){
    cin>>str;
    n=str.length();
    PostFix();
    return 0;
}