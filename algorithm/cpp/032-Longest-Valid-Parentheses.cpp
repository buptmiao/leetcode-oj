/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
	//Solution 1:using dynamic programming
    int longestValidParentheses(string s) {
    	int size = s.length();
        vector<int> dp(size+1);
        int res = 0;
        if(size < 2)
        	return 0;
        for(int i = size-2;i >= 0;i--){ 
        	if(s[i] == '('){ 
        		if(s[i+1] == ')'){
        			dp[i] = dp[i+2] + 2;
        			res = max(res,dp[i]);
        		}
        		else if(s[i+1+dp[i+1]] == ')'){ 
        			dp[i] = dp[i+1] + 2 + dp[i+2+dp[i+1]];
        			res = max(res,dp[i]);
        		}
        	}
        	else
        		dp[i] = 0;
        }
        return res;
    }
    //Solution 2:using a stack
    int longestValidParentheses(string s) { 
    	stack<int> st;
    	int res = 0;
    	for(int i = 0;i < s.size();i++){ 
    		if(s[i] == '(')
    			st.push(i);
    		else{ 
    			if(!st.empty() && s[st.top()] == ')') { 
    				st.pop();
    				int lastpos = st.empty() ? -1 : st.top(); //lastpos
    				if(i - lastpos > res)
    					res = i - lastpos;
    			}
    			else
    				st.push(i);
    		}
    	}
    	return res;
    }
};


