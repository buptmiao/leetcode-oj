/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

class Solution {
public:
	string longestPalindrome(string s){
		string T = "^";
		int n = s.size();
		for(int i = 0;i < n;i++){
			T+='#';
			T+=s[i];
		}
		T+="#$";
		int m = 2*n+3;
		int C = 0,R = 0;
		vector<int> p(m);
		for(int i = 1;i < m-1 ;i++){
			int i_mirror = 2*C - i;
			p[i] = (R > i) ? min(R-i,p[i_mirror]) : 0;
			while(T[i + 1 + p[i]] == T[i - 1 - p[i]])
				p[i] ++;
			if(i+p[i] > R){
				C = i;
				R = i + p[i];
			}
		}
		int maxlen = 0,center = 0;
		for(int i = 1;i < m-1;i++){
			if(p[i] > maxlen){
				maxlen = p[i];
				center = i;
			}
		}
		return s.substr((center-1-maxlen) / 2,maxlen);
	}
};
	