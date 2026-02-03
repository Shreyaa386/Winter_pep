class Solution {
  public:
  
    void merge(vector<int>& arr, int l , int m, int r){
        vector<int>temp;
        int i = l , j = m+1;
        while(i<=m && j<=r){
            if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i<=m)
            temp.push_back(arr[i++]);
            
        
        while(j<=r)
            temp.push_back(arr[j++]);
            for(int k =0;k<temp.size();k++)
            arr[l+k]=temp[k];
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
      //  int n = arr.size();
        // code here
        if(l>=r) return;
        //l =0, r=n-1;
        int mid =l+ (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid ,r);
    }
};