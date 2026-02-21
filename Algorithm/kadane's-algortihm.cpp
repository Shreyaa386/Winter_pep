//kadane's Algorithm
//Time Complexity: O(n)
//Space Complexity: O(1)    
//Kadane's Algorithm is a dynamic programming algorithm used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers.
//The algorithm works by iterating through the array and keeping track of the maximum sum of a subarray that ends at the current index. It also keeps track of the overall maximum sum found so far.
//The algorithm can be implemented as follows:

int kadane(vector<int>& arr) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++) {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}   
