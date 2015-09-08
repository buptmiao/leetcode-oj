/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]

*/

class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> can;
        sort(candidates.begin(),candidates.end());
        backtracting(res,candidates,target,can,0,0);
		return res;
    }
    void backtracting(vector<vector<int> > &res,vector<int> &candidates,int target,vector<int> &can,int index,int sum){ 
    	if(sum == target){ 
    		res.push_back(can);
    		return;
    	}
		for(int i = index;i<candidates.size();i++){
			int num = candidates[i];
			if(i > index && num == candidates[i-1])
				continue;
			if(sum + num > target)//超过了target
				return;
			can.push_back(num);
			backtracting(res,candidates,target,can,i,sum+num);
			can.pop_back();
		}
    }
};
