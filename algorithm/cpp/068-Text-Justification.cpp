/*
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            vector<string> res;
            string temp;
            int cnt = 0;
            for(auto & s : words){
                if(temp.size()+s.size() > L){//需要调整上一行
                    int spacenum = L - temp.size()+1;//需要分配的空格数
                    if(cnt == 1)                    //只有一个单词的情况
                        temp.append(spacenum -1,' ');
                    else{
                        int m = spacenum/(cnt-1); //每一个空格处插入m个空格
                        int n = spacenum%(cnt-1); //前n组个空格插入一个空格
                        string temp2;
                        int pos = 0;
                        for(int i = 0;i < cnt;i++){
                            int a = temp.find_first_of(' ',pos);
                            temp2 += temp.substr(pos,a-pos);
                            pos = a+1;
                            if (temp2.size() == L) break;
                            if(i<n)
                                temp2.append(m+2,' ');
                            else
                                temp2.append(m+1,' ');
                        }
                        temp = temp2;
                    }
                    res.push_back(temp);
                    temp = s;
                    if(temp.size() == L){
                        res.push_back(temp);
                        temp = "";
                        cnt = 0;
                    }else
                        temp+= " ";
                    cnt= 1;
                }
                else{
                    temp += s;
                    if(temp.size() == L){
                        res.push_back(temp);
                        temp = "";
                        cnt = 0;
                    }
                    else{
                        temp += " ";
                        cnt++;
                    }
                }

            }
            if(temp.size()){
                temp.append(L-temp.size(),' ');
                res.push_back(temp);
            }
            return res;
        }
};
