/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    const n = points.length;

    if (n <= 2) return n;

    let result = 1;

    // Calculate the greatest common divisor
    const gcd = (a, b) => {
        a = Math.abs(a);
        b = Math.abs(b);

        while (b !== 0) {
            const temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    };

    for (let i = 0; i < n; i++) {
        const slopes = new Map();
        let best = 0;

        const [x1, y1] = points[i];

        for (let j = i + 1; j < n; j++) {
            const [x2, y2] = points[j];

            let dx = x2 - x1;
            let dy = y2 - y1;

            // Reduce the slope to its simplest form
            const g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Normalize the sign
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            // Same slope => same straight line
            const slope = `${dx},${dy}`;

            const count = (slopes.get(slope) || 0) + 1;
            slopes.set(slope, count);

            best = Math.max(best, count);
        }

        result = Math.max(result, best + 1);
    }

    return result;
};
