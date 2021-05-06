import java.util.*;

class ReorderList {

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode reverse(ListNode node) {
        ListNode curr = node, prev = null, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public void reorderList(ListNode head) 
    {
        if(head == null)
            return;
    // find middle
        ListNode s = head;
        ListNode f = head;
        while(f.next!=null && f.next.next!=null)
        {
            s = s.next;
            f = f.next.next;            
        }

        //  middle is s

        ListNode node1 = head;
        ListNode node2 = s.next;
        s.next = null;

        node2 = reverse(node2);

        // Node dummy = new Node();
        // Node curr = dummy;    // pointer
        ListNode curr = new ListNode();
        // curr.next = null;
        
        while(node1 != null || node2 != null)
        {
            // Node curr = new Node();
            if(node1 != null)
            {
                curr.next = node1;
                // System.out.println(curr.data);
                node1= node1.next;
                curr = curr.next;
            }
        
            if(node2 != null)
            {
                // System.out.println(node2.data);
                curr.next = node2;
                // System.out.println(curr.data);
                node2= node2.next;
                curr = curr.next;
            }
        }
        // dummy = dummy.next;
    }      

}