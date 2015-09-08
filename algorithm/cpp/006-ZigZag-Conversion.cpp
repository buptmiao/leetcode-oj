/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1)  return s;
        string ret;
        size_t size = s.size(),n,j;
        for(int i=0;i<nRows;i++){  //每一行一行的添加
        	if(i == 0 || i == nRows - 1) //第一行和最后一行单独处理
        		for(n = i;n<size;n+=2*nRows-2)
        			ret+=s[n];
        	else{ 
        		for(n = i,j=0;n < size;){ 
        			ret+=s[n];
        			if(j == 0){ 
        				n += 2*(nRows-1-i);
        				j = 1;
        			}else{ 
        				n += 2*i;
        				j = 0;
        			}
        		}
        	}
        }
    }
};