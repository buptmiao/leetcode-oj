/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/


class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if(num.size() == 0)
			return;
		size_t i,j,k;
        for(i=0,j=0;i<num.size()-1;i++) //find a reverse-order pair
		{
			if(num[i] < num[i+1])
				j = i;
		}
		for(k = j+1,i=0;k<num.size();k++) //find the min num that is little than num[j].
		{
			if(num[k] > num[j])
				i = k;
			else
				break;
		}
		if(i > j)                      //if not a descending sequence, than swap two num found above.
			swap(num[j++],num[i]);
		reverse(num.begin()+j,num.end()); 
    }
};