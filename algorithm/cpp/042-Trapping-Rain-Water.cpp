/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

class Solution {
public:
    int trap(int A[], int n) { //using a stack
        stack<int> st;
		int res = 0;
		for(int i = 0;i<n;i++){
			if(st.empty() || A[i] < A[st.top()])
				st.push(i);
			else{
				for(int last = 0,index = st.top();;index = st.top()){
					int left = A[index];
					if(A[i] >= left){  //calculate by left border,and continue
						res += (left-last) * (i-index-1);
						last = left;
						st.pop();
					}else{             //calculate by right border,and break
						res += (A[i]-last) * (i-index-1);
						break;
					}
					if(st.empty())
						break;
				}
				st.push(i);       //push the right border
			}
		}
		return res;
    }
 	//using two pointers
    int trap(int A[],int n){ 
    	int left = 0,right =n-1;
    	int maxleft=0,maxright=0;
    	int res= 0;
    	while(left < right){ 
    		if(A[left] <= A[right]){ 
    			if(A[left] >= maxleft) maxleft = A[left];
    			else res+=maxleft-A[left];
    			left++;
    		}else{ 
    			if(A[right] >= maxright) maxright = A[right];
    			else res+=maxright-A[right];
    			right--;
    		}
    	}
    	return res;
    }
};