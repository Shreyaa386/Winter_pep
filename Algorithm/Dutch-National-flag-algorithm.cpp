//Dutch National Algorithm
//Time Complexity: O(n) 
//Space Complexity: O(1)
//The Dutch National Flag algorithm is a sorting algorithm that sorts an array of three distinct values (often represented as 0, 1, and 2) in linear time and constant space. The algorithm works by maintaining three pointers: one for the current position, one for the next position of 0, and one for the next position of 2. The algorithm iterates through the array and swaps elements based on their values to ensure that all 0s are moved to the beginning, all 1s are in the middle, and all 2s are moved to the end. The algorithm can be implemented as follows:

//syntax: swap(arr[i], arr[j]) is used to swap the elements at index i and j in the array arr.
//Example usage:
// vector<int> arr = {2, 0, 1, 2, 1, 0};
// dutchNationalFlag(arr);
// After calling dutchNationalFlag, arr will be sorted as {0, 0, 1, 1, 2, 2}.
//Note: The input array should only contain the values 0, 1, and 2 for the algorithm to work correctly.
//The algorithm is efficient and works in O(n) time complexity, where n is the size of the input array, and it uses O(1) extra space since it only requires a few pointers for swapping elements.
//The Dutch National Flag algorithm is particularly useful for sorting problems where there are only a few distinct values, and it can be applied in various scenarios such as sorting colors, partitioning arrays, and more.

void dutchNationalFlag(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}