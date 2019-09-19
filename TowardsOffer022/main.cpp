#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
题目描述:
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ResultSet;
		queue<TreeNode*> NodeQueue;
		NodeQueue.push(root);
		while (!NodeQueue.empty())
		{
			int Cnt = NodeQueue.size();
			while (Cnt--)
			{
				TreeNode* pTempNode = NodeQueue.front();
				if (!pTempNode) continue;

				ResultSet.push_back(pTempNode->val);
				NodeQueue.push(pTempNode->left);
				NodeQueue.push(pTempNode->right);
			}
		}

		return ResultSet;
	}
};

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
	vector<int> TreeNodeSet = s.PrintFromTopToBottom(pTree1);
	for (auto& i : TreeNodeSet)
		cout << i << " ";

	return 0;
}