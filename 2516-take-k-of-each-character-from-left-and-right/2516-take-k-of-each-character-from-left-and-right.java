class Solution {
    public int takeCharacters(String s, int k) {
        int[] cnt = new int[3];

        for(char c : s.toCharArray())
            cnt[c - 'a']++;
        if (Math.min(Math.min(cnt[0], cnt[1]), cnt[2]) < k)
            return -1;

        int ans = Integer.MAX_VALUE;
        int l = 0;
        for(int r = 0; r < s.length(); ++r) {
            cnt[s.charAt(r) - 'a']--;

            while (Math.min(Math.min(cnt[0], cnt[1]), cnt[2]) < k){
                cnt[s.charAt(l) - 'a']++;
                ++l;
            }
            ans = Math.min(ans, s.length() - (r - l + 1));
        }
        return ans;
    }
}