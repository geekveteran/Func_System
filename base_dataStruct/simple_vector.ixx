export module simple_vector;

export template <typename T>
class simple_vector {
private:
    T* data;        // Pointer to the dynamic array
    size_t size;    // Current number of elements
    size_t capacity;  // Total capacity of the array

    // Resize the array when capacity is reached
    void resize() {
        capacity = capacity * 2; // Double the capacity
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    // Constructor
    explicit simple_vector(size_t initialCapacity = 4)
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

    // Destructor
    ~simple_vector() {
        delete[] data;
    }

    // Add an element to the end
    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Access element at index
    T& operator[](size_t index) {
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

    // Optional: Access element at index (const version)
    const T& operator[](size_t index) const {
        return data[index];
    }
};
