function findErrorNums(nums: number[]): number[] {
    const ans = [0,0]
    let checkNum = 1;
    nums.sort((a,b)=> a- b);
    console.log(nums);
    for (let i = 0; i < nums.length; ++i) {
        if(nums[i] === checkNum)
            ++checkNum;
        if(nums[i] === nums[i + 1])
            ans[0] = nums[i];
    }
    ans[1] = checkNum;
    return ans;
};