/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1);
    }

    const m = nums1.length;
    const n = nums2.length;
    let low = 0, high = m;
    const totalLeft = Math.floor((m + n + 1) / 2);

    while (low <= high) {
        const cut1 = Math.floor((low + high) / 2);
        const cut2 = totalLeft - cut1;

        const l1 = (cut1 === 0) ? -Infinity : nums1[cut1 - 1];
        const r1 = (cut1 === m) ? Infinity : nums1[cut1];

        const l2 = (cut2 === 0) ? -Infinity : nums2[cut2 - 1];
        const r2 = (cut2 === n) ? Infinity : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((m + n) % 2 === 0) {
                return (Math.max(l1, l2) + Math.min(r1, r2)) / 2;
            } else {
                return Math.max(l1, l2);
            }
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0; // should not reach here for valid input
};
