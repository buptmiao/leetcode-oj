/*
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/

class Solution {
public:
    bool isNumber(string s) {
        bool has_dot = false,has_e = false,has_num = false;
        int i = 0;
        while(s[i] == ' ') i++;

        if(s[i] == '-' || s[i] == '+') i++;
        while(i < s.size() && s[i] != ' '){ 
        	if((s[i] == 'e' || s[i] == 'E') && !has_e){ 
        		has_e = has_dot = true;
        		if(!has_num) return false;
        		if(s[i+1] == '-' || s[i+1] == '+') i++;
        		if(!isdigit(s[i+1])) return false;
        	}
        	else if(s[i] == '.' && !has_dot) has_dot = true;
        	else if(isdigit(s[i])) has_num = true;
        	else return false;
        	i++;
        }
        while(i < s.size())
        	if(s[i++] != ' ')
        		return false;
        return has_num;
    }
};
