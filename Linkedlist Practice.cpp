#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next; //Node pointer
};

//To add Node at the beginning of LinkedList
void appendFront(Node** head_ref, int new_data){
    Node* head = new Node();
    head -> data = new_data;
    head -> next = (*head_ref);
    (*head_ref) = head ;
}

//To add Node at the middle of LinkedList
void appendMiddle(Node* prev_node, int new_data){
    //check if previous node is empty
    if(prev_node == NULL){
        cout<<"The previous node cannot be NULL"<<endl;
        return;
    }
    Node* head = new Node();
    head -> data = new_data;
    head -> next = prev_node -> next;
    prev_node -> next = head;
    
}

//To add Node at the end of LinkedList
void appendEnd(Node** head_ref, int new_data){
    Node* head = new Node();
    Node* last = *head_ref;
    head -> data = new_data;
    
    //If empty list;
    if(*head_ref == NULL){
        *head_ref = head;
        return;
    }
    
    //Traverse through all the nodes
    while(last->next != NULL){
        last = last->next;
    }
    last->next = head;
    head->next = NULL;
}

void printList(Node* node){
    if (node == NULL){
        cout<<"Empty List"<<endl;
    }
    while(node != NULL){
        cout << node->data << endl;
        node = node->next;
    }
}

void deleteNode(Node** head_ref, int key){
    
    //store head Node
    Node* temp = *head_ref;
    Node* prev = NULL;
    
    //head node is key
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    //traverse through LinkedList
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    //if key not found in LinkedList
    if(temp == NULL){
        cout<<"key not found in linkedlist"<<endl;
    }
    //free memory
    prev->next = temp->next;
    delete temp;
    return;
}

void deleteNodePos(Node** head_ref, int position){
    //store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
    if(temp == NULL){
        cout<<"Linkedlist is empty"<<endl;
    }
    //if position is head
    if(position==1){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    
    for(int i = 0; i<position-1; i++){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            cout<<"No Node at that position"<<endl;
            break;
        }
    }
    prev->next = temp->next;
    delete temp;
    
}

void deleteList(Node** head_ref){
    Node* temp = *head_ref;
    Node* prev = NULL;
    while(temp!=NULL){
        prev = temp->next;
        delete temp;
        temp = prev;
    }
    *head_ref = NULL;
    cout<<"Linkedlist deleted"<<endl;
}

void lengthOfListIterative(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    cout<<"Length of Linkedlist: "<<length<<endl;
    return;
}

int lengthOfListRecursive(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1+lengthOfListRecursive(head->next);
}

bool search(Node *head, int key){
    Node* temp = head;
    
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int getNth(Node *head, int position){
    Node* temp = head;
    for(int i=0; i<position-1; i++){
        if(temp == NULL){
            return -1;
        }
        temp = temp->next;
    }
    return temp->data;
    
}

void printNthFromLast(Node *head, int position){
    Node* temp = head;
    Node* temp2 = head;
    int count = 0;
    while(temp!=NULL){
        count+=1; //length of linked list;
        temp = temp->next;
    }
    if(position>count){
        cout<<"Doesn't exist!"<<endl;
        return;
    }
    int key = count - position;
    for(int j=0; j<key; j++){
        temp2 = temp2->next;
    }
    cout<<"Nth from last: "<<temp2->data<<endl;
    return;
}

int main()
{
    Node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    appendEnd(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    appendFront(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    appendFront(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    appendEnd(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    appendMiddle(head->next, 8);  
      
    cout<<"Created Linked list is: "<<endl;  
    printList(head);  
    
    //deleteNode(&head, 4); 
    //puts("\nLinked List after Deletion of 1: ");
    //printList(head);
    
    //deleteNodePos(&head,1);
    //cout<<"Linked list after deletion at position 1"<<endl;
    //printList(head);
    
    //deleteList(&head);
    //printList(head);
    
    //lengthOfListIterative(head);
    //cout<< "Length of LinkedList: "<<lengthOfListRecursive(head)<<endl;
    
    //search(head, 8)? cout<<"Yes, it exists in LinkedList"<<endl: cout<<"No, it doesn't exist in LinkedList"<<endl;
    //search(head, 13)? cout<<"Yes, it exists in LinkedList"<<endl : cout<<"No, it doesn't exist in LinkedList"<<endl;
    //cout<<"Value at Position 3 is: "<<getNth(head,3)<<endl;
    
    printNthFromLast(head,5);
    return 0; 
}
