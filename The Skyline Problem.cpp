/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var getSkyline = function(buildings) {
    const events = [];

    // Create start and end events for each building
    for (const [left, right, height] of buildings) {
        events.push([left, -height, right]);
        events.push([right, 0, 0]);
    }

    // Sort by x-coordinate, then by height
    events.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    // Max heap: [height, right]
    const heap = [[0, Infinity]];

    const result = [];

    // Max-heap operations
    const push = (item) => {
        heap.push(item);
        let i = heap.length - 1;

        while (i > 0) {
            const parent = Math.floor((i - 1) / 2);

            if (heap[parent][0] >= heap[i][0]) break;

            [heap[parent], heap[i]] = [heap[i], heap[parent]];
            i = parent;
        }
    };

    const pop = () => {
        const top = heap[0];
        const last = heap.pop();

        if (heap.length > 0) {
            heap[0] = last;
            let i = 0;

            while (true) {
                let largest = i;
                const left = 2 * i + 1;
                const right = 2 * i + 2;

                if (
                    left < heap.length &&
                    heap[left][0] > heap[largest][0]
                ) {
                    largest = left;
                }

                if (
                    right < heap.length &&
                    heap[right][0] > heap[largest][0]
                ) {
                    largest = right;
                }

                if (largest === i) break;

                [heap[i], heap[largest]] =
                    [heap[largest], heap[i]];

                i = largest;
            }
        }

        return top;
    };

    for (const [x, negHeight, right] of events) {
        // Add a building when its left edge is reached
        if (negHeight < 0) {
            push([-negHeight, right]);
        }

        // Remove expired buildings from the heap
        while (heap[0][1] <= x) {
            pop();
        }

        // Current maximum skyline height
        const height = heap[0][0];

        // Add a key point only when the height changes
        if (
            result.length === 0 ||
            result[result.length - 1][1] !== height
        ) {
            result.push([x, height]);
        }
    }

    return result;
};
