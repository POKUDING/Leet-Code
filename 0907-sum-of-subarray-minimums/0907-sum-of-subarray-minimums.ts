function sumSubarrayMins(arr: number[]): number {
    const stack: number[] = [];
    let ans: number = 0;
    const modNum: number = 1000000007;
    for (let i = 0; i <= arr.length; ++i) {
        while(stack.length && (i === arr.length || arr[stack[stack.length - 1]] >= arr[i])) {
            const min:number = stack.pop();
            const leftRange:number = stack.length ? (min - stack[stack.length - 1]) : min + 1;
            const rightRange: number = i - min;
            const range = leftRange * rightRange;
            ans += (range * arr[min]) % modNum;
            ans %= modNum;
        }
        stack.push(i);
    }
    return ans;
};