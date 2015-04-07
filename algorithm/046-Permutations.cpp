/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

class Solution {
public:
	// Solution 1: using backtracting
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
		vector<int> candidate;
		sort(num.begin(),num.end());
		backtracing(ret,num,candidate);
		return ret;
    }
	void backtracing(vector<vector<int> > &ret,vector<int> &num,vector<int> &candidate)
	{
		if(candidate.size() == num.size()){
			vector<int> temp;
			for(int i = 0;i < candidate.size();i++)
				temp.push_back(num[candidate[i]]);
			ret.push_back(temp);
		}
		else{
			for(size_t i=0;i<num.size();i++){
				if(find(candidate.begin(),candidate.end(),i) == candidate.end()){
						candidate.push_back(i);
						backtracing(ret,num,candidate);
						candidate.pop_back();
				}
			}
		}
	}
	//Solution 2: using dp
	vector<vector<int> > permute(vector<int> &num){ 
		vector<vector<int> > res;
		if(num.size() == 0)
			return res;
		res.push_back(vector<int>(1,num[0]));
		for(int i = 1;i<num.size();i++){
			int size = res.size();
			for(int j = 0;j < size;j++){ 
				res[j].push_back(num[i]);
				vector<int> temp = res[j];
				for(int k = i-1;k>=0;k--){ 
					swap(temp[k],temp[k+1]);
					res.push_back(temp);
				}
			}
		}
		return res;
	}
};

