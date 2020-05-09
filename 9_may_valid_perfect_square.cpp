class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 0;
        long long int h = num;
        long long int t = h/2;
        if(num<0){
            return false;
        }
        else if((num==0)||(num==1)){
            return true;
        }
        else{
            while(l<t){
                if(h*h==num)
                    return true;
                else if(h*h>num && t*t>=num)
                    h = t;
                else 
                    l = t;
                t = (l+(h-l)/2);
                printf("%d,%d,%d ",l,t,h);
            }
            if(h*h==num) return true;
            return false;            
        }
        
    }
};
