function rob(nums: number[]): number {
    const moneys: number[] = [nums[0]];

    if(nums.length > 1)
        moneys.push(Math.max(nums[0],nums[1]));
    for (let i = 2; i < nums.length; ++i)
        moneys.push(Math.max(nums[i] + moneys[i - 2], moneys[i - 1]));
    return moneys[moneys.length - 1];
};