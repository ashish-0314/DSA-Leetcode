class Solution {
public:
    bool check(int x){
        if(x==0) return false;
        int freq[10]={0};

        int temp = x;
        while(temp>0){
            int digit = temp%10;
            freq[digit]++;
            temp/=10;
        }

        for(int i = 0 ; i< 10 ; i++){
            if(freq[i]>0){
                if(freq[i]!=i) return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n+1 ; ; i++){
            if(check(i)) return i;
        }
    }
};