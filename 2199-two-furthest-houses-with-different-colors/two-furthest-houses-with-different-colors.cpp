class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxdist = -1;
        for(int i = 0 ; i< colors.size() ; i++){
            for(int j =i+1 ; j < colors.size() ; j++ ){
                if(colors[i]!=colors[j]){
                    int x = abs(j-i);
                    maxdist = max(x,maxdist);
                }
            }
        }
        return maxdist;
    }
};