#include <iostream>
using namespace std;

/*
��Ŀ����:
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
		if (!pRoot2) return true;//�������ж�pRoot2
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