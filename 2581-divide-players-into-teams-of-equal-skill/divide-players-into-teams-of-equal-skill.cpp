class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        long long k = accumulate(skill.begin(),skill.end(),0)/((skill.size())/2);
        long long ans = 0 ;
        sort(skill.begin(),skill.end());
        int l = 0 , r = skill.size()-1;
        while(l<r){
            if(skill[l]+skill[r]!=k) return -1;
            ans+= 1LL * skill[l] * skill[r];
            l++;
            r--;
        }
        return ans;
    }
};