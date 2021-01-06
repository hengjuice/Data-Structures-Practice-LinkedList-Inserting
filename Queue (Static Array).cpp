#include <iostream>
#define SIZE 5

using namespace std;

class Queue{
    private:
    int items[SIZE], front, rear;
    
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isFull();
    bool isEmpty();
    void enQueue(int element);
    void deQueue();
    void display();
    
};

bool Queue::isFull(){
    return (front == 0 && rear == SIZE - 1);
}

bool Queue::isEmpty(){
    return (front == -1);
}

void Queue::enQueue(int element){
    //if queue is full
    if(isFull()){
        cout<<"Queue is full\n";
        return;
    }
    //if queue is empty
    if(front == -1)
        front = 0;
    rear++;
    items[rear] = element;
    cout<<element<<" inserted into Queue\n";
}

void Queue::deQueue(){
    int element;
    //if queue is empty
    if(isEmpty()){
        cout<<"Queue is empty\n";
        return;
    }
    element = items[front];
    if(front>=rear)
        front=rear=-1;
    else
        front++;
        
    cout<<element<<" removed from Queue\n";
}

void Queue::display(){
    if(isEmpty())
        cout<<"Queue is empty\n";
    cout<<"Queue: \n";
    for(int i = front; i<=rear; i++){
        cout<<items[i]<<" ";
    }
    cout<<"\n";
}


int main() {
  Queue q;

  //deQueue is not possible on empty queue
  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6th element can't be added to because the queue is full
  q.enQueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.deQueue();

  //Now we have just 4 elements
  q.display();

  return 0;
}






