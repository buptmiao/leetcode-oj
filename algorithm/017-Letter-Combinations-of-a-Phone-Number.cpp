/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
	string map1[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	string cache;
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
        	return res;
        backtracting(res,digits,0);
        return res;
    }
    void backtracting(vector<string> &res,string &digits,int x){ 
    	if(x == digits.size())
    		res.push_back(cache);
    	else{ 
    		string chars = map1[digits[x]-'0'];
    		for(int i = 0;i < chars.size();i++){ 
    			cache += chars[i];
    			backtracting(res,digits,x+1);
    			cache.erase(cache.end() - 1);
    		}

    	}
    }
};