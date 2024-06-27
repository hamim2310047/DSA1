#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
node* input(struct node* head,int n){
    int value;
    struct node* temp=head;
    for (int i = 0; i < n; i++)
    {
        cin>>value;
        temp->data= value;
        if(i<n-1){
            temp->next=new node;
            temp=temp->next;
        }
    }
    temp->next=NULL;
    return head;
}
node* insertFirst(struct node* head,struct node* item){
    if (head==NULL)
    {
        return item;
    }
    
    struct node* newitem= item;
    newitem->next=head;
    head=newitem;
    return head;
}
void print(struct node* head){
    if(head==NULL){
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
    int n;
    cin>>n;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* in = input(head,n);
    struct node* newitem=(struct node*)malloc(sizeof(struct node));
    int value;
    cin>>value;
    newitem->data=value;
    newitem->next=NULL;
    struct node* insert=insertFirst(in,newitem);
    print(insert);
    return 0;
}