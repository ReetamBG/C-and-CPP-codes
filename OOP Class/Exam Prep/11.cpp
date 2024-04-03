#include <iostream>

class DynamicArray {
private:
    int* array;
    size_t size;

public:
    // Constructor
    DynamicArray(size_t initialSize) {
        size = initialSize;
        array = new int[size];
    }

    // Destructor
    ~DynamicArray() {
        delete[] array;
    }

    // Function to resize the array
    void resize(size_t newSize) {
        int* newArray = new int[newSize];
        size_t copySize = (newSize < size) ? newSize : size;

        for (size_t i = 0; i < copySize; ++i) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        size = newSize;
    }

    // Function to set a value at a specific index
    void setValue(size_t index, int value) {
        if (index < size) {
            array[index] = value;
        } else {
            std::cout << "Index out of bounds!" << std::endl;
        }
    }

    // Function to get a value at a specific index
    int getValue(size_t index) const {
        if (index < size) {
            return array[index];
        } else {
            std::cout << "Index out of bounds!" << std::endl;
            return -1; // Return a default value or handle the error accordingly
        }
    }
};

int main() {
    // Creating a dynamic array with an initial size of 5
    DynamicArray myArray(5);

    // Setting values at various indices
    myArray.setValue(0, 10);
    myArray.setValue(1, 20);
    myArray.setValue(2, 30);

    // Displaying values at various indices
    std::cout << "Value at index 0: " << myArray.getValue(0) << std::endl;
    std::cout << "Value at index 1: " << myArray.getValue(1) << std::endl;
    std::cout << "Value at index 2: " << myArray.getValue(2) << std::endl;

    // Resizing the array to 8 elements
    myArray.resize(8);

    // Setting values after resizing
    myArray.setValue(5, 50);
    myArray.setValue(6, 60);
    myArray.setValue(7, 70);

    // Displaying values after resizing
    std::cout << "Value at index 5: " << myArray.getValue(5) << std::endl;
    std::cout << "Value at index 6: " << myArray.getValue(6) << std::endl;
    std::cout << "Value at index 7: " << myArray.getValue(7) << std::endl;

    return 0;
}
