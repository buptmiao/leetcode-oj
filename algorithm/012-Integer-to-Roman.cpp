/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
		string s;
        if(num >= 1000)
			s.append(num/1000,'M').append(intToRoman(num % 1000));
		else if(num >= 100)
			s = singleNumberConvert(num/100,'C','D','M').append(intToRoman(num % 100));
		else if(num >= 10)
			s = singleNumberConvert(num/10,'X','L','C').append(intToRoman(num % 10));
		else
			s = singleNumberConvert(num,'I','V','X');
		return s;
    }
    
	string singleNumberConvert(int num,char one,char five,char ten)
	{
		string s;
		if(num < 4)
			s.append(num,one);
		else if(num < 5)
			s.append(1,one).append(1,five);
		else if(num < 6)
			s.append(1,five);
		else if(num < 9)
			s.append(1,five).append(num - 5,one);
		else
			s.append(1,one).append(1,ten);
		return s;
	}
};