#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000

class Stack{
    int top;
    public:
        int a[MAX]; //Maximum Size of Stack
        
        //Constructor
        Stack(){top = -1;}
        
        //Methods
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    //if stack is full
    if(top >= MAX-1){
        cout<<"Stack is full"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        printf("Pushed %d into stack!\n", x);
        return true;
    }
}

int Stack::pop(){
    if(top<=-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top<=-1){
        cout<<"Stack is empty!"<<endl;
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

int main()
{
    Stack s;
    s.peek();
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    
    
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}





