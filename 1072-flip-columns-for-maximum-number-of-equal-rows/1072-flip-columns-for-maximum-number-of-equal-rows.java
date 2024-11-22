class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<List<Integer>, Integer> map = new HashMap<>();
        int ans = 0;

        for (int[] row: matrix) {
            boolean flip = false;
            if(row[0] == 1)
                flip = true;
            for (int i = 0; flip == true && i < row.length; ++i)
                row[i] = row[i] == 1 ? 0 : 1;
            List<Integer> list = Arrays.stream(row).boxed()
                                       .collect(Collectors.toList());;
            int curr = map.getOrDefault(list, 0);
            map.put(list, curr + 1);

            ans = Math.max(ans, curr + 1);
        } 
        return ans;
    }
}