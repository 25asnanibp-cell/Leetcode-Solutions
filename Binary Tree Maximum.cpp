/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    let maxSum = -Infinity;

    const dfs = (node) => {
        if (node === null) return 0;

        // Ignore negative path sums
        const leftSum = Math.max(0, dfs(node.left));
        const rightSum = Math.max(0, dfs(node.right));

        // Maximum path passing through this node
        const currentSum = node.val + leftSum + rightSum;

        maxSum = Math.max(maxSum, currentSum);

        // Return the best one-sided path to the parent
        return node.val + Math.max(leftSum, rightSum);
    };

    dfs(root);

    return maxSum;
};
