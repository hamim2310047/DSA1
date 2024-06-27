#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

node* input(struct node* head,int n){
    struct node* temp=head;
    int value;
    for (int i = 0; i < n; i++)
    {
        cin>>value;
        temp->data=value;
        if (i<n-1)
        {
            temp->next= new node;
            temp=temp->next;
        }
    }
    temp->next=NULL;
    return head;
}
void Print(struct node* head){
    
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
void FindMiddle(struct node* head,int n){
    struct node* temp=head;
    for (int i = 0; i < n/2; i++)
    {
        temp=temp->next;
    }
    cout<<"Middle: "<<temp->data<<endl;
}
int main(){
    int n;
    cin>>n;
    struct node* head= (struct node*)malloc(sizeof(struct node));
    node* newNode=input(head,n);
    Print(newNode);
    FindMiddle(newNode,n);
    return 0;
}