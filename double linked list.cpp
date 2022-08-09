#include<iostream>
#include<stdlib.h>


using namespace std;

 struct node {

     int data;
     struct node* pre;
     struct node* next;
};

struct node* atempty(struct node* head,int data){

   struct node* temp = (struct node*) malloc(sizeof(struct node));
   temp->pre= NULL;
   temp->data= data;
   temp->next=NULL;

    head = temp;
    return head;
};

struct node* at_beg(struct node* head,int data){

   struct node* temp = (struct node*) malloc(sizeof(struct node));
   temp->pre= NULL;
   temp->data= data;
   temp->next=NULL;
    temp->next=head;
    head->pre= temp;
    head = temp;
    return head;
};

struct node* at_end(struct node* head,int data){
   struct node* temp;
   struct node* tp;
   temp = (struct node*) malloc(sizeof(struct node));
   temp->pre= NULL;
   temp->data= data;
   temp->next=NULL;
   tp = head;
   while(tp->next!=NULL){
    tp=tp->next;
   }
   tp->next= temp;
   temp->pre= tp;
    return head;
};

struct node* create(struct node* head){
  int i; int n; int data;
  cout<<"enter the integer number do u want and this integer number is create nodes :";
  cin >> n ;
  cout<<"so want to create "<<n<<" nodes"<<endl;
  for(i=1;i<=n;i++){
    cout<<"enter the data of "<<i<<" node"<<endl;
    cin>>data;
    head = at_end(head,data);
  }
  return head;
}
struct node* delF(struct node* head){
  struct node* temp= head;
  head= head->next;
  temp=NULL;
  free(temp);
  head->pre=NULL;
  return head;
};
struct node* delL(struct node* head){
  struct node* temp= head;
   struct node* temp2;
   while(temp->next!=NULL){
    temp=temp->next;
   }
  temp2 = temp->pre;
  temp2->next=NULL;
  temp=NULL;
  free(temp);
  return head;
};
void print(struct node* head){
    struct node* ptr = head;
         while(ptr!=NULL){
     cout<<ptr->data<<endl;
     ptr=ptr->next;
   }
}

int main(){
     struct node* head= NULL;
     struct node* ptr;
     head=atempty(head,4);
     //head= create(head);
      head = at_beg(head,33);
      head = at_beg(head,22);
      head = at_beg(head,11);
      head = at_beg(head,12);
      head = at_end(head,12);
      head= at_end(head,5);
     cout<<"my linked list is "<<endl;
     print(head);
     cout<<"after deletion of first node my list is"<<endl;
     head= delF(head);
     print(head);
     cout<<"and after delete the end node in the linked "<<endl;
     head = delL(head);
     print(head);
return 0;
}

