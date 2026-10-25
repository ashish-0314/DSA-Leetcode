class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums) set.add(num);
        int ans = 0 ;
        for(int s : set){
            if(!set.contains(s-1)){
                int cnt = 1 ;
                int x = s;
                while(set.contains(x+1)){
                    cnt+=1;
                    x+=1;
                }
                ans = Math.max(cnt,ans);
            }
        }
        return ans;
    }
}