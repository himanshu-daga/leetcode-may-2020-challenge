class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1,0);
        
        int j = 0;
        for(int i=1;i<=num;i++){
            j++;
            if( log2(i)-int(log2(i))==0 ){
                v[i] = 1;
                j = 0;
            }
            else if(i%2==1)
                v[i] = v[i-1] + 1;
            else{
                v[i] = v[j] + 1;
            }
        }
        return v;
    }
};
