class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> res = new ArrayList<>(candies.length);
        int max = 0;
        for(int candy : candies) {
            max = Math.max(max, candy);
        }

        for(int candy: candies) {
            if (candy + extraCandies >= max)
                res.add(true);
            else
                res.add(false);
        }
        return res;
    }
}