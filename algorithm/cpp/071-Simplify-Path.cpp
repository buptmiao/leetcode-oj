/*
Given an absolute path for a file (Unix-style), simplify it. 

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"

In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/
class Solution {
public:
    string simplifyPath(string path) {
		string res;
		string temp;
		vector<string> v;
		path += '/';
        for(size_t i = 1;i<path.size();i++){
			if(path[i] == '/'){
				if(temp == ".." ){
					if(v.size() > 0)	v.pop_back();
				}
				else if(temp.size() && temp != ".")
					v.push_back(temp);
				temp = "";
			}else	temp+=path[i];
		}
		if(v.size() == 0)	return "/";
		for(auto &s : v)
			res += "/"+s;
		return res;
    }
};
