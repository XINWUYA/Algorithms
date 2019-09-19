#include <iostream>
using namespace std;

/*
��Ŀ����:
����һ��������ת��������������ı�ͷ��
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
//Method 1: �ݹ鷨
//class Solution {
//public:
//	ListNode* ReverseList(ListNode* pHead) {
//		if (pHead == NULL || pHead->next == NULL) return pHead;
//
//		ListNode* pReverseHead = ReverseList(pHead->next);
//		pHead->next->next = pHead;
//		pHead->next = nullptr;
//		
//		return pReverseHead;
//	}
//};

//Method 2��ͷ�巨
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReverseHead = nullptr;
		while (pHead != nullptr)
		{
			ListNode* pNext = pHead->next;
			pHead->next = pReverseHead;
			pReverseHead = pHead;
			pHead = pNext;
		}
		return pReverseHead;
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
	ListNode* pReverseList = s.ReverseList(pList);
	for (int i = 0; i < 5; ++i)
	{
		cout << pReverseList->val << " ";
		pReverseList = pReverseList->next;
	}
	return 0;
}