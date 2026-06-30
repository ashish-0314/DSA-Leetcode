class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq ;
        int sum = 0 ;
        for(int x : piles){
            pq.push(x);
            sum+=x;
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            int remove = x/2;
            sum-=remove;
            pq.push(x-remove);
        }
        return sum;
    }
};