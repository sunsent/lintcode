http://www.lintcode.com/zh-cn/problem/string-sort/#
//------------------------------冒泡,暴力
class Solution {
public:
    /**
     * @param str: the string that needs to be sorted
     * @return: sorted string
     */
    string stringSort(string &str) {
        // Write your code here
        int sum[26];//记录每个字母出现的次数
        string result="";
        if(str.size()==0) return str;
        for(int i=0;i<26;i++){
            sum[i]=0;
        }
        for(int i=0;i<str.size();i++){//记录每个字母出现的次数
            char ch=str[i];
            int num=ch-'a';
            sum[num]++;
        }
        for(int i=0;i<str.size()-1;i++){
            int flag=0;
            for(int j=0;j<str.size()-1-i;j++){
                //char ch=str[j];
                //char ch2=str[j+1];
                int num1=str[j]-'a';
                int num2=str[j+1]-'a';
                if(sum[num1]<sum[num2]){//以最常用的字符为第一关键字
                    char temp=str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                    flag=1;
                }
                else if(sum[num1]==sum[num2]){
                    if(num1>num2){//字典顺序为第二关键字排序
                        char temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                        flag=1;
                    }
                }
            }
            if(flag==0){
                i=str.size();
            }
        }
        return str;
    }
};