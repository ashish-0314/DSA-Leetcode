class Solution {
public:

    long long calcTh(vector<int>& piles, int h){
        long long th = 0 ;
        for(int num: piles){
            th+= (num+h-1)/h;
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = (low+high)/2;
            long long totalH = calcTh(piles,mid);
            if(totalH <=h) high = mid-1;
            else low = mid+1;
        }
        return low ;
    }
};