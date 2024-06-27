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
void print(struct node* head){
    if (head==NULL)
    {
        return;
    }
    struct node* current= head;
    while(current!=NULL)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
}
node* Reverse(struct node* head){
    struct node* next=NULL;
    struct node* prev=NULL;
    struct node* cur=head;
    while (cur!=NULL)
    {
        next= cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}
int main(){
    int n;
    cin>>n;
    struct node* head= (struct node*)malloc(sizeof(struct node));
    struct node* in=input(head,n);
    struct node* rev=Reverse(in);
    print(rev);
    return 0;
}