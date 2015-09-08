/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> element(3);
		size_t i = 0, left = 0,right = num.size()-1;
		if(num.size() < 3)
			return ret;
        sort(num.begin(),num.end());
		for(i = 0;i < num.size()-2;i++)
		{
			if(i>0 && num[i] == num[i-1])
				continue;
			for(left = i+1,right = num.size() - 1; left < right ; )
			{
				if(left > i+1 && num[left] == num[left-1])
				{left++;continue;}
				if(right < num.size() - 1 && num[right] == num[right+1])
				{right--;continue;}
					
				if(num[left] + num[right] > -num[i])
					right--;
				else if(num[left] + num[right] < -num[i])
					left++;
				else
				{
					element[0] = num[i] ;
					element[1] = num[left];
					element[2] = num[right];
					ret.push_back(element);
					left++;
				}
			}
		}
		
		return ret;
    }
};