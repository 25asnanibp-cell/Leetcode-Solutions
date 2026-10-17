/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    const values = [];

    for (const head of lists) {
        let node = head;
        while (node !== null) {
            values.push(node.val);
            node = node.next;
        }
    }

    if (values.length === 0) return null;

    values.sort((a, b) => a - b);

    const dummy = new ListNode(0);
    let curr = dummy;

    for (const v of values) {
        curr.next = new ListNode(v);
        curr = curr.next;
    }

    return dummy.next;
};
