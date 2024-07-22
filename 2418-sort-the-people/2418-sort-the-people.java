class Solution {
    class NameHeight {
        public String name;
        public int height;

        public NameHeight(String name, int height) {
            this.name = name;
            this.height = height;
        }
    }

    public String[] sortPeople(String[] names, int[] heights) {
        NameHeight[] arr = new NameHeight[names.length];
        String[] rtn = new String[names.length];

        for(int i = 0; i < names.length; ++i) {
            arr[i] = new NameHeight(names[i], heights[i]);
        }
        Arrays.sort(arr, (a, b)-> {
            return b.height - a.height;
        });
        for(int i = 0; i < names.length; ++i)
            rtn[i] = arr[i].name;
        return rtn;
    }
}