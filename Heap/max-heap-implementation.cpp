//Implementation of Max Heap in C++
#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int peek() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1; // Return -1 to indicate an error
        }
        return heap[0];
    }
    void display() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);
    cout << "Max Heap: ";
    maxHeap.display();
    cout << "Max Element: " << maxHeap.peek() << endl;
    maxHeap.deleteMax();
    cout << "After deleting max element: ";
    maxHeap.display();
    return 0;
}



//explanation of code:
// 1. The MaxHeap class contains a private vector called 'heap' to store the

elements of the max heap.
// 2. The 'heapifyUp' function is used to maintain the max heap property after inserting a new element. It compares the newly added element with its parent and swaps them if the new element is greater, continuing this process until the max heap property is restored.
// 3. The 'heapifyDown' function is used to maintain the max heap property after deleting the maximum element. It compares the new root element with its children and swaps it with the largest of the three if necessary, continuing this process until the max heap property is restored.
// 4. The 'insert' function adds a new element to the end of the heap and then calls 'heapifyUp' to maintain the max heap property.
// 5. The 'deleteMax' function removes the maximum element (the root) from the heap, replaces it with the last element, and then calls 'heapifyDown' to maintain the max heap property.