//using absolute value

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ast:asteroids){
        bool destroyed = false;
        while( !st.empty() && st.top()>0 && ast<0){
            if(abs(st.top())<abs(ast)){
                st.pop();
            }
            else if(abs(st.top())==abs(ast)){
                st.pop();
                destroyed = true;
                break;
            }else{
                destroyed=true;
                break;
            }
        }
        if(!destroyed){
            st.push(ast);
        }
    }
    
    vector<int>result(st.size());
    for(int i=st.size()-1;i>=0;i--){
        result[i]=st.top();
        st.pop();
    }
    return result;
    }
};


//by doing sum

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int ast : asteroids) {
            
            bool destroyed = false;
            
            while(!st.empty() && st.top() > 0 && ast < 0) {
                
                int sum = st.top() + ast;
                
                if(sum < 0) {
                    
                    st.pop();
                }
                else if(sum == 0) {
                    
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                   
                    destroyed = true;
                    break;
                }
            }
            
            if(!destroyed) {
                st.push(ast);
            }
        }
        
        vector<int> result(st.size());
        
        for(int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};