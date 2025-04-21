function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    let max: number = 0;

    for(let num of candies)
        max = Math.max(max, num);

    const rtn : boolean[] = new Array(candies.length);

    for(let i = 0; i < candies.length; ++i) {
        if(candies[i] + extraCandies >= max)
            rtn[i] = true;
        else
            rtn[i] = false;
    }

    return rtn;
};