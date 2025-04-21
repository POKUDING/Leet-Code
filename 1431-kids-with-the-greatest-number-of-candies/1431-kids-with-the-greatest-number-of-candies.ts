function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max: number = Math.max(...candies);
    const rtn : boolean[] = [];

    for(const candy of candies)
        rtn.push(candy + extraCandies >= max);

    return rtn;
};