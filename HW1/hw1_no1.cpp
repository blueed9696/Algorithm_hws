#include <iostream>
#include <cstdlib>
using namespace std;
int length = 0;
// Define a node structure
struct Node{
    int data;
    Node* nextNode;
};

class LinkedList{
    private:
        Node* head; // Define head node

    public:
        LinkedList(){
            head = NULL;
        }

        // Define method to get head node
        Node* getHead(){
            return head;
        }

        //// Methods
        // Print linked list
        void printList(Node* temp);

        // Bubble Sort linked list
        Node* bubbleSort(Node* temp, int list_length);

        // Swap nodes from inside of bubble sort
        void swapNode(Node** previous, Node* node1, Node* node2);
        
        // Take input length and generate random numbers (5~100)
        Node* generateNode();
};

Node* LinkedList::generateNode(){
    cout << "Put input length (>=15) : " ;
    cin >> length;
    Node *head = NULL, *tail = NULL;

    // Generate first element
    if(head == NULL){
        Node* newNode = new Node;
        // Generate random  numbers
        // Offset = 5, Range = 100
        int rand_num = 5 + (rand() % 100);

        newNode->data = rand_num;
        head = newNode;
        tail = newNode;
    }

    // Generate other elements
    for(int i = 0; i < length - 1; i++){
        Node* newNode = new Node;
        int rand_num = 5 + (rand() % 100);
        // Insert it to linked list
        newNode->data = rand_num;
        tail->nextNode = newNode;
        tail = newNode;
    }
    
    return head;
}

void LinkedList::printList(Node* headNode){
    if(headNode != NULL){
        // Print data
        printf("%d " ,headNode->data);

        // Recursive funtion to traverse next elements
        printList(headNode->nextNode);
    }
}

Node* LinkedList::bubbleSort(Node* headNode, int list_length){
    int i;

    for(i = 0; i < list_length; i++){
        Node* current = headNode; 
        Node* previous = NULL;

        while(current->nextNode != NULL){   
            if(current->nextNode == NULL){
                break;
            }
            if(current->data > current->nextNode->data){
                swapNode(&previous, current, current->nextNode);
            }else{
                previous = current;
                current = current->nextNode;
            }
        }
    }

    return headNode;
    }

void LinkedList::swapNode(Node** previous, Node* node1, Node* node2){
    if(*previous == NULL){
        node1->nextNode = node2->nextNode;
        node2->nextNode = node1;
        *previous = node2;
        head = *previous;
    }else{
        (*previous)->nextNode = node2;
        node1->nextNode = node2->nextNode;
        node2->nextNode = node1;
        *previous = node2;
    }
}

int main(){
    // Create Linked List
    LinkedList linkedList;

    // Generate nodes and make as a linked list
    Node* linked_list = linkedList.generateNode();

    // Print linked list before sort
    linkedList.printList(linked_list);

    printf("\n");

    // Buble Sort Linked List
    linkedList.bubbleSort(linked_list, length);

    // Print linked list after sort
    linkedList.printList(linked_list);
}
