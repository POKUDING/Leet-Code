class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        TreeMap<Integer,Integer> map = new TreeMap<>();

        for(int[] item: items) {
            Integer curr = map.getOrDefault(item[0], 0);
            if(curr < item[1])
                map.put(item[0], item[1]);
        }

        int maxBeauty = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            maxBeauty = Math.max(maxBeauty, entry.getValue()); // 최대 아름다움 계산
            entry.setValue(maxBeauty); // 현재 가격에서의 최대 아름다움 갱신
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            // 쿼리 가격보다 작거나 같은 가격에서 가장 큰 아름다움 찾기
            Integer maxForQuery = map.floorEntry(queries[i]) != null 
                                  ? map.floorEntry(queries[i]).getValue() 
                                  : 0;
            result[i] = maxForQuery; // 쿼리 결과 저장
        }


        return result;
    }
}