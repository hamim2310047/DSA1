#include<iostream>
#include<string.h>
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
    else
    {
        char c = ch[top];
        top--;
        return c;
    }
}
int isPalindrome(string S){
    string str2;
    for (int i = 0; i < n; i++)
    {
        push(S[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str2+=pop();
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (S[i]!=str2[i])
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    cin>>str;
    n=str.length();
    if (isPalindrome(str))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}