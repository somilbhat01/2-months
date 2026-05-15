#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    int size;
    
public:
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* nextNode = nullptr;
        
        while (current->next != head) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        
        delete current;
        head = nullptr;
        size = 0;
    }
    
    void push_front(int value) {
        if (head == nullptr) {
            head = new Node(value);
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            
            Node* newNode = new Node(value);
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
        size++;
    }
    
    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value);
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            
            Node* newNode = new Node(value);
            newNode->next = head;
            last->next = newNode;
        }
        size++;
    }
    
    void pop_front() {
        if (head == nullptr) return;
        
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            
            Node* oldHead = head;
            head = head->next;
            last->next = head;
            delete oldHead;
        }
        size--;
    }
    
    void pop_back() {
        if (head == nullptr) return;
        
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != head) {
                current = current->next;
            }
            
            delete current->next;
            current->next = head;
        }
        size--;
    }
    
    void print() {
        if (head == nullptr) {
            std::cout << "Empty" << std::endl;
            return;
        }
        
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
    
    int get_size() { return size; }
    
    bool contains(int value) {
        if (head == nullptr) return false;
        
        Node* current = head;
        do {
            if (current->data == value) return true;
            current = current->next;
        } while (current != head);
        
        return false;
    }
    
    bool isEmpty() { return size == 0; }
};

int main() {
    CircularLinkedList list;
    
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.push_back(30);
    
    std::cout << "List: ";
    list.print();   // 5 10 20 30
    
    std::cout << "Size: " << list.get_size() << std::endl;  // 4
    
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();   // 10 20 30
    
    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();   // 10 20
    
    std::cout << "Contains 20: " << list.contains(20) << std::endl;  // 1
    std::cout << "Contains 5: " << list.contains(5) << std::endl;    // 0
    
    return 0;
}