class Solution {
public:

    int s[46];
    int solve(int n){
    if(n<=2) return n;
    if(s[n]!=-1) return s[n];
    return s[n]=solve(n-1)+solve(n-2); 

    }
    int climbStairs(int n) {
        memset(s,-1,sizeof(s));
        return solve(n);

    }
};