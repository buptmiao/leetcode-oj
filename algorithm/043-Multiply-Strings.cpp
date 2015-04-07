/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(),'0');  //长度相加，就是结果的最大长度
        for(int i = num1.size()-1;i>=0;i--)
			for(int j = num2.size()-1;j>=0;j--){
				char t = (num1[i] - '0')*(num2[j]-'0');
				res[i+j] += (res[i+j+1]-'0'+t) / 10;
				res[i+j+1] = (res[i+j+1]-'0'+t)% 10 + '0';
			}
		int start = res.find_first_not_of('0',0);
		if(start == -1) return "0";
		return res.substr(start,res.size()-start);
    }
};
