/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. 
If you still see your function signature returns a char * or String, 
please click the reload button  to reset your code definition.
*/

 /*KMP*/
class Solution {
public:
    int strStr(char *haystack, char *needle) {
		int slen = strlen(haystack);
		int plen = strlen(needle);
		int i = 0;
		int j = 0;
		int *next = new int[plen];
		GetNextval(needle,next);
		while(i < slen && j <plen)
		{
			if(j == -1 || haystack[i] == needle[j])
			{
				j++;
				i++;
			}
			else
				j = next[j];
		}
		if( j == plen)
			return i-plen;
		else
			return -1;
	}
	void GetNextval(char* p, int next[])  //得到优化过的next数组
	{     
		int plen = strlen(p);
		next[0] = -1;
		int j = 0;
		int k = -1;
		while(j < plen - 1)
		{
			if( k == -1 || p[j] == p[k])
			{
				k++;
				j++;
				if(p[j] != p[k])
					next[j] = k;
				else
					next[j] = next[k];
			}
			else
				k = next[k];
		}
	}  
};

class Solution1 {
public:
    int strStr(char *haystack, char *needle) {
		int lenh = strlen(haystack);
		int lenn = strlen(needle);
		for(int i = 0;;i++)
			for(int j = 0;;j++){
				if(j == lenn) return i;
				if(i+j == lenh) return -1;
				if(haystack[i+j] != needle[j]) break;
			}
    }
};