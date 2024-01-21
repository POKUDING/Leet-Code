function rob(nums: number[]): number {
    const moneys: number[] = [];

    if(nums.length === 1) {
        return nums[0];
    }
    if(nums.length <= 2) {
        return Math.max(nums[0], nums[1]);
    }
    moneys.push(nums[0]);
    moneys.push(nums[1]);
    moneys.push(nums[0] + nums[2]);
    for (let i = 3; i < nums.length; ++i) {
        moneys[i] = nums[i] + Math.max(moneys[i - 2], moneys[i - 3]);
    }
    return Math.max(moneys[moneys.length - 1], moneys[moneys.length - 2]);
};