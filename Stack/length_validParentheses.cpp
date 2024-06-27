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
int VP_length(){
    int len=-1;
    int max_len=0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            push(str[i]);
        }
        else
        {
            if (top==-1)
            {
                len=i;
            }
            else
            {
                pop();
                if (top==-1)
                {
                    max_len=max(max_len, i-len);
                }
                else
                {
                    max_len=max(max_len, i-top);
                }
            }
        }
    }
    return max_len;
}
int main(){
    cout<<"input String: ";
    cin>>str;
    n=str.length();
    cout<<"Length of the valid parentheses: "<<VP_length()<<endl;
    return 0;
}