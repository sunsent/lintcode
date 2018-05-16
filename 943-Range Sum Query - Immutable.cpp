//http://www.lintcode.com/zh-cn/problem/range-sum-query-immutable/#
//------------------------------
class NumArray {
public:
    vector<vector<int>> num_array;
    NumArray(vector<int> nums) {
        num_array.push_back(nums);
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        for(int a=i;a<=j;a++){
            sum=num_array[0][a]+sum;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */