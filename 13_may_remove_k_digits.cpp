class Solution {
public:
    string removeKdigits(string num, int k) {
        int newMin = 0;
        int oldMin = -1;
        int l = num.length();
        int toErase = 0;
        while((k>0)&&(newMin<l)){
            
            //get newMin
            newMin = oldMin +1;
            for(int i=oldMin+1;i<=oldMin+1+k;i++)
                if (num[i]<num[newMin]) newMin = i;
                
            // printf("%d %d %d %d %s\n", newMin, oldMin, l, k, num.c_str());
            
            // remove newMin vaala char and modify other indices accordingly
            {
                toErase = newMin-(oldMin+1);
                num.erase(oldMin+1, toErase);
                k -= toErase;
                l -= toErase;
                newMin -= toErase;
            }
            oldMin = newMin;
        }
        if(k>0) num.erase(l-k);
        while(num[0]=='0') num.erase(num.begin());
        if (num.length()<1) return "0";
        return num;
    }
};
