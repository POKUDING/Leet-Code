function fac(n:number) {
    if (n === 1)
        return n;
    return n * fac(n - 1);
}

function climbStairs(n: number): number {
    let rtn: number = 1;
    let cnt: number = 0;
    let tmp: number = 1;
    
    while (n - (2 * cnt++) >= 2) {
        tmp = 1;
        for(let i = 0; i < cnt; ++i)
            tmp *= n - cnt - i;
        rtn += (tmp / fac(cnt));
        console.log(tmp, rtn, cnt);
    }
    return rtn;
};