class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int h = nums.size()-1;
        int l = 0;
        int m=(l+h)/2;
        while(l!=h){
            if((m-l)%2==1){
                if(nums[m]!=nums[m+1])
                    l=m+1;
                else
                    h=m-1;
            }
            else{
                if(nums[m]!=nums[m+1])
                    h=m;
                else
                    l=m+2;
            }   
            m = (l+h)/2;
        }
        return nums[l];
    }
};
