#include <iostream>
using namespace std;

/*
题目描述:
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2) return false;
		return __isSubtreeWithRoot(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
private:
	bool __isSubtreeWithRoot(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot2) return true;//必须先判断pRoot2
		if (!pRoot1) return false;
		if (pRoot1->val != pRoot2->val) return false;
		return __isSubtreeWithRoot(pRoot1->left, pRoot2->left) && __isSubtreeWithRoot(pRoot1->right, pRoot2->right);
	}
};

int main()
{
	TreeNode* pTree1 = new TreeNode(1);
	pTree1->left = new TreeNode(2);
	pTree1->right = new TreeNode(3);

	TreeNode* pTree2 = new TreeNode(3);
	
	Solution s;
	cout << s.HasSubtree(pTree1, pTree2);
	return 0;
}