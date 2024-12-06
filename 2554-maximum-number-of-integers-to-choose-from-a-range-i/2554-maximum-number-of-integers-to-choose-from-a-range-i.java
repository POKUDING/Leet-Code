class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        int ans = 0;
        int banIdx = 0;
        int sum = 0;
        Set<Integer> set = new HashSet<>();

        for(int ban : banned)
            set.add(ban);

        for(int i = 1; i <= n; ++i) {
            if(set.contains(i)) {
                continue;
            }
            if(sum + i > maxSum)
                break;
            sum += i;
            ++ans;
        }
        return ans;
    }
}