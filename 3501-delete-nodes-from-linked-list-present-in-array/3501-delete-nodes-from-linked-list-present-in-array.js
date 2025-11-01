/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    const valuesToRemove = new Set(nums);
    const dummy = new ListNode(0, head);
    let slow = dummy;

    while (slow.next !== null) {
        if (valuesToRemove.has(slow.next.val)) {
            slow.next = slow.next.next;
        } else {
            slow = slow.next;
        }
    }
    return dummy.next;
};