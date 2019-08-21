#include <iostream>
#include <vector>
using namespace std;

/*
题目描述：4. 寻找两个有序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//Method 1: 24ms 10.2MB
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int Nums1Size = nums1.size();
		int Nums2Size = nums2.size();
		if (nums1.empty())
			return Nums2Size % 2 == 0 ? (static_cast<double>(nums2[Nums2Size / 2 - 1]) + static_cast<double>(nums2[Nums2Size / 2])) / 2.0 : static_cast<double>(nums2[(Nums2Size - 1) / 2]);
		else if (nums2.empty())
			return Nums1Size % 2 == 0 ? (static_cast<double>(nums1[Nums1Size / 2 - 1]) + static_cast<double>(nums1[Nums1Size / 2])) / 2.0 : static_cast<double>(nums1[(Nums1Size - 1) / 2]);
		else
		{
			vector<int> TotalNumSet;
			int Nums1Iter = 0, Nums2Iter = 0;
			int TotalNumSize = Nums1Size + Nums2Size;
			int ShutDownIter = TotalNumSize % 2 == 0 ? TotalNumSize / 2 : (TotalNumSize - 1) / 2;

			while (static_cast<int>(TotalNumSet.size()) <= ShutDownIter && (Nums1Iter < Nums1Size || Nums2Iter < Nums2Size))
			{
				if (Nums1Iter >= Nums1Size)
					TotalNumSet.push_back(nums2[Nums2Iter++]);
				else if (Nums2Iter >= Nums2Size)
					TotalNumSet.push_back(nums1[Nums1Iter++]);
				else
					TotalNumSet.push_back(nums1[Nums1Iter] < nums2[Nums2Iter] ? nums1[Nums1Iter++] : nums2[Nums2Iter++]);
			}

			return TotalNumSize % 2 == 0 ? (static_cast<double>(TotalNumSet[TotalNumSize / 2 - 1]) + static_cast<double>(TotalNumSet[TotalNumSize / 2])) / 2.0 : static_cast<double>(TotalNumSet[(TotalNumSize - 1) / 2]);
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { 3, 4 };
	cout << "则中位数是 " << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}