class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;

        if (nums.size() < 3)
          return nums.size();
        for(int i = 0, j = 0, size = nums.size(); i < size; i+= j)
        {
          j = 0;
          while(i + j < size && nums[i] == nums[i + j])
            j++;
          if (j >= 2)
            nums[ret++] = nums[i];
           nums[ret++] = nums[i];
        }
        return ret;
    }
};