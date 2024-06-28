class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long ans = 0;
        Map<Integer,Integer> map = new HashMap<>();

        for(int[] road : roads) {
            map.put(road[0], map.getOrDefault(road[0], 0) + 1);
            map.put(road[1], map.getOrDefault(road[1], 0) + 1);
        }
        List<Integer> keySet = new ArrayList<>(map.keySet());
        keySet.sort((o1, o2)-> map.get(o2).compareTo(map.get(o1)));
        for(Integer key : keySet) {
            ans += (long)map.get(key) * (long)n--;
        }
        return ans;
    }
}