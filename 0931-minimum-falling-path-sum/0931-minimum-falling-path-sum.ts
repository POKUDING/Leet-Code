function minFallingPathSum(matrix: number[][]): number {
    const N: number = matrix.length;
    const M: number = matrix[0].length;

    let preRow: number[] = matrix[0];
    for(let r = 1; r < N; ++r) {
        const curRow: number[] = [];
        for (let c = 0; c < M; ++c) {
            const curNum = matrix[r][c];
            const preNum1 = preRow[c - 1] || Infinity;
            const preNum2 = preRow[c];
            const preNum3 = preRow[c + 1] || Infinity;
            curRow[c] = matrix[r][c] + Math.min(preNum1, preNum2, preNum3);
        }
        preRow = curRow;
    }
    return Math.min(...preRow);
};