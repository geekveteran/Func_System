export module utilities;

export namespace Utilities {
    // A simple utility function to print arrays
    void printArray(const int* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    // A utility function to calculate the sum of an array
    int sumArray(const int* arr, size_t size) {
        int sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum;
    }
}
