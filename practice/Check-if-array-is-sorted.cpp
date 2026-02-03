class Solution {
public:
//with recursion
    bool sorted(vector<int>& arr, int index) {
        
        if (index == arr.size() - 1)
            return true;

        if (arr[index] > arr[index + 1])
            return false;

        return sorted(arr, index + 1);
    }

    bool isSorted(vector<int>& arr) {
        return sorted(arr, 0);
    }
};
