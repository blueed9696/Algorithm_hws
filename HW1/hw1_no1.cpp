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

        Node* generateNode();

        //// Methods
        // Input : integer data
        // Output : x
        // Create head node
        void addHeadNode(int n);

        // Input : Node structure, integer data
        // Output : x
        // Insert Node before the reference node
        void insertBefore(Node* temp, Node* refNode, int n);

        // Input : Node structure, integer data
        // Output : x
        // Insert Node after the reference node
        void insertAfter(Node* temp, Node* refNode, int n);

        // Input : Node, deleting value
        // Output : x
        // Delete Node that has value 'n' and link prev 'n' Node with after 'n' Node
        void deleteNode(Node* temp, int n);

        // Input : head Node
        // Output : x
        // Print linked list
        void printList(Node* temp);

        Node* bubbleSort(Node* temp, int list_length);

        void swapNode(Node** previous, Node* node1, Node* node2);
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

// void LinkedList::addHeadNode(int n){
//     // Create new node
//     Node* temp = new Node;

//     // Put n to new node's data
//     temp -> data = n;

//     // Check if head is empty
//     if(head == NULL){
//         head = temp; // If head is empty make temp as a head
//     }else{
//         // assign temp's next node address to current head node
//         temp -> nextNode = head;
//         // new node takes head node address
//         head = temp;
//     }
// }

// void LinkedList::insertBefore(Node* temp, Node* refNode,int n){
//     // Create inserting node
//     Node* newNode = new Node;

//     // Put n to new node's data
//     newNode -> data = n;

//     // When the first component is the reference node
//     if(temp == refNode){
//         newNode->nextNode = temp;
//         head = newNode;
//     }

//     // Traverse list until temp = reference
//     while(temp->nextNode != refNode){
//         temp = temp->nextNode;
//     }

//     // Put new node before reference node
//     newNode->nextNode = temp->nextNode;
//     temp->nextNode = newNode; 

// }

void LinkedList::printList(Node* headNode){
    if(headNode != NULL){
        // Print data
        printf("%d " ,headNode->data);

        // Recursive funtion to traverse next elements
        printList(headNode->nextNode);
    }
}

Node* LinkedList::bubbleSort(Node* headNode, int list_length){
    // 1. j loop : Start from head and if it's bigger than nextNode, swap
    // 2. i loop : Start from head node and move to next node after previous head node sorted.

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


    Node* linked_list = linkedList.generateNode();
    // Print linked list before sort
    linkedList.printList(linked_list);

    printf("\n");

    // Buble Sort Linked List
    linkedList.bubbleSort(linked_list, length);

    // Print linked list after sort
    linkedList.printList(linked_list);
}
