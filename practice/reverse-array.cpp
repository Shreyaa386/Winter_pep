class Solution {
  public:
  
    void reverseArr(vector<int> &arr , int start , int end){
        if(start>=end) return ;
        swap(arr[start],arr[end]);
        reverseArr(arr,start+1, end-1);
    }
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        // code here
        int start=0, end=n-1;
        
        reverseArr(arr, start, end);
        
    }
};