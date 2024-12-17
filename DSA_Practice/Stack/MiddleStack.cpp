#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int _data) : data(_data), prev(nullptr), next(nullptr){}
};

class MiddleStack{
    private:
    Node* head;
    Node* middle;
    size_t size;

    public:
    MiddleStack() : head(nullptr), middle(nullptr), size(0){}

    void push(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            middle = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

            // If the size of the stack is even, we need to move the middle pointer
            // one step to the left because the new node is at the beginning of
            // the stack. This is done to keep the middle pointer pointing to
            // the middle element of the stack.
            if(size % 2 == 0){
                middle = middle->prev;
            }
        }
        size++;
    }

    int pop(){
        if(!head){
            cout << "Stack is empty\n";
            return -1;
        }
        Node* toDelete = head;
        int data = toDelete->data;
        head = head->next;

        if(head){
            head->prev = nullptr;
        }

        // If the size of the stack is odd, we need to move the middle pointer
        // one step to the right because the new node is at the beginning of
        // the stack. This is done to keep the middle pointer pointing to
        // the middle element of the stack. This is done because the middle
        // element is the one that is in the middle of the stack, and when we
        // remove the top element, we need to move the middle pointer to the
        // right to keep it pointing to the middle element. If we don't do
        // this, the middle pointer will be pointing to the wrong element.
        if(size % 2 == 1){
            middle = middle->next;
        }

        delete toDelete;
        size--;
        if(size == 0){
            middle = nullptr;
        }
        return data;
    }

    int getMiddle(){
        if(!middle){
            cout << "Stack is empty\n";
            return -1;
        }
        return middle->data;
    }

    void insertMiddle(int data){
        if(!middle){
            push(data);
            return;
        }

        Node* newNode = new Node(data);
        newNode->prev = middle->prev;
        newNode->next = middle;

        if(middle->prev){
            middle->prev->next = newNode;
        }
        middle->prev = newNode;
        if(size % 2 == 1){
            middle = newNode;
        }
        size++;
    }

    void deleteMiddle(){
        if(!middle){
            cout << "Stack is empty\n";
            return;
        }

        Node* toDelete = middle;

        if(middle->prev){
            middle->prev->next = middle->next;
        }
        if(middle->next){
            middle->next->prev = middle->prev;
        }

        // If the size of the stack is even, we need to move the middle pointer
        // one step to the right because the element that was in the middle
        // is now gone and we need to move the middle pointer to the right
        // of the new middle element. If we don't do this, the middle pointer
        // will be pointing to the wrong element.
        //
        // If the size of the stack is odd, we need to move the middle pointer
        // one step to the left because the element that was in the middle
        // is now gone and we need to move the middle pointer to the left
        // of the new middle element. If we don't do this, the middle pointer
        // will be pointing to the wrong element.
        if(size % 2 == 0){
            middle = middle->next;
        }
        else{
            middle = middle->prev;
        }
        if(toDelete == head){
            head = head->next;
        }

        delete toDelete;
        size--;
        if(size == 0){
            middle = nullptr;
        }
    }
};


int main(){
    MiddleStack mid_stack;

    mid_stack.push(1);
    mid_stack.push(2);
    mid_stack.push(3);
    mid_stack.push(4);
    mid_stack.push(5);
    mid_stack.push(6);

    mid_stack.deleteMiddle();
    cout << "Middle after deletion: " << mid_stack.getMiddle() << endl; // Output: 4

    mid_stack.insertMiddle(10);
    cout << "Middle after insertion: " << mid_stack.getMiddle() << endl; // Output: 10

    mid_stack.pop();
    cout << "Middle after pop: " << mid_stack.getMiddle() << endl; // Output: 3
    return 0;
}