class Node {

    int data;
    Node prev, next;

    Node(int val) {
        data = val;
        prev = null;
        next = null;
    }
}

public class doublyLinkedList {

    static Node insert(Node head, int val) {

        Node temp = new Node(val);

        if (head == null)
            head = temp;

        else {
            temp.next = head;
            head.prev = temp;
            head = temp;
        }

        return head;
    }

    public static int countPair(Node first, Node sec, int sum) {
        int count = 0;

        while (first!= null && sec != null && first != sec && first != sec.next) {

            if (first.data + sec.data == sum) {
                // System.out.println(first.data);
                // System.out.println(sec.data);
                count++;
                first = first.next;
                sec = sec.prev;
            } else if (first.data + sec.data > sum) {
                sec = sec.prev;
            } else
                first = first.next;
        }

        return count;
    }

    public static int countTriplets(Node head, int sum) {

        Node cur = head, last = head;
        int count = 0;

        while (last.next != null) {
            last = last.next;
        }

        while (cur != null) {

            // System.out.println(cur.data);
            count += countPair(cur.next, last, sum - cur.data);
            cur = cur.next;
        }

        return count;

    }

    public static void main(String args[]) {
        // start with an empty doubly linked list
        Node head = null;

        // insert values in sorted order
        head = insert(head, 9);
        head = insert(head, 8);
        head = insert(head, 6);
        head = insert(head, 5);
        head = insert(head, 4);
        head = insert(head, 2);
        head = insert(head, 1);

        int x = 17;
        System.out.println("count = " + countTriplets(head, x));
    }

}