#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front;   // Points to front (where we remove from)
    int rear;    // Points to rear (where we add to)
    
public:
    CircularQueue() : front(-1), rear(-1) {}
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Error: Queue full!\n";
            return;
        }
        
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        
        arr[rear] = value;
        cout << "Enqueued " << value << " at index " << rear << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue empty!\n";
            return;
        }
        
        cout << "Dequeued " << arr[front] << " from index " << front << endl;
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    
    int getFront() {
        if (isEmpty()) {
            cout << "Error: Queue empty!\n";
            return -1;
        }
        return arr[front];
    }
    
    int size() {
        if (isEmpty()) return 0;
        if (rear >= front) {
            return rear - front + 1;
        } else {
            return MAX_SIZE - front + rear + 1;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue: empty\n";
            return;
        }
        
        cout << "Queue (front to rear): ";
        int index = front;
        for (int i = 0; i < size(); i++) {
            cout << arr[index];
            if (i < size() - 1) cout << " ";
            index = (index + 1) % MAX_SIZE;
        }
        cout << "  (front=" << front << ", rear=" << rear << ")" << endl;
    }
};

int main() {
    cout << "=== CIRCULAR QUEUE (ARRAY) ===\n";
    CircularQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    
    q.dequeue();
    q.dequeue();
    q.display();
    
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;
    
    return 0;
}