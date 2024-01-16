class RandomizedSet {
    private setted : Map<number,number> = new Map<number,number>();
    private arr: number[] = [];

    constructor() {
    }

    insert(val: number): boolean {
        if(this.setted.has(val))
            return false;
        this.setted.set(val,this.arr.length);
        this.arr.push(val);
        return true;
    }

    remove(val: number): boolean {
        const idx = this.setted.get(val);
        if (idx === undefined)
            return false;
        this.arr[idx] = this.arr[this.arr.length - 1];
        this.arr.pop();
        this.setted.set(this.arr[idx], idx);
        return this.setted.delete(val);
    }

    getRandom(): number {
        const randidx = Math.floor(Math.random() * 10) % this.arr.length;
        return this.arr[randidx]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */