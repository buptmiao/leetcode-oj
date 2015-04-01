/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ret;
		vector<int> element(4);
		size_t i ,j, left ,right,len = num.size()-1;
		if(num.size() < 4)
			return ret;
        sort(num.begin(),num.end());
		for(j = 0; j< len - 2;j++)
		{
			if(j>0 && num[j] == num[j-1])
				continue;
			for(i = j+1;i < len-1;i++)
			{
				if(i>j+1 && num[i] == num[i-1])
					continue;
				for(left = i+1,right = len; left < right ; )
				{
					if(left > i+1 && num[left] == num[left-1])
					{left++;continue;}
					if(right < num.size() - 1 && num[right] == num[right+1])
					{right--;continue;}
						
					if(num[left] + num[right] > target-num[i]-num[j])
						right--;
					else if(num[left] + num[right] <target-num[i]-num[j])
						left++;
					else
					{
						element[0] = num[j] ;
						element[1] = num[i];
						element[2] = num[left];
						element[3] = num[right];
						ret.push_back(element);
						left++;
					}
				}
			}
		}
		
		return ret;
    }
};