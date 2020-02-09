/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int v = l1.val + l2.val;
        ListNode l3 = new ListNode(v % 10);
        ListNode copy = l3;
        int pre = v >= 10 ? 1 : 0;
        int val1;
        l1 = l1.next; l2 = l2.next;
        while (l1 != null || l2 != null) {
            if (l1 != null && l2 != null) {
                val1 = l1.val + l2.val + pre;
            } else if (l1 != null) {
                val1 = l1.val + pre;
                l1 = l1.next;
            } else {
                val1 = l2.val + pre;
                l2 = l2.next;
            }
            ListNode node = new ListNode(val1 % 10);
            l3.next = node;
            l3 = l3.next;
            pre = val1 >= 10 ? 1 : 0;
        }
        if (pre != 0) {
            ListNode node = new ListNode(pre);
            l3.next = node;
        }
        //l3.next = l1 != null ? l1 : l2;
        return copy;
    }
}