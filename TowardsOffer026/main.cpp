#include <iostream>
#include <stack>
using namespace std;

/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//Method 1: 递归法
//class Solution {
//public:
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		__convertInOrder(pRootOfTree);
//
//		return m_pHead;
//	}
//
//private:
//	void __convertInOrder(TreeNode* pRoot)
//	{
//		if (!pRoot) return;
//
//		__convertInOrder(pRoot->left);
//		pRoot->left = m_pPre;
//		
//		if (m_pPre) m_pPre->right = pRoot;
//
//		m_pPre = pRoot;
//
//		if (!m_pHead) m_pHead = pRoot;
//
//		__convertInOrder(pRoot->right);
//	}
//
//	TreeNode* m_pHead = nullptr;
//	TreeNode* m_pPre = nullptr;
//};

//Method 2: 非递归法
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		stack<TreeNode*> TreeNodeStack;
		TreeNode* pTemp = pRootOfTree;
		TreeNode* pPre = nullptr;
		TreeNode* pResult = nullptr;
		bool IsHead = true;

		while (pTemp || !TreeNodeStack.empty())
		{
			while (pTemp)
			{
				TreeNodeStack.push(pTemp);
				pTemp = pTemp->left;
			}

			pTemp = TreeNodeStack.top();
			TreeNodeStack.pop();

			if (IsHead)
			{
				pResult = pTemp;
				pPre = pResult;
				IsHead = false;
			}
			else
			{
				pPre->right = pTemp;
				pTemp->left = pPre;
				pPre = pTemp;
			}

			pTemp = pTemp->right;
		}

		return pResult;
	}
};

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
	TreeNode* pNewList = s.Convert(pTree1);
	while (pNewList)
	{
		cout << pNewList->val << " ";
		pNewList = pNewList->right;
	}

	return 0;
}