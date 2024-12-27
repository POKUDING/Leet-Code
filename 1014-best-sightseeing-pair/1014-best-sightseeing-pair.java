class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int max = 0;
        int top = values[0];

        for(int i = 1; i < values.length; ++i) {
            max = Math.max(max, top + values[i] - i);
            top = Math.max(top, values[i] + i);
        }
        return max;
    }
}