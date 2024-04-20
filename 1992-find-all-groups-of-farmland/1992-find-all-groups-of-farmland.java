class Solution {
    public int[][] findFarmland(int[][] land) {
        ArrayList<int[]> arr = new ArrayList<>();
        int curr = 2;
        arr.add(new int[]{0, 0, 0, 0});
        for(int y = 0; y < land.length; ++y) {
            for(int x = 0; x < land[0].length; ++x) {
                if(land[y][x] == 1) {
                    if(y > 0 && land[y - 1][x] > 1)
                        land[y][x] = land[y - 1][x];
                    else if (x > 0 && land[y][x - 1] > 1)
                        land[y][x] = land[y][x - 1];
                    else {
                        land[y][x] = curr++;
                        arr.add(new int[]{y, x, y, x});
                    }
                    arr.get(land[y][x] - 1)[2] = y;
                    arr.get(land[y][x] - 1)[3] = x;
                }
            }
        }
        int[][] rtn = new int[arr.size() - 1][4];
        for(int i = 1; i < arr.size(); ++i)
            rtn[i - 1] = arr.get(i);
        return rtn;
    }
}