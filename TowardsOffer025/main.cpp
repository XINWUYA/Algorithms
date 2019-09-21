#include <iostream>
using namespace std;
/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead) return NULL;

		//1.在每个节点后面插入复制的节点
		RandomListNode* pTempList = pHead;
		while (pTempList)
		{
			RandomListNode* pNewNode = new RandomListNode(pTempList->label);
			pNewNode->next = pTempList->next;
			pTempList->next = pNewNode;
			pTempList = pNewNode->next;
		}

		//2.对复制节点的random链接进行赋值
		pTempList = pHead;
		while (pTempList)
		{
			RandomListNode* pNewNode = pTempList->next;
			if (pTempList->random)
				pNewNode->random = pTempList->random->next;//pNewNode->random应指向pTempList->random的拷贝，即pTempList->random->next
			pTempList = pNewNode->next;
		}

		//3.拆分
		pTempList = pHead;
		RandomListNode* pClonedHead = pHead->next;
		while (pTempList->next)
		{
			RandomListNode* pNextNode = pTempList->next;
			pTempList->next = pNextNode->next;
			pTempList = pNextNode;
		}

		return pClonedHead;
	}
};

//TestCase
int main()
{
	RandomListNode* pHead = new RandomListNode(1);
	pHead->next = new RandomListNode(2);
	pHead->next->next = new RandomListNode(3);

	Solution s;
	RandomListNode* pNewHead = s.Clone(pHead);

	RandomListNode* pTemp = pHead;
	while (pTemp)
	{
		cout << pTemp->label << " ";
		pTemp = pTemp->next;
	}
	cout << endl;

	pTemp = pNewHead;
	while (pTemp)
	{
		cout << pTemp->label << " ";
		pTemp = pTemp->next;
	}
	cout << endl;

	return 0;
}