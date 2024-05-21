class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> rtn = new ArrayList<>();
        rtn.add(new ArrayList<Integer>());
        makeSubsets(nums,0,rtn);
        return rtn;
    }

    public void makeSubsets(int[] nums, int idx, List<List<Integer>> subsetList) {
        if(idx == nums.length)
            return ;
        for(int i = 0, len = subsetList.size(); i < len; ++i) {
            List<Integer> newList = new ArrayList<Integer>(subsetList.get(i));
            newList.add(nums[idx]);
            subsetList.add(newList);
        }
        makeSubsets(nums, idx + 1, subsetList);
    }
}