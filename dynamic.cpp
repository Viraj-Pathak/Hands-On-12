#include <iostream>

class DynamicArray {
private:
    int *arr;
    int capacity;
    int size;

public:
    DynamicArray() {
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void resize() {
        capacity *= 2;
        int *newArr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    int at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() {
        return size;
    }
};

int main() {
    DynamicArray dynamicArray;
    dynamicArray.push_back(10);
    dynamicArray.push_back(20);
    dynamicArray.push_back(30);
    
    for (int i = 0; i < dynamicArray.getSize(); ++i) {
        std::cout << dynamicArray.at(i) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
