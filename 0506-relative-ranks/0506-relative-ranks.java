class Solution {
    public String[] findRelativeRanks(int[] score) {
        int[] sortedScore = new int[score.length];
        Map<Integer,Integer> map = new HashMap<>();

        for(int i = 0; i < score.length; ++i)
            sortedScore[i] = score[i];
        Arrays.sort(sortedScore);
        for(int i = score.length - 1, j = 1; i >= 0 ; --i)
            map.put(sortedScore[i],j++);
        String[] ans = new String[score.length];
        for(int i = 0; i < score.length; ++i) {
            if(map.get(score[i]) == 1)
                ans[i] = new String("Gold Medal");
            else if (map.get(score[i]) == 2)
                ans[i] = new String("Silver Medal");
            else if (map.get(score[i]) == 3)
                ans[i] = new String("Bronze Medal");
            else
                ans[i] = map.get(score[i]).toString();
        }
        return ans;
    }
}