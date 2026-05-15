#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    void push_front(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void push_back(int value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    void pop_front() {
        if (head == nullptr) return;
        
        Node* oldHead = head;
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete oldHead;
        size--;
    }
    
    void pop_back() {
        if (tail == nullptr) return;
        
        Node* oldTail = tail;
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete oldTail;
        size--;
    }
    
    void insert_at(int index, int value) {
        if (index < 0 || index > size) return;
        
        if (index == 0) {
            push_front(value);
            return;
        }
        
        if (index == size) {
            push_back(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        
        size++;
    }
    
    void delete_at(int index) {
        if (index < 0 || index >= size) return;
        
        if (index == 0) {
            pop_front();
            return;
        }
        
        if (index == size - 1) {
            pop_back();
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        delete current;
        size--;
    }
    
    void print_forward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    void print_backward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
    
    int get_size() { return size; }
    
    bool contains(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }
    
    bool isEmpty() { return size == 0; }
};

int main() {
    DoublyLinkedList list;
    
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.push_back(30);
    
    std::cout << "Forward: ";
    list.print_forward();   // 5 10 20 30
    
    std::cout << "Backward: ";
    list.print_backward();  // 30 20 10 5
    
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print_forward();   // 10 20 30
    
    list.pop_back();
    std::cout << "After pop_back: ";
    list.print_forward();   // 10 20
    
    list.insert_at(1, 15);
    std::cout << "After insert_at(1,15): ";
    list.print_forward();   // 10 15 20
    
    list.delete_at(1);
    std::cout << "After delete_at(1): ";
    list.print_forward();   // 10 20
    
    return 0;
}