/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
*/


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        unordered_map<string,int> smap;
        if(L.size() == 0 || S.size() <L.size()*L[0].size()) //如果S长度小于右边的总和 或者 右边不存在
        	return res;
        size_t wordlength = L[0].size();
        for(auto it = L.begin();it != L.end();++it)
        	smap[*it]++;
        for(size_t i = 0;i <= S.size()-wordlength*L.size();i++){
        	if(smap.find(S.substr(i,wordlength)) == smap.end())
        		continue;
        	int tmpcnt = L.size();
        	unordered_map<string,int> smaptmp(smap);
			unordered_map<string,int>::iterator it;
			//查找，消除
        	for(int j = i;tmpcnt > 0 && (it = smaptmp.find(S.substr(j,wordlength)) )!= smaptmp.end() && it->second >0;j+=wordlength){ 
        		tmpcnt --;
        		it->second --;
        	}
        	if(tmpcnt == 0)
        		res.push_back(i);
        }
        return res;
    }
};
