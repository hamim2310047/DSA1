#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

node* input(node* head,int n){
    int value;
    struct node* temp=head;
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
node* reverseKthnode(struct node* head,int k){
    int count=0;
    struct node* cur=head;
    struct node* prev=NULL;
    struct node* next=NULL;
    while (count<k&&cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        count++;
    }
    if (head!=NULL)
    {
        head->next=cur;
    }
    count=0;
    while (count<k-1&&cur!=NULL)
    {
        cur=cur->next;
        count++;
    }
    if (cur!=NULL)
    {
        cur->next=reverseKthnode(cur->next,k);
    }
    
    /*if (next!=NULL)
    {
        head->next=reverseKthnode(next,k);
    }*/
    return prev;
}
void print (struct node* head){
    if(head==NULL)
        return ;
    struct node* cur=head;
    while (cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
}
int main(){
    struct node* head= (struct node*)malloc(sizeof(struct node));
    int n,k;
    cin>>n>>k;
    node* in=input(head,n);
    node* rev=reverseKthnode(in,k);
    print(rev);
    return 0;
}