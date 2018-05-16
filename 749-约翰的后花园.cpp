//http://www.lintcode.com/zh-cn/problem/johns-backyard-garden/#
//--------------------------
class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        // write you code here
        if(x%7==0){
            return "YES";
        }
        while(x>0){
            if(x%3==0){
                return "YES";
            }
            x=x-7;
        }
        if(x<0){
            return "NO";
        }
    }
};