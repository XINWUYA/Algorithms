#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目描述：5.最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入 : "babad"
输出 : "bab"
注意 : "aba" 也是一个有效答案。
示例 2：

输入 : "cbbd"
输出 : "bb"

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//Method 1：中心扩展方法 40ms 104.2MB
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.empty())
//			return "";
//
//		auto expandAroundCenter = [](string s, int left, int right)->int
//		{
//			int IndexL = left, IndexR = right;
//			while (IndexL >= 0 && IndexR <= (int)s.size() && s[IndexL] == s[IndexR])
//			{
//				IndexL--;
//				IndexR++;
//			}
//			return IndexR - IndexL - 1;
//		};
//
//		int Start = 0, End = 0;
//		for (unsigned int i = 0; i < s.size(); ++i)
//		{
//			int Len1 = expandAroundCenter(s, i, i);
//			int Len2 = expandAroundCenter(s, i, i + 1);
//
//			int Len = max(Len1, Len2);
//
//			if (Len > End - Start)
//			{
//				Start = i - (Len - 1) / 2;
//				End = i + Len / 2;
//			}
//		}
//
//		return s.substr(Start, End - Start + 1);
//	}
//};

//Method 2: Manacher's Algorithm 8ms 9.8MB
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";

		string ManaStr = "$#";
		for (auto& ch : s)
		{
			ManaStr += ch;
			ManaStr += '#';
		}
		
		int ManaStrLen = ManaStr.length();
		vector<int> RadiusSet(ManaStrLen, 0);
		int MaxLen = 0, MaxPos = 0;
		int Right = 0, CurrentPos = 0;
		for (int i = 1; i < ManaStrLen; ++i)
		{
			if (i < Right)
				RadiusSet[i] = min(Right - i, RadiusSet[2 * CurrentPos - i]);//避免当i超过Right时，Radius计算错误
			while (ManaStr[i - RadiusSet[i] - 1] == ManaStr[i + RadiusSet[i] + 1])//中心扩展
				++RadiusSet[i];
			if (i + RadiusSet[i] > Right)//更新最右端和当前位置
			{
				Right = i + RadiusSet[i];
				CurrentPos = i;
			}
			if (RadiusSet[i] > MaxLen)//记录最长子串的位置
			{
				MaxLen = RadiusSet[i];
				MaxPos = i;
			}
		}

		return s.substr((MaxPos - MaxLen) / 2, MaxLen);
	}
};

//TestCase
int main()
{
	Solution s;
	string Str = "adccda";
	cout << s.longestPalindrome(Str) << endl;
	return 0;
}