class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        for(int i = 0; i < k; ++i) {
            int currHappy = happiness[happiness.length - 1 - i] - i;
            ans += currHappy < 0 ? 0 : currHappy;
        }
        return ans;
    }
}