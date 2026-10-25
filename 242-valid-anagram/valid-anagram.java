class Solution {
    public boolean isAnagram(String s, String t) {
        int[] charcnt = new int[26];
        if(s.length() != t.length()) return false;
        for(int i =0 ; i < s.length() ; i++){
            charcnt[s.charAt(i)-'a']++;
            charcnt[t.charAt(i)-'a']--;
        }
        for(int count : charcnt){
            if(count != 0) return false;
        } 
       return true;
    }
}