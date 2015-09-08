/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int ret = 0;
		int diff = 0x7FFFFFFF;
		size_t i,left,right,len = num.size();
		sort(num.begin(),num.end());
		for(i = 0;i < len - 2;i++)
		{
			if(i>0 && num[i] == num[i-1])
				continue;
			for(left = i+1,right = len - 1;left < right;)
			{
				int sum = num[i]+num[left]+num[right];
				if(num[i]+num[left]+num[right] > target)
				{
					if(abs(sum - target) < diff)
					{ret = sum;	diff = abs(sum - target);}	
					right--;
				}
				else if(num[i]+num[left]+num[right] < target)
				{
					if(abs(sum - target) < diff)
					{ret = sum;	diff = abs(sum - target);}	
					left++;
				}
				else
					return target;;
			}
		}
        return ret;
    }
};