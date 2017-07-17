//给当一个二叉搜索树。写一个程序来查找其中的第K个最小元素
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

struct  TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution1 {
public:
	int kthSmallest(TreeNode *root,int k) {
		int result = 0;
		int index = 0;
		InOrder(root, k, index, result);
		return result;
	}

private:
	void InOrder(TreeNode *root, int k, int &index, int &result) {
		if (root) {
			InOrder(root->left, k, index, result);
			++index;
			if (index == k) {
				result = root->val;
			}
				InOrder(root->right, k, index, result);
		}
	}
};

class Solution2 {
public:
	int kthSmallest(TreeNode *root, int k) {
		return InOrder(root, k);
	}

	int InOrder(TreeNode *root, int &k) {
		if (!root) 
			return -1;
		int val = InOrder(root->left, k);
		if (!k) 
			return val;
		if (!--k) 
			return root->val;
		return InOrder(root->right, k);
	}
};

class Solution3 {	//非递归方法
public:
	int kthSmallest(TreeNode *root, int k) {
		int index = 0;
		TreeNode *cur = root;
		stack<TreeNode*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			index++;
			if (index == k)
				return cur->val;
			cur = cur->right;
		}
		return 0;
	}
};



int main()
{
	Solution1 s;
	Solution2 x;
	Solution2 w;

	int k;
	cin >> k;
	TreeNode *root = new TreeNode(5);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(9);
	TreeNode *node5 = new TreeNode(6);
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(11);

	root->left = node2;
	root->right = node4;
	node2->left = node1;
	node2->right = node3;
	node4->left = node5;
	node4->right = node7;
	node5->right = node6;

	cout << s.kthSmallest(root, k) << endl;
	cout << x.kthSmallest(root, k) << endl;
	cout << w.kthSmallest(root, k) << endl;

	return 0;
}