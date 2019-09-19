#include <iostream>
using namespace std;

/*
题目描述:
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//Method 1： 迭代法
//class Solution {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		ListNode* pTempHead = new ListNode(-1);
//		ListNode* pMergedHead = pTempHead;
//
//		while (pHead1 || pHead2)
//		{
//			if (!pHead1)
//			{
//				pTempHead->next = pHead2;
//				break;
//			}
//			if (!pHead2)
//			{
//				pTempHead->next = pHead1;
//				break;
//			}
//			if (pHead1->val <= pHead2->val)
//			{
//				pTempHead->next = pHead1;
//				pHead1 = pHead1->next;
//			}
//			else
//			{
//				pTempHead->next = pHead2;
//				pHead2 = pHead2->next;
//			}
//			pTempHead = pTempHead->next;
//		}
//
//		return pMergedHead->next;
//	}
//};

//Method 2：递归法
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1) return pHead2;
		if (!pHead2) return pHead1;
		if (pHead1->val <= pHead2->val)
		{
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else
		{
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
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

	ListNode* pList2 = new ListNode(1);
	pTempList = pList2;
	for (int i = 1; i < 5; ++i)
	{
		pTempList->next = new ListNode(i + 1);
		pTempList = pTempList->next;
	}

	Solution s;
	ListNode* pMergedList = s.Merge(pList, pList2);
	while (pMergedList)
	{
		cout << pMergedList->val << " ";
		pMergedList = pMergedList->next;
	}

	return 0;
}