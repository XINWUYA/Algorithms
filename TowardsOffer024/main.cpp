#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
��Ŀ����:
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root) 
			return m_ListsSet;

		auto compareFunc = [](const vector<int>& vLeft, const vector<int>& vRight)
		{
			return vLeft.size() > vRight.size();
		};

		__findPathRecursively(root, expectNumber);

		sort(m_ListsSet.begin(), m_ListsSet.end(), compareFunc);

		return m_ListsSet;
	}
private:
	void __findPathRecursively(TreeNode* root, int expectNumber)
	{
		if (!root || root->val > expectNumber) return;

		m_List.push_back(root->val);

		if (root->val == expectNumber && !root->left && !root->right)
			m_ListsSet.push_back(m_List);

		__findPathRecursively(root->left, expectNumber - root->val);
		__findPathRecursively(root->right, expectNumber - root->val);

		m_List.pop_back();
	}

	vector<int> m_List;
	vector<vector<int>> m_ListsSet;
};

int main()
{
	TreeNode* pTree1 = new TreeNode(10);
	pTree1->left = new TreeNode(12);
	pTree1->right = new TreeNode(5);
	pTree1->right->left = new TreeNode(4);
	pTree1->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int>> ListsSet = s.FindPath(pTree1, 22);

	for (auto& Item : ListsSet)
	{
		for (auto& i : Item)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}