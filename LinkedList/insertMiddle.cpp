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
node* insertMiddle(struct node* head, struct node* item,int k){
    if (head== NULL)
    {
        return item;
    }
    struct node* current=head;
    int i=1;
    while (i<k&&current!=NULL)
    {
        current=current->next;
        i++;
    }
    item->next=current->next;
    current->next=item;
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
    int value,k;
    cin>>value>>k;
    newitem->data=value;
    newitem->next=NULL;
    head=insertMiddle(in,newitem,k);
    print(head);
    return 0;
}