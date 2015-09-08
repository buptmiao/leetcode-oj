/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num(n);
        int total = 1;
        string res;
        for(int i = 1;i<=n;i++){ 
        	num[i-1] = i;	//给出一个1~n序列
        	total *= i;  	//计算n的阶乘
        }
        for(int i = n-1;i>=0;i--){ 
        	total /= i+1;
        	if(k > total){ 
        		int t = 1 + (k-1)/total; 		//	计算后面有几个全排列，t至少为1
        		res += '0'+num[t-1];     		//	把第t个数字放在结果后面
        		num.erase(num.begin() + t - 1)；  //	清除这个数字
        		k %= total;                     //	更新K
        		if(k == 0)
        			k = total;
        	}
        	else{                               //直接按序输出
        		res += '0'+num[0];
        		num.erase(num.begin());
        	}
        }
        return res;
    }
};

