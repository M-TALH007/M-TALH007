#include <iostream>

using namespace std;
# define max 10

int stack[max];
int top = -1;
void push(int data){
   if(top== max-1)
   {
    cout<<"stack is full"<<endl;
   }
   else
     top= top+1;
     stack[top]= data;

}
int pop(){
    int data;
 if(top== -1)
   {
    cout<<"stack is empty"<<endl;
    exit(1);
   }
   else
    data = stack[top];
    top = top-1;
    return data;
}
void print (){
    if(top== -1)
   {
    cout<<"stack is empty"<<endl;
    return;
   }
   int i;
   for(i=0; i<=top; i++ ){
    cout<<"stack is "<< stack[i]<<endl;
   }
}

void push1(int data){

     top= top+1;
     for(int i= top; i>0;i--){
        stack[i]= stack[i-1];
     }
     stack[0]= data;

}
void print1 (){
    if(top== -1)
   {
    cout<<"stack is empty"<<endl;
    return;
   }
   int i;
   for(i=0; i<=top; i++ ){
    cout<<"element in stack  "<< stack[i]<<endl;
   }
}
int pop1(){
    int i;
    int val = stack[0];
    for(i=0; i<top; i++){
     stack[i]= stack[i+1];

    }
    top = top-1;
    return val;

}

/*int main()
{
    int data,val;
   push(1);
   push(2);
   push(3);
   print();
   data = pop();
   cout<<data<<endl;
   data = pop();
   cout<<data<<endl;
   print();
   push1(12);
   push1(100);
   push1(21);
   push1(21);
   push1(12);
   push1(114);
   push1(233);
   print1();
   val = pop1();
   cout<<"pop element from stack "<<val<<endl;
   val = pop1();
   cout<<"pop element from stack "<<val<<endl;
   val = pop1();
   cout<<"pop element from stack "<<val<<endl;
   print1();



    return 0;
}
*/
