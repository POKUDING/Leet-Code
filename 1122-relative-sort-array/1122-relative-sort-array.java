class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        // Convert int[] to Integer[] for sorting
        Integer[] arr1Integer = Arrays.stream(arr1).boxed().toArray(Integer[]::new);
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; ++i) {
            map.put(arr2[i], i);
        }
        
        Arrays.sort(arr1Integer, (num1, num2) -> {
            Integer num1Idx = map.get(num1);
            Integer num2Idx = map.get(num2);
            num1Idx = (num1Idx == null) ? 10001 : num1Idx;
            num2Idx = (num2Idx == null) ? 10001 : num2Idx;
            if (num1Idx.equals(num2Idx)) {
                return Integer.compare(num1, num2);
            }
            return Integer.compare(num1Idx, num2Idx);
        });
        
        // Convert Integer[] back to int[]
        return Arrays.stream(arr1Integer).mapToInt(Integer::intValue).toArray();
    }
}