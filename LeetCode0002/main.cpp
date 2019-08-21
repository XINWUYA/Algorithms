#include <iostream>

/*
题目描述：2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//Method 1: 40ms 10.3MB
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* pResultNode = new ListNode(0);
//		ListNode* pCalculatingNode = pResultNode;
//		pCalculatingNode->val = l1->val + l2->val;
//		int Carry = 0;
//		Carry = pCalculatingNode->val / 10;
//		pCalculatingNode->val %= 10;
//
//		l1 = l1->next;
//		l2 = l2->next;
//		while (l1 != NULL || l2 != NULL)
//		{
//			pCalculatingNode->next = new ListNode(0);
//			pCalculatingNode = pCalculatingNode->next;
//			if (l1 == NULL)
//			{
//				pCalculatingNode->val = l2->val + Carry;
//				l2 = l2->next;
//			}
//			else if (l2 == NULL)
//			{
//				pCalculatingNode->val = l1->val + Carry;
//				l1 = l1->next;
//			}
//			else
//			{
//				pCalculatingNode->val = l1->val + l2->val + Carry;
//				l1 = l1->next;
//				l2 = l2->next;
//			}
//			Carry = pCalculatingNode->val / 10;
//			pCalculatingNode->val %= 10;
//		}
//
//		if(Carry > 0)
//			pCalculatingNode->next = new ListNode(Carry);
//
//		return pResultNode;
//	}
//};

//Method 2: 40ms 10.4MB
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pResultNode = new ListNode(0);
		ListNode* pCalculatingNode = pResultNode;

		int Carry = 0;
		while (l1 || l2)
		{
			int Sum = 0;
			if (l1)
			{
				Sum += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				Sum += l2->val;
				l2 = l2->next;
			}
			if (Carry) 
				Sum += Carry;
			
			Carry = Sum / 10;

			pCalculatingNode->next = new ListNode(Sum % 10);
			pCalculatingNode = pCalculatingNode->next;
		}
		if(Carry)
			pCalculatingNode->next = new ListNode(1);

		return pResultNode->next;
	}
};

int main()
{
	ListNode* pl1 = new ListNode(2);
	pl1->next = new ListNode(4);
	pl1->next->next = new ListNode(3);
	ListNode* pl2 = new ListNode(5);
	pl2->next = new ListNode(6);
	pl2->next->next = new ListNode(6);

	Solution s;
	ListNode* pResult = s.addTwoNumbers(pl1, pl2);
	while (pResult)
	{
		std::cout << pResult->val << " ";
		pResult = pResult->next;
	}
	return 0;
}