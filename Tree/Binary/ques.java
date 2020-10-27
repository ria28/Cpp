import java.util.*;

public class ques {
    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int val, Node left, Node right) {
            this.data = val;
            this.left = left;
            this.right = right;
        }
    }

    // https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/
    // Microsoft
    static int count = 0;
    static Node root; // bcoz we need subtree so it should not include root

    public static int subtreeSum(Node node, int sum) {
        if (node == null)
            return 0;

        int ls = subtreeSum(node.left, sum);
        int rs = subtreeSum(node.right, sum);

        if (node != root)
            if (ls + rs + node.data == sum)
                count++;

        return (ls + rs + node.data);
    }

    // https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
    // Amazon , DE Shaw
    public static void diagonal(Node node, HashMap<Integer, ArrayList<Integer>> hm, int d) {
        if (node == null)
            return;
        ArrayList<Integer>list = hm.get(d);
        if(list == null){
            list = new ArrayList<>();
            list.add(node.data);
        }
        else{
            list.add(node.data);
        }
        hm.put(d,list);
        
        diagonal(node.left, hm, d+1);
        diagonal(node.right, hm, d);
    }

    // https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
    public static class Pair_2 {
        Node node;
        int col;

        Pair_2(Node node, int col) {
            this.node = node;
            this.col = col;
        }
    }
    public static void vertical(Node node){
        Queue<Pair>q = new ArrayDeque<>();

        // q.add(new Pair_2(node , 0));
        
        while(!q.isEmpty()){
            int size = q.size();
            HashMap<Integer,Set<Integer>>hm = new HashMap<>();
        }
    }

    public static void display(Node node) {
        if (node == null)
            return;
        String str = " ";
        str += node.left == null ? "." : node.left.data + " ";
        str += "<--" + node.data + "-->";
        str += node.right == null ? "." : node.right.data + " ";

        System.out.println(str);
        display(node.left);
        display(node.right);
    }

    public static class Pair {
        Node node;
        int state;

        Pair(Node node, int state) {
            this.node = node;
            this.state = state;
        }
    }

    public static void main(String[] args) {
        // Integer arr[] = { 5, -10, 9, null, null, 8, null, null, 3, -4, null, null, 7, null, null };
        Integer arr[] = { 8, 3,1,null,null,null,10,6,4,null,null,7,null,null,14,13,null,null,null};

        Node root = new Node(arr[0], null, null);
        Pair rp = new Pair(root, 1);
        Stack<Pair> st = new Stack<>();
        st.push(rp);

        int idx = 0;
        while (st.size() > 0) {
            Pair top = st.peek();
            if (top.state == 1) {
                idx++;
                if (arr[idx] != null) {
                    Node lnode = new Node(arr[idx], null, null);
                    top.node.left = lnode;
                    Pair np = new Pair(lnode, 1);
                    st.push(np);
                } else {
                    top.node.left = null;
                }
                top.state++;
            } else if (top.state == 2) {
                idx++;
                if (arr[idx] != null) {
                    Node rnode = new Node(arr[idx], null, null);
                    top.node.right = rnode;
                    Pair np = new Pair(rnode, 1);
                    st.push(np);
                } else {
                    top.node.right = null;
                }
                top.state++;
            } else {
                st.pop();
            }
        }

        display(root);
        // subtreeSum(root, 7);
        // System.out.println(count);


        // HashMap<Integer, ArrayList<Integer>>hm = new HashMap<>();
        // diagonal(root, hm, 0);
        // for(Integer i : hm.keySet()){
        //     ArrayList<Integer>list = hm.get(i);
        //     for(int j =0; j<list.size();j++){
        //         System.out.print(list.get(j)+" ");
        //     }
        //     System.out.println();
        // }
    }
}