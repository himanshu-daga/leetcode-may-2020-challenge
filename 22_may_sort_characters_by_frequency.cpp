class Solution {
public:
    
    void merge(vector<int> &v, vector<char>& c, int l, int r){
        int m = (l+r)/2;
        int n1 = m-l+1;
        int n2 = r-m;
        int vl[n1], vr[n2];
        char cl[n1], cr[n1];
        int i,j,k;
        
        for (i = 0; i < n1; i++){
            vl[i] = v[l + i];
            cl[i] = c[l+i];
        }            
        for (j = 0; j < n2; j++) {
            vr[j] = v[m + 1+ j];
            cr[j] = c[m+1+j];
        }
        
        i = 0; 
        j = 0; 
        k = l;
        while (i < n1 && j < n2) 
        { 
            if (vl[i] >= vr[j]) 
            { 
                v[k] = vl[i];
                c[k] = cl[i];
                i++; 
            } 
            else
            { 
                v[k] = vr[j]; 
                c[k] = cr[j];
                j++; 
            } 
            k++;
        }
        
        while (i < n1) 
            { v[k] = vl[i]; c[k] = cl[i]; i++;k++;  }
        while (j < n2) 
            { v[k] = vr[j]; c[k] = cr[j]; j++; k++; } 
    }

    
    void mergeSort(vector<int> &v, vector<char>& c, int l, int h){
        if(l<h){
            mergeSort(v,c,l,(h+l)/2);
            mergeSort(v,c,(h+l)/2 + 1, h);
            merge(v,c,l,h);
        }
    }
    
    
    string frequencySort(string s) {
        int l = s.size();
        vector<int> v(128,0);
        vector<char> c(128);
        for(int i=0;i<128;i++)
            c[i] = char(i);
        for(int i=0;i<l;i++)
            v[int(s[i])]++;
        
        mergeSort(v,c,0,127);
        
        string ans;
        for(int i=0;i<62;i++){
            for(int f=0;f<v[i];f++)
                ans.push_back(c[i]);
        }
        return ans;
    // BRUTE FORCE
        // int i=0,max=0;
        // while(i<l){
        //     for(int j=0;j<52;j++){
        //         if(v[j]>v[max]){
        //             max=j;
        //         }
        //     }
        //     for(int j=0;j<v[max];j++){
        //         if(max<26)
        //             s[i] = 'a'+max;
        //         else
        //             s[i] = 'A'+max-26;
        //         i++;
        //     }
        //     v[max]=0;
        // }
        // return s;
        
    }
};
