#include <iostream>
using namespace std;

class StackArray {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int topIndex;  // Points to top element index
    
public:
    StackArray() : topIndex(-1) {}
    
    void push(int value) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Error: Stack overflow!\n";
            return;
        }
        arr[++topIndex] = value;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack empty!\n";
            return;
        }
        topIndex--;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack empty!\n";
            return -1;
        }
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    int size() {
        return topIndex + 1;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack: empty\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== STACK (ARRAY) ===\n";
    StackArray s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // Stack (top to bottom): 30 20 10
    
    cout << "Peek: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;
    
    s.pop();
    s.display();  // Stack (top to bottom): 20 10
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    return 0;
}