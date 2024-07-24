class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        Integer[] rtn = new Integer[nums.length];

        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            int idx = 0;
            int mappedNum = 0;
            while(true) {
                int curr = num % 10;
                mappedNum += mapping[curr] * Math.pow(10, idx++);
                num /= 10;
                if(num == 0)
                    break;
            }
            rtn[i] = nums[i];
            map.put(nums[i], mappedNum);
        }
        Arrays.sort(rtn, (a, b)-> {
            return map.get(a) - map.get(b);
        });
        return Arrays.stream(rtn).mapToInt(Integer::intValue).toArray();
    }
}