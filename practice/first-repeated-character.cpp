class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        int freq[256]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]>1)
            return string(1, s[i]);
        }
        return "-1";
    }
};