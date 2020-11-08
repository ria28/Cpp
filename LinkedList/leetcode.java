import java.util.*;

class leetcode {
    public  static class ListNode {
        int val;
        ListNode next;
        ListNode(){

        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    static ListNode res = new ListNode(0);
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // ListNode res = new ListNode(0);
        ListNode head = res;
        // System.out.println(head.val);
        int s1 = 0, s2 = 0;
        ListNode head1= l1;
        ListNode head2 = l2;
        while (l1 != null) {
            l1 = l1.next;
            s1++;
        }
        while (l2 != null) {
            l2 = l2.next;
            s2++;
        }
        // System.out.println(s1+" "+s2);
        int oc = addLL(head1, head2, s1, s2);
        if (oc > 0)
            res.next = new ListNode(oc);
        return head.next;
    }

    public static int addLL(ListNode l1, ListNode l2, int pv1, int pv2) {               
        if (l1 == null && l2 == null)
            return 0;
        
        int data = 0;
        if (pv1 > pv2) {
            int oc = addLL(l1.next, l2, pv1 - 1, pv2);
            data = l1.val + oc;
        } else if (pv1 < pv2) {
            int oc = addLL(l1, l2.next, pv1, pv2 - 1);
            data = l2.val + oc;
        } else {
            int oc = addLL(l1.next, l2.next, pv1 - 1, pv2 - 1);
            data = l1.val + l2.val + oc;
        }
       
        int nd = data % 10;
        int nc = data / 10;
        System.out.println(res.val);
        res.next = new ListNode(nd);
        res = res.next;
        return nc;

    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(7);
        l1.next = new ListNode(2);
        l1.next.next = new ListNode(4);
        l1.next.next.next = new ListNode(3);
        ListNode l2 = new ListNode(5);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);
        ListNode node = addTwoNumbers(l1, l2);
        while (node != null) {
            System.out.print(node.val);
            node = node.next;
        }
    }
}
