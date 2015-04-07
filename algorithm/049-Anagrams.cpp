/*

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
		map<string,int> stoindex;
		for(size_t i = 0;i<strs.size();i++){
			string s = strs[i];
			sort(s.begin(),s.end());
			if(stoindex.find(s) == stoindex.end())
				stoindex[s] = i;
			else{
				if(stoindex[s] >= 0){
					ret.push_back(strs[stoindex[s]]);
					stoindex[s] = -1;
				}
				ret.push_back(strs[i]);
			}
		}
		return ret;
    }
};