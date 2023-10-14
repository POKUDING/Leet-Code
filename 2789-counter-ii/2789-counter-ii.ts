type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let cnt = init;
	const increment = () : number => {return ++cnt};
    const decrement = () : number => { return --cnt };
    const reset = () : number => { return cnt = init };
    return { increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */