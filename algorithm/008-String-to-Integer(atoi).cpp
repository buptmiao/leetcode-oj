/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
	int atoi(const char *str) {
		int len = strlen(str);
		int ret = 0;
		int nagi = 0;	
		int nagiflag = 0;
		int digitflag = 0;
		for(int i = 0; i < len;i++)
		{
			if(isspace(str[i]) && digitflag == 0)
				continue;
			else if(str[i] == '-' && digitflag == 0 && nagiflag == 0){
				nagi = 1;nagiflag = 1;	digitflag = 1;
			}
			else if(str[i] == '+' && digitflag == 0 && nagiflag == 0){
				nagi = 0;nagiflag = 1;	digitflag = 1;
			}
			else if(isdigit(str[i])){
				digitflag = 1;
				if(abs(ret) > 214748364 || (abs(ret) == 214748364 && str[i] > '7'))
					return nagi ? -2147483648 : 2147483647 ;
				ret = ret * 10 + str[i] - 0x30;
			}
			else 
				break;
		}
		return nagi ? -ret : ret;
    }
};