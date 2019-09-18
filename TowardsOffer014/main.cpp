#include <iostream>
using namespace std;

/*
题目描述:
输入一个链表，输出该链表中倒数第k个结点。
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//Method 1: 解题思路：两个指针，一个指针先走k-1步，从第k步开始，两个指针一起走，当第一个指针走到链表结尾时，后一指针即为倒数第k个结点。
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