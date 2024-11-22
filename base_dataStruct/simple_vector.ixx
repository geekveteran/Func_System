export module simple_vector;

import <stdexcept>;

export class simple_vector {
private:
    int* data;        // Pointer to the dynamic array
    size_t size;      // Current number of elements
    size_t capacity;  // Total capacity of the array

    // Resize the array when capacity is reached
    void resize() {
        capacity = capacity * 2; // Double the capacity
        int* newData = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    // Constructor
    simple_vector(size_t initialCapacity = 4)
        : data(new int[initialCapacity]), size(0), capacity(initialCapacity) {}

    // Destructor
    ~simple_vector() {
        delete[] data;
    }

    // Add an element to the end
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Access element at index
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get the number of elements
    size_t getSize() const {
        return size;
    }

    // Get the capacity of the array
    size_t getCapacity() const {
        return capacity;
    }
};
