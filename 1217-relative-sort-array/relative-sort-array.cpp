class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int &num : arr1) mp[num]++;
        int i = 0;
        for(int &num : arr2){
            while(mp[num]>0){
                arr1[i]=num;
                i++;
                mp[num]--;
            }
        }
        for(auto &it : mp){
            int freq = it.second;
            while(freq>0){
                arr1[i]= it.first;
                i++;
                freq--;
            }
        }
        return arr1;
    }
};