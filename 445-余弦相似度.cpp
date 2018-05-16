http://www.lintcode.com/zh-cn/problem/cosine-similarity/#
class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Cosine similarity
     */
    double cosineSimilarity(vector<int> &A, vector<int> &B) {
        // write your code here
        if(A.size()==0) return 2.0000;
        double AmulB=0.0;
        double A2=0.0;
        double B2=0.0;
        for(int i=0;i<A.size();i++){
            AmulB=AmulB+(A[i]*B[i]);
            A2=A2+(A[i]*A[i]);
            B2=B2+(B[i]*B[i]);
        }
        double a2=sqrt(A2);
        double b2=sqrt(B2);
        if(a2==0||b2==0){
            return 2.0000;
        }
        return (AmulB/(a2*b2));
    }
};