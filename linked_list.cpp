#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;      // Points to top node (not "front" - stacks use "top")
    int count;
    
public:
    Stack() : top(nullptr), count(0) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack empty!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }
    
    int peek() {  // "peek" or "top" - not "front"
        if (isEmpty()) {
            cout << "Error: Stack empty!\n";
            return -1;
        }
        return top->data;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    int size() {
        return count;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack: NULL\n";
            return;
        }
        Node* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " → ";
            }
            current = current->next;
        }
        cout << " → NULL" << endl;
    }
};

int main() {
    cout << "=== STACK (LINKED LIST) ===\n";
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // Stack: 30 → 20 → 10 → NULL
    
    cout << "Peek: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;
    
    s.pop();
    s.display();  // Stack: 20 → 10 → NULL
    
    s.pop();
    s.pop();
    s.pop();  // Error message
    
    return 0;
}