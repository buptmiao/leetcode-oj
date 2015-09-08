/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

class Solution {
public:
	//Solution 1 ：交换位置
	void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
		for(int i = 0;i < n/2; i++){  //从最外层到最里层
			for(int j = i;j < n-i-1; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n-j-1][i];
				matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
				matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
				matrix[j][n-i-1] = temp;
			}
		}
    }
    //Solution 2：tricks
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());//先逆序在交换，顺时针旋转90度；先交换在逆序，逆时针旋转90度
        for (unsigned i = 0; i < matrix.size(); ++i)
            for (unsigned j = i+1; j < matrix[i].size(); ++j)
                swap (matrix[i][j], matrix[j][i]);
    }
};