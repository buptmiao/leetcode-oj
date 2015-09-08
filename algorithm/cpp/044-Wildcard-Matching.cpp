/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution { //通配符匹配
public:
     bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 
            if (*p=='*'){star=p++; ss=s;continue;} //保存上次*匹配的位置
            if (star){ p = star+1; s=++ss;continue;} //失配时回到上次匹配保存的位置
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;  
    }

    //using recursive
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') return *s == '\0';
		if(*p == '*'){
			while(*p == '*') p++;
			if(*p == '\0') return true; //*号结尾，返回true
			while(*s != '\0'){
				const char *ts = s,*tp = p;
				while(*ts && (*ts == *tp || *tp == '?')){
					++ts;++tp;
				}
				if(*tp == '*') return isMatch(ts,tp);//递归次数与星号个数有关
				if(*ts == '\0') return *tp == '\0';
				++s;                                 //
			}
		}
		else
			return (*p == '?' && *s != '\0') || *p == *s ? isMatch(s+1,p+1) : false;
    }
    // dp solution which results by MLE
   bool isMatch(const char *s, const char *p) {
		int slen = strlen(s);
		int plen = strlen(p);
		vector<vector<bool> > V(slen+1,vector<bool>(plen+1,false));
		V[slen][plen] = true;
		for(int j=plen-1; j>=0 ; j--)  //初始条件，当s 到达'\0' 时
			if(p[j] == '*') V[slen][j] = V[slen][j+1];
			
		for(int j=plen-1; j>=0 ; j--){
			for(int i=slen-1; i>=0 ; i--){
				if(p[j] != '*')
					V[i][j] = (s[i] == p[j] || p[j] == '?') ? V[i+1][j+1] : false;
				else if(V[i][j+1])
					V[i][j] = true;
				else
					V[i][j] =  V[i+1][j] ;
			}
		}
		return V[0][0];
    }
};
