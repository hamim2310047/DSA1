#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

node* input(struct node* head,int n){
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

node* reverse(struct node* head){
    struct node* prev=NULL;
    struct node* next=NULL;
    struct node* cur=head;
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}

void NthNode(struct node* head,int N){
    struct node* temp=head;
    int i=1;
    while (i<N && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    cout<<temp->data<<endl;
}

int main(){
    int n,N;
    cin>>n;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* in=input(head,n);
    struct node* rev=reverse(in);
    cin>>N;
    NthNode(rev,N);
    return 0;
}