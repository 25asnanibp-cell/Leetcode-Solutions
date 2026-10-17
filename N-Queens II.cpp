
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let count = 0;

    const cols = new Set();
    const diagonals1 = new Set(); // row - col
    const diagonals2 = new Set(); // row + col

    const backtrack = (row) => {
        // All n queens have been placed
        if (row === n) {
            count++;
            return;
        }

        for (let col = 0; col < n; col++) {
            const d1 = row - col;
            const d2 = row + col;

            // Check if this position is attacked
            if (
                cols.has(col) ||
                diagonals1.has(d1) ||
                diagonals2.has(d2)
            ) {
                continue;
            }

            // Place the queen
            cols.add(col);
            diagonals1.add(d1);
            diagonals2.add(d2);

            // Place a queen in the next row
            backtrack(row + 1);

            // Backtrack: remove the queen
            cols.delete(col);
            diagonals1.delete(d1);
            diagonals2.delete(d2);
        }
    };

    backtrack(0);

    return count;
};
