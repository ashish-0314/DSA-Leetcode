class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid){
        int curr = mid;
        for(auto& task : tasks){
            int actual = task[0];
            int mini = task[1];

            if(curr<mini) return false;
            curr-=actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int l = 0 ;
        int r = 1e9;
        int res = INT_MAX;
        auto lambda=[](auto &task1 , auto &task2){
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];
            return diff1>diff2;
        };
        sort(tasks.begin(),tasks.end(),lambda);
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(tasks,mid)){
                res= mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};