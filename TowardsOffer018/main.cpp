#include <iostream>
using namespace std;

/*
��Ŀ����:
���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺Դ������
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		���������
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7  5
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
	void Mirror(TreeNode* pRoot) {
		if (!pRoot) return;
		
		TreeNode* pTempNode = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTempNode;

		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

void printTree(const TreeNode* vTree)
{
	if (!vTree) return;
	else
	{
		cout << vTree->val << " ";
		printTree(vTree->left);
		printTree(vTree->right);
	}
}

//TestCase
int main()
{
	TreeNode* pTree1 = new TreeNode(1);
	pTree1->left = new TreeNode(2);
	pTree1->right = new TreeNode(3);
	pTree1->left->left = new TreeNode(4);
	pTree1->left->right = new TreeNode(5);
	pTree1->right->left = new TreeNode(6);
	pTree1->right->right = new TreeNode(7);
	
	Solution s;
	s.Mirror(pTree1);
	printTree(pTree1);

	return 0;
}