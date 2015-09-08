/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cache;
        backtracting(res,cache,0,n);
        return res;
    }
    void backtracting(vector<string> &res,string cache,int x,int n){ 
		if(x != n ){
    		cache.append(1,'(');
    		backtracting(res,cache,++x,n);
    		int t = 2*x-cache.size();//numbers of '('s - ')'s.
    		for(int i = 0;i<t;i++){ 
    			cache.append(1,')');
    			backtracting(res,cache,x,n);
    		}
    	}else if(cache.size() == n*2)
			res.push_back(cache);
    }
};