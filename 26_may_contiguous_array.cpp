class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int l = nums.size();
        if(l<2)
            return 0;
        
        int min, max;
        max = (nums[0]==1)? 1:-1;
        min = (nums[0]==1)? 1:-1;    
            
        vector<int> v(l,0);
        v[0] = (nums[0]==0)? -1 : 1;
        for(int i=1;i<l;i++){
            v[i] = (nums[i]==1)? v[i-1]+1 : v[i-1]-1;
            if(v[i]>max) max = v[i];
            if(v[i]<min) min = v[i];
        }
        
        int ans = 0;
        for(int i=l-1;i>=0;i--){
            if(v[i]==0){
                ans = i+1;
                break;
            }
        }
        // hash index = sum-min and stores start index when that sum is found first
        vector<int> hash(max-min+1,-1);
        for(int i=0;i<l;i++){
            if(hash[v[i]-min]==-1)
                hash[v[i]-min] = i;
            else if(i-hash[v[i]-min]>ans)
                ans = i-hash[v[i]-min];
        }
        return ans;
        
        // BRUTE FORCE
        // int max = 0;
        // for(int i=0;i<l;i++)
        //     for(int j=i+1;j<l;j++)
        //         if((j-i)%2==1){
        //             if( (nums[i]==0) && ((v[j]-(v[i]+1))==0) && (j-i+1>max) )
        //                 max = j-i+1;
        //             else if( (nums[i]==1) && ((v[j]-(v[i]-1))==0) && (j-i+1>max) )
        //                 max = j-i+1;
        //         } 
        // return max;
    }
};
