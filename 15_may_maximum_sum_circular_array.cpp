class Solution {
public:
    int max(int a, int b){
        if(a>b) 
            return a;
        else 
            return b;
    }
    
    int maxSubarraySumCircular(vector<int>& A){
        int maxHere = A[0];
        int maxSum = A[0];
        int l = A.size();
        
        // if our solution subarray is non wrapping
        for(int i=1;i<l;i++){
            maxHere = max(A[i], maxHere+A[i]);
            maxSum = max(maxSum, maxHere);
        }
        
        // if our solution subarray is wrapping
        int total = 0;
        for(int i=0;i<l;i++) {
            total+=A[i];
            A[i]*=-1;
        }
        
        int maxHereRev = A[0];
        int maxSumRev = A[0];
        for(int i=1;i<l;i++){
            maxHereRev = max(A[i], maxHereRev+A[i]);
            maxSumRev = max(maxSumRev, maxHereRev);
        }
        if(maxSumRev+total == 0)
            return maxSum;
        else
            maxSumRev = total + maxSumRev;
        cout<<maxSumRev;
        return max(maxSum, maxSumRev);
    }
    
    /* BRUTE FORCE
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = A[0];
        int sum = 0;
        int l = A.size();
        for(int i=0;i<l;i++){
            sum = 0;
            for(int j=0;j<=i;j++) sum += A[j];
            if(sum>maxSum) 
                maxSum = sum;
            for(int j=1;j<l;j++){
                sum = sum + A[(i+j)%l] - A[(j-1)%l];
                if(sum>maxSum) 
                    maxSum = sum;
            }
        }
        return maxSum;
    }
    */
};
