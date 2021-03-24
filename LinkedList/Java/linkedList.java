
// import java.util.LinkedList;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Comparator;

public class linkedList {

    public static class Node {
        int data;
        Node next;

        Node() {
        }

        Node(int d) {
            this.data = d;
            this.next = null;
        }
    }

    Node head;
    Node tail;
    int size;

    public void addLast(int val) {
        if (size == 0) {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;
            head = tail = temp;
            size++;
        } else {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;
            tail.next = temp;
            tail = temp;
            size++;
        }
    }

    public void addFirst(int val) {
        Node temp = new Node();
        temp.data = val;
        if (size == 0) {
            head = temp;
            temp.next = null;
        } else {
            temp.next = head;
            head = temp;
        }
        size++;
    }

    public int getFirst() {
        if (size == 0)
            return -1;
        else
            return head.data;
    }

    public void removeFirst() {
        head = head.next;
        size--;
    }

    public int size() {
        return size;
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
    public static void deleteNode_withoutHead(Node node) {
        // System.out.println(node.data);
        if (node.next == null) {
            node = null;
            return;
        }
        Node temp = node.next;
        node.data = temp.data;
        node.next = temp.next;
    }

    // https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
    public int Nth_node_end(int k) {
        // without using size we'll use TWO POINTERS

        Node s = head;
        Node f = head; // slow and fast
        for (int i = 0; i < k - 1; i++)
            f = f.next;

        while (f.next != null) {
            s = s.next;
            f = f.next;
        }

        return s.data;
    }

    // https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
    // FLOYD's algo===============
    public void remove_loop(Node loop_start) {
        Node f = loop_start;
        while (true) {
            f = f.next;
            if (f.next == loop_start)
                break;
        }
        f.next.next = null;
    }

    public void detectLoop_remove() {
        Node s = head;
        Node f = head;

        while (s != null && f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
            if (s == f) {
                System.out.println(s.data);
                remove_loop(s);
                break;
            }
        }

    }

    // https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
    public static int intersection(linkedList ll_1, linkedList ll_2, int size_differ) {
        Node head_1 = ll_1.head;
        Node head_2 = ll_2.head;

        // System.out.print(head_1.data +" "+ head_2.data);

        for (int i = 0; i < size_differ; i++)
            head_1 = head_1.next;
        System.out.print(head_1.data);

        while (head_1.next != null && head_2.next != null) {
            // System.out.print(head_1.data +" "+ head_2.data);
            if (head_1.data == head_2.data)
                return head_1.data;

            head_1 = head_1.next;
            head_2 = head_2.next;
        }
        return -1;

    }

    // Remove Duplicate elements==============================================
    // https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
    public Node mid_node(Node head, Node tail) {
        Node s = head;
        Node f = head;
        while (f != tail && f.next != tail) {
            f = f.next.next;
            s = s.next;
        }
        return s;
    }

    public linkedList merge2sorted_arr(linkedList ll_1, linkedList ll_2) {
        linkedList res = new linkedList();
        Node one = ll_1.head;
        Node two = ll_2.head;

        while (one != null && two != null) {
            if (one.data < two.data) {
                res.addLast(one.data);
                one = one.next;
            } else {
                res.addLast(two.data);
                two = two.next;
            }
        }

        while (one != null) {
            res.addLast(one.data);
            one = one.next;
        }

        while (two != null) {
            res.addLast(two.data);
            two = two.next;
        }

        return res;
    }

    public linkedList merge_sort(Node head, Node tail) {
        if (head == tail) {
            linkedList base = new linkedList();
            base.addLast(head.data);
            return base;
        }

        Node mid = mid_node(head, tail);
        linkedList fsh = merge_sort(head, mid);
        linkedList ssh = merge_sort(mid.next, tail);

        linkedList res = merge2sorted_arr(fsh, ssh);
        return res;
    }

    public void remove_duplicates(linkedList ll) {
        linkedList res = new linkedList();
        while (ll.size() > 0) {
            int val = ll.getFirst();
            ll.removeFirst();

            if (res.size() == 0 || res.tail.data != val)
                res.addLast(val);
        }

        ll.head = res.head;
        ll.tail = res.tail;
        ll.size = res.size;

        ll.display();
    }

    // remove duplicates using hashmap

    public void remove_duplicates_2(linkedList ll) {
        HashSet<Integer> hs = new HashSet<>();
        Node curr_node = ll.head;
        Node prev = null;

        while (curr_node != null) {
            int val = curr_node.data;
            if (hs.contains(val))
                prev.next = curr_node.next;
            else {
                hs.add(val);
                prev = curr_node;
            }
            curr_node = curr_node.next;
        }

        ll.display();
    }

    public void repeated_ele_1(linkedList ll) {
        linkedList ll_sorted = merge_sort(ll.head, ll.tail);
        remove_duplicates(ll_sorted);

        remove_duplicates_2(ll);
    }

    // Delete nodes which have a greater value on right
    // side============================
    public void delete_lesser_nodes() {
        Node curr_node = this.head;
        while (curr_node != null) {
            if (curr_node.data < curr_node.next.data)
                deleteNode_withoutHead(curr_node);

            curr_node = curr_node.next;
        }
    }

    // SEGREGATE ODD EVEN
    // https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

    public boolean check_even(int data) {
        return (data % 2 == 0) ? true : false;
    }

    public void segregate_01() {
        Node start = this.head;
        Node end = this.tail;

        linkedList odd = new linkedList();
        linkedList even = new linkedList();

        while (start != null) {
            if (check_even(start.data))
                even.addLast(start.data);
            else
                odd.addLast(start.data);
            start = start.next;
        }

        this.head = even.head;
        even.tail.next = odd.head;
    }

    // https://www.geeksforgeeks.org/sum-of-two-linked-lists/
    // ADDITION OF LINKED LISTS
    // pv = place value
    public static int add_ll(Node one, int pv1, Node two, int pv2, linkedList res) {
        if (one == null && two == null)
            return 0;

        int sum = 0;

        if (pv1 > pv2) {
            int oc = add_ll(one.next, pv1 - 1, two, pv2, res);
            sum = one.data + oc; // old carry

        } else if (pv2 > pv1) {
            int oc = add_ll(one, pv1, two.next, pv2 - 1, res);
            sum = two.data + oc;
        } else {
            int oc = add_ll(one.next, pv1 - 1, two.next, pv2 - 1, res);
            sum = one.data + two.data + oc;
        }

        int new_sum = sum % 10;
        int new_carry = sum / 10;
        res.addFirst(new_sum);
        return new_carry;
    }

    // https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/
    public static void three_ll_sum(Node one, Node two, Node three, int target, int sum) {
        sum = one.data + two.data + three.data;
        if (sum == target) {
            System.out.println("[" + one.data + ", " + two.data + " " + three.data + "]");
            return;
        }

        if (sum > target)
            return;
        else {
            if (three.next != null)
                three_ll_sum(one, two, three.next, target, sum);
            if (two.next != null)
                three_ll_sum(one, two.next, three, target, sum);
            if (one.next != null)
                three_ll_sum(one.next, two, three, target, sum);

        }
    }

    // segregate 0, 1,2
    public void segregate_012(linkedList ll) {
        Node curr_node = ll.head;
        Node cn = ll.head;
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        while (curr_node != null) {
            if (curr_node.data == 0)
                cnt_0++;
            else if (curr_node.data == 1)
                cnt_1++;
            else
                cnt_2++;
            curr_node = curr_node.next;
        }
        // System.out.println(cnt_2);
        while (cnt_0 != 0) {
            cn.data = 0;
            cn = cn.next;
            cnt_0--;
        }
        while (cnt_1 != 0) {
            cn.data = 1;
            cn = cn.next;
            cnt_1--;
        }
        while (cnt_2 != 0) {
            cn.data = 2;
            cn = cn.next;
            cnt_2--;
        }
        ll.display();
    }

    // QUICK SORT====================================================
    public Node partiton(Node head, Node tail) {
        return tail;
    }

    public void quickSort(Node head, Node tail) {
        // System.out.println(head.data);
        // System.out.println(tail.data);

        Node pivot = partiton(head, tail);
        Node curr = head;

        if (tail == null || pivot == null || head == tail)
            return;

        while (curr != null) {

            if (curr == pivot)
                break;
            if (curr.data > pivot.data && curr.next != null) {
                Node nbr = curr.next;
                Node temp = new Node();
                int val = curr.data;
                deleteNode_withoutHead(curr);
                temp.data = val;
                temp.next = tail.next; // null
                tail.next = temp;
                tail = temp;
                // System.out.println(curr.data);
                curr = nbr;
            } else
                curr = curr.next;
        }

        // System.out.println(head.data);

        Node head_ = head;
        while (head_.next.data < pivot.data) {
            head_ = head_.next;
        }
        System.out.println(head.data + ", " + head_.data);
        quickSort(head, head_);
        System.out.println(pivot.next.data + "," + tail.data);
        quickSort(pivot.next, tail);

    }

    // https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/
    // REARRANGE

    public Node reverse(Node node) {
        Node curr = node, prev = null, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public void rearrange(Node head) {
        // find middle
        Node s = head;
        Node f = head;
        while (f.next != null && f.next.next != null) {
            s = s.next;
            f = f.next.next;
        }

        // middle is s

        Node node1 = head;
        Node node2 = s.next;
        s.next = null;

        node2 = reverse(node2);

        // Node dummy = new Node();
        // Node curr = dummy; // pointer
        Node curr = new Node();
        // curr.next = null;

        while (node1 != null || node2 != null) {
            // Node curr = new Node();
            if (node1 != null) {
                curr.next = node1;
                // System.out.println(curr.data);
                node1 = node1.next;
                curr = curr.next;
            }

            if (node2 != null) {
                // System.out.println(node2.data);
                curr.next = node2;
                // System.out.println(curr.data);
                node2 = node2.next;
                curr = curr.next;
            }
        }
        // dummy = dummy.next;

    }

    public void zig_zag(Node head) {
        boolean flag = false;
        Node cur = head;

        while (cur.next != null) {
            if (flag == false) {
                if (cur.data > cur.next.data) {
                    int temp = cur.data;
                    cur.data = cur.next.data;
                    cur.next.data = temp;
                }
            }

            if (flag == true) {
                if (cur.data < cur.next.data) {
                    int temp = cur.data;
                    cur.data = cur.next.data;
                    cur.next.data = temp;
                }
            }

            cur = cur.next;
            flag = !(flag);
        }
    }

    // https://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/
    // list 1-> -2 -> -3 -> 4 -> -5
    // o/p -5 -> -3 -> -2 -> 1 -> 4

    public void helper_sort(Node node) {
        int a = node.data;

        Node temp = node.next;
        node.data = temp.data;
        node.next = temp.next;

        Node temp2 = new Node();
        temp2.data = a;
        temp2.next = head.next;
        head = temp2;

    }

    public void sort_alreadySorted(Node cur) {
        // Node cur = head;
        while (cur != null) {
            if (cur.data < 0) {
                System.out.println(cur.data);
                Node val = cur;
                Node node = cur.next;
                addFirst(val.data);
                deleteNode_withoutHead(cur);
                cur = node;
            } else
                cur = cur.next;
        }

        // System.out.println(head.data);
    }

    public static Node mergeKSortLists(Node[] arr, int k) {

        Node head = null, last = null;

        // create min heap
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.data - b.data;
            }
        });
        for (int i = 0; i < k; i++)
            if (arr[i] != null)
                pq.add(arr[i]);

        while (!pq.isEmpty()) {
            Node top = pq.peek();
            pq.remove();

            if (top.next != null)
                pq.add(top.next);

            if (head == null) {
                head = top;
                last = top;
            } else {
                last.next = top;
                last = top;
            }
        }
        return head;
    }

    // https://www.geeksforgeeks.org/subtract-two-numbers-represented-as-linked-lists/

    public int getLength(Node node) {
        int size = 0;
        while (node != null) {
            size++;
            node = node.next;
        }
        return size;
    }

    public Node appendZeros(Node node, int diff) {
        while (diff > 0) {
            Node zero = new Node(0);
            zero.next = node;
            node = zero;
            diff--;
        }
        return node;
    }

    boolean borrow = false;

    public Node subtractHelper(Node l1, Node l2) {
        if (l1 == null && l2 == null && borrow == false)
            return null;

        int sub = 0;

        Node nxt = subtractHelper((l1 != null) ? l1.next : null, (l2 != null) ? l2.next : null);

        int d1 = l1.data;
        int d2 = l2.data;

        if (borrow) {
            d1--;
            borrow = false;
        }

        if (d1 < d2) {
            borrow = true;
            d1 = d1 + 10;
        }

        sub = d1 - d2;
        Node cur = new Node(sub);
        cur.next = nxt;

        return cur;

    }

    public Node subtract_LL(Node l1, Node l2) {
        if (l1 == null && l2 == null)
            return null;
        int len1 = getLength(l1);
        int len2 = getLength(l2);

        Node sNode = null, lNode = null;
        Node temp1 = l1, temp2 = l2;

        if (len1 != len2) {
            sNode = (len1 < len2) ? l1 : l2;
            lNode = (len1 < len2) ? l2 : l1;

            sNode = appendZeros(sNode, Math.abs(len1 - len2));

        } else {
            while (l1 != null && l2 != null) {
                if (l1.data > l2.data) {
                    sNode = temp2;
                    lNode = temp1;
                    break;
                }
                l1 = l1.next;
                l2 = l2.next;
            }
        }
        return subtractHelper(lNode, sNode);
    }

    public static void multiply_ll(Node node1, Node node2) {
        int no1 = 0, no2 = 0;

        while (node1 != null || node2 != null) {
            if (node1 != null) {
                no1 = no1 * 10 + node1.data;
                node1 = node1.next;
            }
            if (node2 != null) {
                no2 = no2 * 10 + node2.data;
                node2 = node2.next;
            }

        }

        System.out.println(no1 * no2);
    }

    public static void merge2sorted_2(Node head1 , Node head2)
    {
        Node node1 = head1;
        Node node2 = head2;

        if(node1 != null)
        {
            node1.next = node2;
            // return node1;
        }

        if(node2.data > node1.data && node2.data<node1.next.data)
        {
            Node temp = node1.next;
            node1.next = node2;
            node2 = node2.next;

        }
    }

    public static void main(String[] args) {
        // LinkedList<Integer> ll = new LinkedList<>();
        linkedList ll = new linkedList();
        ll.addLast(1);
        ll.addLast(4);
        ll.addLast(1);
        ll.addLast(12);
        ll.addLast(10);

        // System.out.println("before deletion : ");
        // ll.display();
        // System.out.println("after deletion : ");
        // deleteNode_withoutHead(ll.head.next.next);
        // ll.display();
        // System.out.println(ll.Nth_node_end(3));

        // loop===================================================
        linkedList ll2 = new linkedList();
        ll2.addLast(1);
        ll2.addLast(2);
        ll2.addLast(3);
        ll2.addLast(4);
        ll2.addLast(5);

        // head.next.next.next.next.next =head.next;
        // 1 -> 2 ->3
        // | |
        // 5<- 4
        // ll2.detectLoop_remove();
        // ll2.display();

        // Intersection point======================================
        linkedList ll_1 = new linkedList();
        ll_1.addLast(3);
        ll_1.addLast(6);
        ll_1.addLast(9);
        ll_1.addLast(15);
        ll_1.addLast(30);

        linkedList ll_2 = new linkedList();
        ll_2.addLast(10);
        ll_2.addLast(15);
        ll_2.addLast(30);

        int size_differ = (ll_1.size() - ll_2.size());
        // System.out.println(intersection(ll_1, ll_2, size_differ));

        // remove repeated elements ===============================================
        linkedList ll_rep = new linkedList();
        ll_rep.addLast(12);
        ll_rep.addLast(11);
        ll_rep.addLast(12);
        ll_rep.addLast(21);
        ll_rep.addLast(41);
        ll_rep.addLast(43);
        ll_rep.addLast(21);

        // ll_rep.repeated_ele_1(ll_rep);

        // steps (ologn)
        // 1. Sort -> merge_sort() -> middle , merge2sorted_arr()
        // 2. Remove duplicates from sorted array on ologn

        linkedList ll_3 = new linkedList();
        ll_3.addLast(12);
        ll_3.addLast(15);
        ll_3.addLast(10);
        ll_3.addLast(11);
        ll_3.addLast(5);
        ll_3.addLast(6);
        ll_3.addLast(2);
        ll_3.addLast(3);

        // ll_3.delete_lesser_nodes();
        // ll_3.display();

        // ll.segregate_01();
        // ll.display();

        linkedList res = new linkedList();
        // int oc = add_ll(ll.head,ll.size,ll2.head,ll2.size,res);
        // res.display();

        // triplet sum============================================================
        linkedList triplet_1 = new linkedList();
        linkedList triplet_2 = new linkedList();
        linkedList triplet_3 = new linkedList();
        triplet_1.addLast(12);
        triplet_1.addLast(6);
        triplet_1.addLast(29);

        triplet_2.addLast(23);
        triplet_2.addLast(5);
        triplet_2.addLast(8);

        triplet_3.addLast(90);
        triplet_3.addLast(20);
        triplet_3.addLast(59);

        int target = 101;

        // three_ll_sum(triplet_1.merge_sort(triplet_1.head,triplet_1.tail).head,
        // triplet_2.merge_sort(triplet_2.head,triplet_2.tail).head,
        // triplet_3.merge_sort(triplet_3.head,triplet_3.tail).head,target,0);

        linkedList ll4 = new linkedList();
        // 2 1 2 1 1 2 0 1 0
        ll4.addLast(2);
        ll4.addLast(1);
        ll4.addLast(2);
        ll4.addLast(1);
        ll4.addLast(1);
        ll4.addLast(2);
        ll4.addLast(0);
        ll4.addLast(1);
        ll4.addLast(0);
        // ll4.segregate_012(ll4);

        linkedList ll5 = new linkedList();
        ll5.addLast(40);
        ll5.addLast(20);
        ll5.addLast(60);
        ll5.addLast(10);
        ll5.addLast(50);
        ll5.addLast(30);
        // ll5.quickSort(ll5.head, ll5.tail);
        // ll5.display();

        // ll2 = 1,2,3,4,5
        // ll2.rearrange(ll2.head);
        // ll2.display();

        // ll2.zig_zag(ll2.head);
        // ll2.display();

        linkedList ll6 = new linkedList();
        ll6.addLast(1);
        ll6.addLast(-2);
        ll6.addLast(-3);
        ll6.addLast(4);
        ll6.addLast(-5);

        // ll6.sort_alreadySorted(ll6.head);
        // ll6.display();

        int k = 3;
        Node arr[] = new Node[k];

        linkedList l_1 = new linkedList();
        linkedList l_2 = new linkedList();
        linkedList l_3 = new linkedList();

        l_1.addLast(1);
        l_1.addLast(3);
        l_1.addLast(5);
        l_1.addLast(7);

        l_2.addLast(2);
        l_2.addLast(4);
        l_2.addLast(6);
        l_2.addLast(8);

        l_3.addLast(0);
        l_3.addLast(9);
        l_3.addLast(10);
        l_3.addLast(11);

        arr[0] = l_1.head;
        arr[1] = l_2.head;
        arr[2] = l_3.head;
        // Node head_k = mergeKSortLists(arr, k);
        // while(head_k!=null)
        // {
        // System.out.print(head_k.data);
        // head_k = head_k.next;
        // }

        Node head = new Node(1);
        head.next = new Node(0);
        head.next.next = new Node(0);

        Node head2 = new Node(1);

        linkedList ob = new linkedList();
        // Node result = ob.subtract_LL(head, head2);
        // while(result!=null)
        // {
        // System.out.print(result.data);
        // result = result.next;
        // }

        // multiply_ll(l_1.head, l_2.head);


        merge2sorted_2(l_1.head, l_2.head);
    }
}
