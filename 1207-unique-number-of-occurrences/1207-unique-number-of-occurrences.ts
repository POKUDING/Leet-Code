function uniqueOccurrences(arr: number[]): boolean {
    const map = new Map();
    const times = new Map();
    for(const num of arr) {
        if (!map[num])
            map[num] = 0;
        map[num]++;
    }
    for (const key in map) {
        if(times[map[key]])
            return false;
        times[map[key]] = key;
    }
    return true
};