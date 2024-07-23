class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums)
            map.put(num, map.getOrDefault(num,0) + 1);
        // System.out.println(map);
        Integer[] newArr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(newArr, (a, b) -> {
            if(map.get(a) == map.get(b))
                return b - a;
            return map.get(a) - map.get(b);
        });
        return Arrays.stream(newArr).mapToInt(Integer::intValue).toArray();
    }
}