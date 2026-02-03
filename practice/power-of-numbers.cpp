class Solution {
  public:
  int power(int n, int exp){
          if(exp==0)
          return 1;
          return n*power(n,exp-1);
        }
  
    int reverseExponentiation(int n) {
        //code here
        int rev=0;
        int temp=n;
        while(temp>0){
            rev= rev*10+(temp%10);
            temp/=10;
            
        }
        return power(n,rev);
    }
        
};