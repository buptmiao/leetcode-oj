/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/

class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
		backtracing(ret,n,(1<<n)-1 ,0,0,0);
		return ret;
    }
	void backtracing(int &ret,int num,int limit,int h,int r,int l){
		if(num == 0)
			ret++;
		else{
			int pos = limit & (~(h|r|l));
			while(pos){
				int p = pos & (-pos);
				pos-=p;
				backtracing(ret,num - 1,limit,h+p,(r+p)<<1,(l+p)>>1);//nice shot
			}
		}
	}
};
