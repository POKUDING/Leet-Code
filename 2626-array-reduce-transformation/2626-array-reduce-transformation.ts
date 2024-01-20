type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let rtn:number = 0;

    if(!nums.length)
        return init;
    rtn = init
    for(let i = 0; i < nums.length; ++i) {
        rtn = fn(rtn, nums[i]);
    }
    return rtn;
};