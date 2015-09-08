/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/


 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

 struct IntervalNode{ 
	int start;
	int end;
	int cover;
	IntervalNode * left,*right;
	IntervalNode():start(0),end(0),cover(0),left(NULL),right(NULL){}
	IntervalNode(int s,int e,int c,IntervalNode *l,IntervalNode *r):start(s),end(e),cover(c),left(l),right(r){}
};

IntervalNode *build(int start,int end){ 
	IntervalNode *root = new IntervalNode(start,end,0,NULL,NULL);
	if(start+1 < end){ 
		int mid = (start+end)>>1;
		root->left = build(start,mid);
		root->right = build(mid,end);
	}else if(start+1 == end){ 
		root->left  = new IntervalNode(start,start,0,NULL,NULL);
		root->right = new IntervalNode(end,end,0,NULL,NULL);
	}
	return root;
}
void deletetree(IntervalNode * root){ 
	if(root == NULL) return;
	if(root->left)
		deletetree(root->left);
	if(root->right)
		deletetree(root->right);
	delete root;
}
void Insert(IntervalNode *root,int s,int e){ 
	if(root && root->cover == 0){ 
		auto m = (root->start+root->end) >> 1;
		if(s == root->start && e ==root->end)
			root->cover = 1;
		else if(e <= m) Insert(root->left,s,e);
		else if(m <= s) Insert(root->right,s,e);
		else{ 
			Insert(root->left,s,m);
			Insert(root->right,m,e);
		}
	}
}
void traversal(IntervalNode *root,vector<Interval> &res,Interval &temp){
	if(root == NULL) return;
	if(root->cover == 1){
		if(root->start > temp.end){ 
			res.push_back(temp);
			temp.start = root->start;
			temp.end = root->end;
		}
		else
			temp.end = root->end;
	}
	else{
		traversal(root->left,res,temp);
		traversal(root->right,res,temp);
	}
}


class Solution {
public:
	//Solution 1:Interval-tree
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		if(intervals.size() == 0) return res;
		int minleft = INT_MAX,maxright=INT_MIN;
		for(auto &it : intervals){
			minleft = min(minleft,it.start);
			maxright = max(maxright,it.end);
		}
		Interval temp = Interval(minleft,minleft);
		IntervalNode *root = build(minleft,maxright);
		for(auto &it : intervals)
			Insert(root,it.start,it.end);
		traversal(root,res,temp);
		res.push_back(temp);
		deletetree(root);
		return res;
	}
	//Solution 2:sort
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),comp());
		vector<Interval> res;
		if(intervals.size() == 0) return res;
		Interval temp = intervals[0];
		for(auto it = intervals.begin();it != intervals.end();++it){
			if(it->start > temp.end){
				res.push_back(temp);
				temp = *it;
			}else{
				temp.end = max(it->end,temp.end);
			}

		}
		res.push_back(temp);
		return res;
    }
    struct comp{ 
    	bool operator()(const Interval &I1,const Interval &I2) const { 
    		return I1.start<I2.start ;//|| (I1.start == I2.start && I1.end < I2.end);
    	}
    };
};