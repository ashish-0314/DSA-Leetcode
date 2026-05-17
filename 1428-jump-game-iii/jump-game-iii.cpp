class Solution {
    int n ;
public:
    
    bool solve(int i ,vector<int>& arr ){
        if(i<0 || i >= n || arr[i]<0) return false;
        if(arr[i]==0) return true;
        int jump = arr[i];
        arr[i]*=-1;
        return(solve(i+jump,arr) || solve(i-jump,arr));
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(start,arr);
    }
};