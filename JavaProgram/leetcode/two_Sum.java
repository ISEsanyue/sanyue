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
        long add1 = 0, add2 = 0;
        int i = 0;
        while (l1 != null) {
            add1 = add1 + l1.val * (long)Math.pow(10, i);
            l1 = l1.next;
            i++;
        }
        i = 0;
        while (l2 != null) {
            add2 = add2 + l2.val * (long)Math.pow(10, i);
            l2 = l2.next;
            i++;
        }
        long sum = add1 + add2;
        long v = sum % 10;
        sum = sum / 10;
        ListNode result = new ListNode((int)v);
        ListNode pre = result;
        while (sum != 0) {
            long val1 = sum % 10;
           /* if(result != null) {
                result.val = val1;
            }*/
            ListNode node = new ListNode((int)val1);
            result.next = node; 
            result = result.next;
            sum = sum / 10;
        }
        return pre;
    }
}