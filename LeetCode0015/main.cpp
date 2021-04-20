//ÌâÄ¿Á´½Ó£ºhttps://leetcode-cn.com/problems/3sum/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());
    	
        if (nums[0] + nums[1] > 0)
            return {};
    	
        const int n = nums.size();
        for (int first = 0; first < n && nums[first] <= 0; ++first)
    	{
        	if (first > 0 && nums[first] == nums[first - 1])
                continue;

            int target = -nums[first];
            int third = n - 1;
        	
            for (int second = first + 1; second < n - 1; ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                while (second < third && nums[second] + nums[third] > target)
                    --third;

            	if (second == third)
                    break;

                if (nums[second] + nums[third] == target)
                    result.push_back({ nums[first], nums[second], nums[third] });
            }
    	}

        return result;
    }
};

int main()
{
    //std::vector<int> nums = { };
    //std::vector<int> nums = { 0 };
    //std::vector<int> nums = { -1,0,1,2,-1,-4 };
    std::vector<int> nums = { 0,0,0,0 };

	Solution s;
    auto result = s.threeSum(nums);
	
	for(auto& item : result)
	{
		if (!item.empty())
			std::cout << item[0] << "," << item[1] << "," << item[2] << std::endl;
	}
    return 0;
}