#include<iostream>
using namespace std;
string str;
int top=-1;
int n;
char ch[100];
void push(char item){
    if (top>=n-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        top++;
        ch[top]=item;
    }
}
char pop(){
    if (top==-1)
    {
        cout<<"UnderFlow"<<endl;
    }
    char c = ch[top];
    top--;
    return c;
    
}
int isValid(){
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            push(str[i]);
        }
        else{
            if ((ch[top]=='('&&str[i]==')')||(ch[top]=='{'&&str[i]=='}')||(ch[top]=='['&&str[i]==']'))
            {
                pop();
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    cin>>str;
    n=str.length();
    if (isValid())
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}