import java.util.*;

public class multiSolver {

    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    }

    public static void display(Node node) {
        String str = node.data + "->";
        for (Node child : node.children) {
            str += child.data + "->";
        }
        str += ".";
        System.out.println(str);

        for (Node child : node.children) {
            display(child);
        }
    }

    public static Node construct(int[] arr) {
        Stack<Node> st = new Stack<>();
        Node root = null;
        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == -1) {
                st.pop();
            } else {
                Node t = new Node(arr[i]);
                if (st.size() == 0) {
                    root = t;
                } else {
                    st.peek().children.add(t);
                }
                st.push(t);
            }
        }
        return root;
    }

    // in heap always available
    static int size;
    static int max;
    static int min;
    static int height;

    public static void multisolver(Node node, int depth) {
        size++;
        min = Math.min(min, node.data);
        max = Math.max(max, node.data);
        height = Math.max(height, depth);

        for (Node child : node.children) {
            multisolver(child, depth + 1);
        }
    }

    static Node predecessor;
    static Node successor;
    static int state;

    public static void predecSuccess(Node node, int val) {
        if (state == 0) {
            if (node.data == val)
                state = 1;
            else
                predecessor = node;
        } else if (state == 1) {
            successor = node;
            state = 2;
        }
        for (Node child : node.children) {
            predecSuccess(child, val);
        }
    }

    static int ceil;
    static int floor;

    public static void ceilAndFlor(Node node, int val) {
        if (node.data > val) {
            if (node.data < ceil)
                ceil = node.data;
        }
        if (node.data < val) {
            if (node.data > floor)
                floor = node.data;
        }
        for (Node child : node.children) {
            ceilAndFlor(child, val);
        }
    }

    // MAX HEAP
    static PriorityQueue<Integer> pq;

    public static void kthLargest(Node node, int k) {
        pq.add(node.data);
        for (Node child : node.children) {
            kthLargest(child, k);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1,
                -1 };

        // int[] arr = { 10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1 };

        Node root = construct(arr);
        size = 0;
        max = Integer.MIN_VALUE;
        min = Integer.MAX_VALUE;
        height = 0;
        multisolver(root, 0);
        System.out.println("Size :" + size);
        System.out.println("MAX :" + max);
        System.out.println("MIN :" + min);
        System.out.println("Height :" + height);

        predecessor = null;
        successor = null;
        state = 0;
        predecSuccess(root, 90);
        // System.out.println("Predecessor: " + predecessor.data + " Successor: " +
        // successor.data);
        ceil = Integer.MAX_VALUE;
        floor = Integer.MIN_VALUE;
        ceilAndFlor(root, 90);
        // System.out.println("Floor: "+ floor+" Ceil: "+ceil);

        pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        kthLargest(root, 3);
        for (int i = 0; i < 2; i++)
            pq.remove();
        System.out.println(pq.peek());

    }

}