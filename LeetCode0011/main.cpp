//ÌâÄ¿Á´½Ó£ºhttps://leetcode-cn.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        if (height.size() <= 1)
            return 0;

        int result = 0, left = 0, right = height.size() - 1;
    	while(left < right)
    	{
            int current = 0;
            if (height[left] < height[right])
            {
                current = height[left] * (right - left);
                left++;
            }
            else
            {
                current = height[right] * (right - left);
                right--;
            }
            result = current > result ? current : result;
        }
    	
        return result;
    }
};

int main()
{
    //std::vector<int> height{ 1,1 };  // Ref result: 1
    //std::vector<int> height{ 4,3,2,1,4 };  // Ref result: 16
    std::vector<int> height{ 1,8,6,2,5,4,8,3,7 };  // Ref result: 49

    Solution s;
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}