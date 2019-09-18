#include <iostream>
#include <vector>
using namespace std;

/*
��Ŀ����:
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/

//Method 1: ����˼·������ n-1 ��̨�ף����Դ� n-2 ���� 1 ����ȥ��Ҳ���Դ� n-3 ���� 2 ����ȥ...����ôf(n-1) = f(n-2) + f(n-3) + ... + f(0)
//ͬ������ n ��̨�ף����Դ� n-1 ���� 1 ����ȥ��Ҳ���Դ� n-2 ���� 2 ����ȥ... ����ôf(n) = f(n-1) + f(n-2) + ... + f(0)
//��ˣ�f(n) = 2*f(n-1)���Ǹ��ȱ�����
class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (number - 1);
	}
};

//Method 2: ��̬�滮��
//class Solution {
//public:
//	int jumpFloorII(int number) {
//		vector<int> dp(number, 1);
//		for (int i = 1; i < number; i++)
//		{
//			for (int j = 0; j < i; j++)
//				dp[i] += dp[j];
//		}
//		return dp[number - 1];
//	}
//};

int main()
{
	Solution s;
	for(int i = 1; i < 10; ++i)
		cout << s.jumpFloorII(i) << " ";
	return 0;
}