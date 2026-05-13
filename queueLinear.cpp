#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;   // Points to front (where we remove from)
    Node* rear;    // Points to rear (where we add to)
    int count;
    
public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}
    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
    }
    
    int getFront() {  // "getFront" or "front" - not "peek"
        if (isEmpty()) {
            cout << "Error: Queue empty!\n";
            return -1;
        }
        return front->data;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    int size() {
        return count;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue: NULL\n";
            return;
        }
        Node* current = front;
        cout << "Queue (front → rear): ";
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
    cout << "=== QUEUE (LINKED LIST) ===\n";
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Queue (front → rear): 10 → 20 → 30 → NULL
    
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;
    
    q.dequeue();
    q.display();  // Queue (front → rear): 20 → 30 → NULL
    
    return 0;
}