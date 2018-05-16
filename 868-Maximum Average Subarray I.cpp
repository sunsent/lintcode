//http://www.lintcode.com/zh-cn/problem/maximum-average-subarray-i/#
//-------------------------
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        // Write your code here
        double result;
        double max_sum=0;
        if(nums.size()<=k){
            for(int i=0;i<nums.size();i++){
                max_sum=nums[i]+max_sum;
            }
            result=max_sum/nums.size();
            return result;
        }
        queue<int> k_nums;
        for(int i=0;i<k;i++){
            k_nums.push(nums[i]);
            max_sum=nums[i]+max_sum;
        }//先把前k个加起来,并用队列保存前k个数
        double max_temp=max_sum;
        for(int i=k;i<nums.size();i++){//每次减去队列第一个,再加上新的数
            double first=k_nums.front();
            k_nums.pop();
            k_nums.push(nums[i]);
            max_temp=max_temp-first+nums[i];
            if(max_temp>max_sum){//然后与之前最大值比较
                max_sum=max_temp;
            }
        }
        return max_sum/k;
    }
};