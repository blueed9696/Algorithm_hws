#include <iostream>
#include <cstdlib>
using namespace std;

// binary tree element array length
int length = 0;

// Binary tree node definition
struct Node{
    int data;
    Node* leftChild;
    Node* rightChild;

    // Node Struct constructor for init
    Node(int key){
        data = key;
        leftChild = NULL;
        rightChild = NULL;
    }
};

// Definition of binary tree
class Tree{
    private:
        Node* root;

        Node* insertNode(Node* current, int key){
            // Define first node
            if(current == NULL){
                return new Node(key);
            }
            // Inserting Process
            if(key > current->data){ // Putting key value to right
                current->rightChild = insertNode(current->rightChild, key);
            }else{ // Putting key value to left
                current->leftChild = insertNode(current->leftChild, key);
            }

            return current;
        }
        // Reading from left child to right child
        void printNode(Node* current){
            if(current != NULL){
                printNode(current->leftChild);
                cout << current->data << " ";
                printNode(current->rightChild);
            }
        }
        
        // Function to save array of sorted tree
        int* saveArray(Node* current, int element_arr[], int& ind){
            if(current != NULL){
                saveArray(current->leftChild, element_arr, ind);
                element_arr[ind++] = current->data;
                saveArray(current->rightChild, element_arr, ind);
            }
            return element_arr;
        }

    public:
        Tree(){
            // Root node initialization
            root = NULL; 
        }
        // Inserting node
        void insert(int key){
            root = insertNode(root, key);
        }

        void print(){
            printNode(root);
        }

        int* returnArr() {
            int* element_arr = new int[length]; // Allocate memory for the array
            int index = 0;
            saveArray(root, element_arr, index);
            return element_arr;
        }

        int search(int left, int right, int element_arr[], int key){
            int key_not_found = 0;

            // Define dividing index
            if(left < 0){
                left = 0;
            }
            if(right < 0){
                right = 0;
            }

            int mid1 = left + (right - left)/3;
            int mid2 = right - (right - left)/3;

            if(mid1 > length){
                mid1 = length;
            }
            if(mid2 > length){
                mid2 = length;
            }

            // Return last node if all dividers reaches last node
            if(mid1 == length && mid2 == length){
                return mid1-1;
            }

            // Return mid index if mid1 or mid2 contains key value
            if(element_arr[mid1] == key){
                return mid1;
            }
            if(element_arr[mid2] == key){
                return mid2;
            }

            if(key < element_arr[mid1]){ // Expand left index in case it passed key value
                return search(left, mid1 - 1, element_arr, key);
            }else if(key > element_arr[mid2]){ // Expand right index in case it passed key value
                return search(mid2 + 1, right, element_arr, key);
            }else{
                return search(mid1 - 1, mid2 + 1, element_arr, key);
            }

            // set boundary to mid2 not cross over mid1
            if(mid1 > mid2){
                return key_not_found = -1;
            }
            
            // Return if key is not found
            return key_not_found = -1;
        }


};

int main(){
    Tree tree;

    int key;

    // Take input length for tree
    cout << "Put input length (>0): ";
    cin >> length;
    if(length < 0){
        cout << "Warning : put positive integers";
    }

    int rand_num_arr[length];

    // Generate random numbers to tree
    for(int i = 0; i < length; i++){
        int rand_num = i + rand()%1000; // randomly generate number
        rand_num_arr[i] = rand_num;

        // Add 1 if random number redundancy found.
        for(int j = 0; j < length; j++){
            if(i != j){
                if(rand_num_arr[j] == rand_num){
                    rand_num = rand_num + 1; // If it's in array, +1
                }
            }
        }
        tree.insert(rand_num);
    }

    cout << "Sorted binary tree : " << endl;
    tree.print();
    
    // Store sorted tree values to array
    int* element_arr = tree.returnArr();

    // Search key value from tree
    cout << endl << "Put key value want to find : ";
    cin >> key;

    // Find key from tree
    int key_index = tree.search(0, length, element_arr, key);
    
    if(key_index == -1){
        cout << "Key is not found";
    }else{
        cout << "Key is in index " << " ";
        cout << key_index << endl;
    }
}