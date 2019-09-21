#include <iostream>
using namespace std;
/*
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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

		//1.��ÿ���ڵ������븴�ƵĽڵ�
		RandomListNode* pTempList = pHead;
		while (pTempList)
		{
			RandomListNode* pNewNode = new RandomListNode(pTempList->label);
			pNewNode->next = pTempList->next;
			pTempList->next = pNewNode;
			pTempList = pNewNode->next;
		}

		//2.�Ը��ƽڵ��random���ӽ��и�ֵ
		pTempList = pHead;
		while (pTempList)
		{
			RandomListNode* pNewNode = pTempList->next;
			if (pTempList->random)
				pNewNode->random = pTempList->random->next;//pNewNode->randomӦָ��pTempList->random�Ŀ�������pTempList->random->next
			pTempList = pNewNode->next;
		}

		//3.���
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