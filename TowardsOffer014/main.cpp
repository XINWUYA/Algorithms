#include <iostream>
using namespace std;

/*
��Ŀ����:
����һ����������������е�����k����㡣
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//Method 1: ����˼·������ָ�룬һ��ָ������k-1�����ӵ�k����ʼ������ָ��һ���ߣ�����һ��ָ���ߵ������βʱ����һָ�뼴Ϊ������k����㡣
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* p1 = pListHead, * p2 = pListHead;
		int NodeCnt = 0;
		int i = 0;
		while (p1)
		{
			p1 = p1->next;
			if (i >= k)
				p2 = p2->next;
			i++;
		}
		if (i < k) return nullptr;

		return p2;
	}
};

//TestCase
int main()
{
	ListNode* pList = new ListNode(1);
	ListNode* pTempList = pList;
	for (int i = 1; i < 5; ++i)
	{
		pTempList->next = new ListNode(i + 1);
		pTempList = pTempList->next;
	}

	Solution s;
	cout << s.FindKthToTail(pList, 4)->val;

	return 0;
}