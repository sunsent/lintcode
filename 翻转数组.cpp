//http://www.lintcode.com/zh-cn/problem/reverse-array/#
class Solution {
public:
    /**
     * @param nums: a integer array
     * @return: nothing
     */
    void reverseArray(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        int half=n/2;
        for(int i=0;i<half;i++){
            nums[i]=nums[i]+nums[n-1-i];
            nums[n-1-i]=nums[i]-nums[n-1-i];//nums[n-1-i]=原来的nums[i]
            nums[i]=nums[i]-nums[n-1-i];
        }
    }
};