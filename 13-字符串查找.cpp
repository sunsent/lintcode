//http://www.lintcode.com/zh-cn/problem/strstr/
//----------------------暴力匹配
int strStr(const char source, const char target) {
// write your code here
int sourceSize,targetSize;
if(source==NULL||target==NULL) return -1;
sourceSize=strlen(source);

    targetSize=strlen(target);



    //if(targetSize==0&&sourceSize==0) return 0;

    int s=0;
    int t=0;
    int location;// target 字符串出现的第一个位置
    while(t<targetSize&&s<sourceSize){
        if(target[t]==source[s]){
            location=s;
            t++;
            s++;
        }
        else{
            s=s-t+1;
            t=0;
        }
    }
    if(t==targetSize){
        return s-t;
    }
    else{
        return -1;
    }
}