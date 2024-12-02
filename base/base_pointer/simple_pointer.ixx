export module base_pointer;
// Custom implementation of a Unique Pointer
template <typename T>
class UniquePointer {
private:
    T* ptr; // Raw pointer to manage

public:
    // Constructor
    explicit UniquePointer(T* resource = nullptr) : ptr(resource) {}

    // Destructor
    ~UniquePointer() {
        delete ptr;
    }

    // Delete copy constructor and copy assignment to ensure unique ownership
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor
    UniquePointer(UniquePointer&& other) noexcept : ptr(nullptr) {
        ptr = other.ptr;  // Transfer ownership
        other.ptr = nullptr;
    }

    // Move assignment operator
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr;          // Clean up existing resource
            ptr = other.ptr;     // Transfer ownership
            other.ptr = nullptr; // Leave the source in a valid state
        }
        return *this;
    }

    // Overload dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Overload arrow operator
    T* operator->() const {
        return ptr;
    }

    // Release ownership of the pointer
    T* release() {
        T* temp = ptr; // Store current pointer
        ptr = nullptr; // Reset managed pointer
        return temp;   // Return raw pointer
    }

    // Reset the pointer to a new resource
    void reset(T* newPtr = nullptr) {
        delete ptr;  // Clean up existing resource
        ptr = newPtr; // Take ownership of the new pointer
    }

    // Check if the pointer is non-null
    bool isValid() const {
        return ptr != nullptr;
    }

    // Explicit boolean conversion
    explicit operator bool() const {
        return isValid();
    }
};