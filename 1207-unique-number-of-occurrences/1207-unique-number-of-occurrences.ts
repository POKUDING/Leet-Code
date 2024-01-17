function uniqueOccurrences(arr: number[]): boolean {
    let occurrences: Map<number, number> = new Map<number, number>();
    for (let i = 0; i < arr.length; i++) {
        if (!occurrences.has(arr[i])) {
            occurrences.set(arr[i], 1);
        } else {
            occurrences.set(arr[i],  occurrences.get(arr[i]) + 1);
        }
    }
    
    let occurrenceValues: number[] = [...occurrences.values()].sort((a:number, b:number) => a - b);
    for (let i = 1; i < occurrenceValues.length; i++) {
        if (occurrenceValues[i] === occurrenceValues[i-1]) {
            return false;
        }
    }

    return true;
};