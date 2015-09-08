/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
        int m = matrix.size();
		if(matrix.size() == 0)	return res;
		int n = matrix[0].size();
		for(int i = 0;i < (min(m,n)+1)/2;i++){ //圈数
			
			if(i*2+1 == m){
				for(int j = i;j <= n-i-1 ;j++) 
					res.push_back(matrix[i][j]);
				return res;	
			}
			if(i*2+1 == n){
				for(int j = i;j <= m-i-1 ;j++)
					res.push_back(matrix[j][n-1-i]);
				return res;
			}
			for(int j = i;j < n-i-1 ;j++) 
				res.push_back(matrix[i][j]);
			for(int j = i;j < m-i-1 ;j++)
				res.push_back(matrix[j][n-1-i]);
			for(int j = i;j < n-i-1 ;j++)
				res.push_back(matrix[m-1-i][n-1-j]);
			for(int j = i;j < m-i-1 ;j++)
				res.push_back(matrix[m-1-j][i]);
		}
		return res;
    }
};