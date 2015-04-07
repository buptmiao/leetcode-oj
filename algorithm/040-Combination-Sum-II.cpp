/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/
class Solution{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
			backtracting(res,candidates,target,can,i+1,sum+num);
			can.pop_back();
		}
    }
};