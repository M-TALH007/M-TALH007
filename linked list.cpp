#include<iostream>
#include<stdlib.h>

/*
using namespace std;

 struct node {

     int data;
     struct node *link;
};

struct node* at_end(struct node *ptr,int data){
   struct node *temp =NULL;
   temp= (struct node *) malloc(sizeof(struct node));
   temp->data = data;
   temp->link = NULL;

   ptr->link= temp;
   return temp;
};

struct node* at_beg(struct node* &head,int data){
   struct node *temp =NULL;
   temp= (struct node *) malloc(sizeof(struct node));
   temp->data = data;
   temp->link = NULL;

   temp->link = head;
   head = temp;
   return head;


};
*/
/*int main(){
   struct node *head =NULL;
   head= (struct node *) malloc(sizeof(struct node));
   head->data = 45;
   head->link = NULL;


   struct node *ptr= head;

    ptr = at_end(ptr,2);
    ptr = at_end(ptr,3);
    ptr = at_end(ptr,4);
    head = at_beg(head,5);
    ptr = head;


   while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
   }
   return 0;
}
*/
