#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目描述：3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//Method 1: 8ms 9.2MB
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		if (s.empty()) return 0;
//
//		int AddrTemp = 0;
//		int MaxLen = 0;
//
//		for (int AddrA = 0; AddrA < (int)s.size(); ++AddrA)
//		{
//			for (int AddrB = AddrTemp; AddrB < AddrA; ++AddrB)
//			{
//				if (s[AddrB] == s[AddrA])
//				{
//					AddrTemp = AddrB + 1;
//					break;
//				}
//			}
//			MaxLen = max(MaxLen, AddrA - AddrTemp + 1);
//		}
//
//		return MaxLen;
//	}
//};

//Method 2: 8ms 9.7MB
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;

		vector<int> AsciiSet(128, -1);
		int PreSameCharAddr = -1;	
		int MaxLen = 0;

		for (int i = 0; i < (int)s.size(); ++i)
		{
			PreSameCharAddr = max(PreSameCharAddr, AsciiSet[s[i]]);
			AsciiSet[s[i]] = i;
			MaxLen = max(MaxLen, i - PreSameCharAddr);
		}

		return MaxLen;
	}
};

int main()
{
	Solution s;
	string Str = "pwwkew";
	std::cout << s.lengthOfLongestSubstring(Str) << std::endl;
	return 0;
}