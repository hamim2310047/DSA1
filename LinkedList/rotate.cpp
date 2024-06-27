#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

node* input(struct node* head, int n){
    int value;
    struct node* temp=head;
    for (int i = 0; i < n; i++)
    {
        cin>>value;
        temp->data=value;
        if (i<n-1)
        {
            temp->next=new node;
            temp=temp->next;
        }
    }
    temp->next=NULL;
    return head;
}

node* rotate(struct node* head,int k){
    struct node* cur=head;
    int i=1;
    while (i<k&&cur!=NULL)
    {
        cur=cur->next;
        i++;
    }
    struct node* temp=cur;
    while (cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
void print(struct node* head){
    if (head==NULL)
    {
        return;
    }
    struct node* cur=head;
    while (cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
}
int main(){
    int k,n;
    cin>>n>>k;
    struct node* head= (struct node*)malloc(sizeof(struct node));
    struct  node* in=input(head,n);
    struct node* new1=rotate(in,k);
    print(new1);
    return 0;
}