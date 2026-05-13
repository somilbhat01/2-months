#include <iostream>

class Vector {
private:
    int* arr;
    int current_size;
    int current_capacity;

public:
    // Constructor
    Vector() {
        current_size = 0;
        current_capacity = 2;
        arr = new int[current_capacity];
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    void push_back(int value) {
        if (current_size == current_capacity) {
            // Double capacity and reallocate
            int new_capacity = current_capacity * 2;
            int* new_arr = new int[new_capacity];
            
            // Copy old elements
            for (int i = 0; i < current_size; i++) {
                new_arr[i] = arr[i];
            }
            
            // Delete old array
            delete[] arr;
            
            // Update pointer and capacity
            arr = new_arr;
            current_capacity = new_capacity;
        }
        
        // Add element and increment size
        arr[current_size] = value;
        current_size++;
    }

    void pop_back() {
        if (current_size > 0) {
            current_size--;
        } else {
            std::cout << "Underflow: No elements to pop." << std::endl;
        }
    }

    int size() {
        return current_size;
    }

    int capacity() {
        return current_capacity;
    }

    int& operator[](int index) {
        if (index < 0 || index >= current_size) {
            std::cout << "Error: Index out of bounds." << std::endl;
            // Return first element as fallback (not ideal, handles crash)
            return arr[0];
        }
        return arr[index];
    }

    void print_debug() {
        std::cout << "Size: " << current_size << " | Capacity: " << current_capacity << " | Elements: ";
        for (int i = 0; i < current_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector v;
    for (int i = 1; i <= 20; i++) {
        v.push_back(i);
        v.print_debug();
    }
    for (int i = 0; i < 5; i++) {
        v.pop_back();
        v.print_debug();
    }
    std::cout << "Element at index 3: " << v[3] << std::endl;
    return 0;
}
