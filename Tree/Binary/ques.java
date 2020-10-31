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
        ArrayList<Integer> list = hm.get(d);
        if (list == null) {
            list = new ArrayList<>();
            list.add(node.data);
        } else {
            list.add(node.data);
        }
        hm.put(d, list);

        diagonal(node.left, hm, d + 1);
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

    public static List<List<Integer>> vertical(Node node) {
        Queue<Pair_2> q = new ArrayDeque<>();
        q.add(new Pair_2(node, 0));
        TreeMap<Integer, List<Integer>> hm_2 = new TreeMap<>();

        while (!q.isEmpty()) {
            int size = q.size();
            HashMap<Integer, Set<Integer>> hm = new HashMap<>();
            while (size-- > 0) {
                Pair_2 cur = q.peek();
                q.remove();
                if (hm.get(cur.col) != null)
                    hm.get(cur.col).add(cur.node.data);
                else {
                    Set<Integer> s = new HashSet<>();
                    s.add(cur.node.data);
                    hm.put(cur.col, s);
                }

                if (cur.node.left != null)
                    q.add(new Pair_2(cur.node.left, cur.col - 1));
                if (cur.node.right != null)
                    q.add(new Pair_2(cur.node.right, cur.col + 1));
            }

            for (Integer i : hm.keySet()) {
                for (Integer j : hm.get(i)) {
                    if (hm_2.get(i) != null)
                        hm_2.get(i).add(j);
                    else {
                        List<Integer> list = new ArrayList<>();
                        list.add(j);
                        hm_2.put(i, list);
                    }
                }
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (Integer i : hm_2.keySet()) {
            ans.add(hm_2.get(i));
        }
        return ans;
    }

    // https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
    static ArrayList<Integer> nodes = new ArrayList<>();

    public static void boundary_left(Node node) {
        if (node == null)
            return;

        if (node.left != null) {
            nodes.add(node.data);
            boundary_left(node.left);
        } else if (node.right != null) {
            nodes.add(node.data);
            boundary_left(node.right);
        }
    }

    public static void boundary_leaves(Node node) {
        if (node.left == null && node.right == null) {
            nodes.add(node.data);
        }
        if (node.left != null)
            boundary_leaves(node.left);

        if (node.right != null)
            boundary_leaves(node.right);
    }

    public static void boundary_right(Node node) {
        if (node == null)
            return;
        if (node.left == null && node.right == null)
            return;

        if (node.right != null) {
            boundary_right(node.right);
        } else if (node.left != null) {
            boundary_right(node.left);
        }
        nodes.add(node.data);
    }

    public static void boundaryTraversal(Node node) {
        if (node == null)
            return;
        nodes.add(node.data);

        if (node.left != null)
            boundary_left(node.left);

        boundary_leaves(node);

        if (node.right != null)
            boundary_right(node.right);

    }

    // https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
    public static void perfectBinaryTree(Node node) {
        if (node == null)
            return;
        System.out.print(node.data + " ");
        if (node.left != null) { // since perfect tree so no need to check for right node
            System.out.print(node.left.data + " " + node.right.data + " ");
        }
        if (node.left.left == null)
            return;
        Queue<Node> q = new ArrayDeque<>();
        q.add(node.left);
        q.add(node.right);

        while (!q.isEmpty()) {
            Node first = q.peek();
            q.remove();
            Node second = q.peek();
            q.remove();

            System.out.print(first.left.data + " " + second.right.data + " ");
            System.out.print(first.right.data + " " + second.left.data + " ");

            if (first.left.left != null) {
                q.add(first.left);
                q.add(second.right);
                q.add(first.right);
                q.add(second.left);
            }
        }
    }

    // https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
    static Node root_;

    public static void createNode(int i, int[] par, Node[] created) {
        if (created[i] != null)
            return;
        created[i] = new Node(i, null, null);

        if (par[i] == -1) {
            root_ = created[i];
            return;
        }
        if (created[par[i]] == null)
            createNode(par[i], par, created);

        if (created[par[i]].left == null)
            created[par[i]].left = created[i];
        else
            created[par[i]].right = created[i];

    }

    public static Node constructTree(int[] parent) {
        Node[] created = new Node[parent.length];
        for (int i = 0; i < parent.length; i++) {
            created[i] = null;
        }
        for (int i = 0; i < parent.length; i++) {
            createNode(i, parent, created);
        }
        return root_;
    }

    // https://www.geeksforgeeks.org/change-a-binary-tree-so-that-every-node-stores-sum-of-all-nodes-in-left-subtree/
    public static int leftSubtreeSum(Node node) {
        if (node == null)
            return 0;
        if (node.left == null && node.right == null)
            return node.data;
        int leftSum = leftSubtreeSum(node.left);
        int rightSum = leftSubtreeSum(node.right);

        node.data += leftSum;

        return node.data + rightSum;
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

    // https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
    public static Node lca(Node node, int n1, int n2) {
        if (node == null)
            return null;
        if (node.data == n1 || node.data == n2)
            return node;
        Node left_lca = lca(node.left, n1, n2);
        Node right_lca = lca(node.right, n1, n2);

        if (left_lca != null && right_lca != null)// found lca
            return node;

        return (left_lca != null ? left_lca : right_lca);

    }

    // https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
    static int cnt = -1;

    public static boolean nodeToRootPath_2(Node node, int val) {
        // System.out.println(cnt);
        if (node == null)
            return false;
        if (node.data == val) {
            cnt++;
            return true;
        }

        boolean filc = nodeToRootPath_2(node.left, val);
        if (filc) {
            cnt++;
            return true;
        }
        boolean firc = nodeToRootPath_2(node.right, val);
        if (firc) {
            cnt++;
            return true;
        }
        return false;
    }

    public static int dist_btw_two_nodes(Node node, int n1, int n2) {
        nodeToRootPath_2(node, n1);
        int d1 = cnt;
        cnt =-1;
        nodeToRootPath_2(node, n2);
        int d2 = cnt;
        cnt=-1;
        nodeToRootPath_2(node,lca(node, n1, n2).data);
        int d3 = cnt;
        return (d1 + d2 - (2 * d3));
    }

    public static void main(String[] args) {
        // Integer arr[] = { 5, -10, 9, null, null, 8, null, null, 3, -4, null, null, 7,
        // null, null };
        // Integer arr[] = {
        // 1,2,4,null,null,5,null,null,3,6,12,null,null,13,null,null,7,14,null,null,15,null,null};
        Integer arr[] = { 8, 3, 1, null, null, null, 10, 6, 4, null, null, 7, null, null, 14, 13, null, null, null };
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
        System.out.println();
        // subtreeSum(root, 7);
        // System.out.println(count);

        // HashMap<Integer, ArrayList<Integer>>hm = new HashMap<>();
        // diagonal(root, hm, 0);
        // for(Integer i : hm.keySet()){
        // ArrayList<Integer>list = hm.get(i);
        // for(int j =0; j<list.size();j++){
        // System.out.print(list.get(j)+" ");
        // }
        // System.out.println();
        // }

        // List<List<Integer>> ans = vertical(root);
        // for (List<Integer> i : ans) {
        // for (Integer j : i) {
        // System.out.print(j + " ");
        // }
        // System.out.println();
        // }

        // boundaryTraversal(root);
        // for (int i = 0; i < nodes.size(); i++) {
        // System.out.print(nodes.get(i) + ", ");
        // }

        // perfectBinaryTree(root);

        // int[] arr2 = { 1, 5, 5, 2, 2, -1, 3 };
        // display(constructTree(arr2));

        // leftSubtreeSum(root);
        // display(root);

        System.out.println(dist_btw_two_nodes(root, 1,14));
        // nodeToRootPath_2(root, 8);
        // System.out.println(cnt);

    }
}