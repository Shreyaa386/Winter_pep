class Solution {
public:
     int s[31];
     int solve(int n){
        if(n<=1) return n;
        if(s[n]!=-1) return s[n];
        return s[n] = solve(n-1)+solve(n-2);
     }
    int fib(int n) {
       memset(s,-1,sizeof(s));
       return solve(n);

       
    }
};