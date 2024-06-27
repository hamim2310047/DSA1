#include<iostream>
#include<string>
using namespace std;
string str;
int n=str.length();
char ch1[100], ch2[100], ch3[100];
int top1=-1,top2=-1, top3=-1;
void push(char item,char arr[], int &top){
    if (top>=n)
    {
        cout<<"OverFlow"<<endl;
    }
    top++;
    arr[top]=item;
}
int pop(char arr[], int &top){
    if (top==-1)
    {
        cout<<"Underflow"<<endl;
    }
    char y = arr[top];
    top--;
    return y;
}
int isValidparentheses(){
    for (int i = 0; i < n; i++)
    {
        if (str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            push(str[i],ch1,top1);
        }
        else
        {
            if ((ch1[top1]=='('&&str[i]==')')||(ch1[top1]=='{'&&str[i]=='}')||(ch1[top1]=='['&&str[i]==']'))
            {
                pop(ch1,top1);
            }
            else
            {
                return 0;
            }
        }
    }
    return 1 ;
}
int isPalindrome(){
        char ch4[100];
        for (int i = 0; i < n; i++)
        {
            if (str[i]>='0'&&str[i]<='9')
            {
                push(str[i],ch2,top2);
            }
        }
        int p=top2;
        for (int i = 0; i <=p ; i++)
        {
            ch4[i]=pop(ch2,top2);
        }
        for (int i = 0; i <= p; i++)
        {
            if (ch2[i]!=ch4[i])
            {
                return 0;
                break;
            }
        }
    return 1;
}
int isValidOperand(){
        for (int i = 0; i < n; i++)
        {
            push(str[i],ch3,top3);
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i]==')'||str[i]=='}'||str[i]==']')
            {
                char ch=ch3[top3-1];
                if (ch>='0'&&ch<='9')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    return 1;
}
int isNotEmpty(){
    int a=0;
    if(isValidparentheses()){
        for (int i = 0; i < n; i++)
        {
            if ((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
            {
                a=1;
            }
        }
    }
    return a;
}
int isValidExpression(){
    return isValidparentheses() /*&& isPalindrome() && isValidOperand()*/;
}
int main(){
    cin>>str;
    if (isValidExpression()==1)
    {
        cout<<"Valid"<<endl;
    }
    else
    {
        cout<<"Invalid"<<endl;
    }
    return 0;
}