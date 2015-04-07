/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

class Solution {
public:
	//Solution 1：using backtracting
	vector<vector<int> > permuteUnique(vector<int> &num) {
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
			int lastnum = num[0]-1;
			for(size_t i=0;i<num.size();i++){
				if(find(candidate.begin(),candidate.end(),i) == candidate.end() && num[i]!=lastnum){
						lastnum = num[i];
						candidate.push_back(i);
						backtracing(ret,num,candidate);
						candidate.pop_back();
				}
			}
		}
	}
	//Solution 2： using dp
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
		if(num.size() == 0)
			return ret;
		ret.push_back(vector<int>(1,num[0]) );
		for(int i = 1;i<num.size();i++){
			int size = ret.size();
			for(int j = 0;j<size;j++){  //遍历 ret 中每一个子排列
				ret[j].push_back(num[i]);
				vector<int> temp = ret[j];
				for(int k = i-1 ; k>= 0 && temp[k] != temp[k+1] ; k--){ //不一致的才需要交换
					swap(temp[k],temp[k+1]);
					ret.push_back(temp);
				}
			}
		}
		return ret;
	}
};