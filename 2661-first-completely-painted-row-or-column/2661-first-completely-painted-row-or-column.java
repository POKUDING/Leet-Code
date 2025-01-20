class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int h = mat.length;
        int w = mat[0].length;
        Map<Integer,int[]> positionMap = new HashMap<>();
        int[] hCnt = new int[h];
        int[] wCnt = new int[w];



        for(int y = 0; y < h; ++y) {
            for(int x = 0; x < w; ++x) {
                positionMap.put(mat[y][x], new int[]{y, x});
            }
        }

        for(int i = 0; i < arr.length; ++i) {
            int num = arr[i];
            int[] position = positionMap.get(num);
            if(++hCnt[position[0]] == w)
                return i;
            if(++wCnt[position[1]] == h)
                return i;
        }
        return 0;
    }
}