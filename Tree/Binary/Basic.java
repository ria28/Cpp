import java.util.*;

public class Basic {

    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    static boolean isBalanced = true;
    public static int balancedTree(Node node){  //  difference b/w rhs and lhs height <=1 to be balanced 
        if(node == null)
            return -1;
        
        // int fac = Math.abs(height(node.left)-height(node.right));
        int hL = balancedTree(node.left) ;
        int hR = balancedTree(node.right);

        int fac =  Math.abs(hL-hR);
        if(fac >1)
            isBalanced =false;

        return (Math.max(hL,hR)+1);        
    }

    static class BSTPair{
        boolean isBST;
        int min;
        int max;
    }
    public static BSTPair isBST(Node node){
        if(node == null){
            BSTPair b = new BSTPair();
            b.isBST = true;
            b.max = Integer.MIN_VALUE;
            b.min = Integer.MAX_VALUE;
            return b;
        }

        BSTPair lp = isBST(node.left);
        BSTPair rp = isBST(node.right);
        BSTPair mp = new BSTPair();
        mp.isBST = lp.isBST && rp.isBST && (node.data >= lp.max && node.data<=rp.min);
        mp.min = Math.min(node.data, Math.min(lp.min, rp.min));
        mp.max = Math.max(node.data,Math.max(lp.max,rp.max));

        return mp;
    }

    static int tilt = 0;

    public static int tilt(Node node){
        if(node == null)
            return 0;
        int ls = tilt(node.left);
        int rs = tilt(node.right);
        tilt += Math.abs(ls-rs);
        return (ls+ rs + node.data);

    }

    public static int diameter(Node node) { // O(n^2)
        if (node == null)
            return 0;

        int ld = diameter(node.left); // distance between 2 nodes on the LHS
        int rd = diameter(node.right); // distance between 2 nodes ont the RHS
        int f = height(node.left) + height(node.right) + 2; // factor --> dia with root included

        int dia = Math.max(f, Math.max(ld, rd));

        return dia;
    }

    static class DiaPair {
        int height;
        int diameter;
    }

    public static DiaPair diameter_2(Node node) { // O(n)
        if (node == null) {
            DiaPair bp = new DiaPair();
            bp.height = -1;
            bp.diameter = 0;
            return bp;
        }
        System.out.println(node.data);

        DiaPair lp = diameter_2(node.left);
        DiaPair rp = diameter_2(node.right);

        DiaPair mp = new DiaPair();
        mp.height = Math.max(lp.height, rp.height) + 1;
        mp.diameter = Math.max(lp.height + rp.height + 2, Math.max(lp.diameter, rp.diameter));

        return mp;
    }

    public static Node removeLeaves(Node node) {
        if (node == null)
            return null;
        if (node.left == null && node.right == null)
            return null;
        node.left = removeLeaves(node.left);
        node.right = removeLeaves(node.right);
        return node;
    }

    public static void singleChildNode(Node node) {
        if (node == null)
            return;
        if ((node.left != null && node.right == null) || (node.left == null && node.right != null))
            System.out.print(node.data + ", ");

        singleChildNode(node.left);
        singleChildNode(node.right);
    }

    public static Node transformLeftClone(Node node) {// get back the orih=ginal tree from the cloned one
        if (node == null)
            return null;

        Node ltp = transformLeftClone(node.left.left); // left transformed part
        Node rtp = transformLeftClone(node.right);

        node.left = ltp;
        node.right = rtp;

        return node;
    }

    public static Node leftClone(Node node) {
        if (node == null)
            return null;
        Node lcp = leftClone(node.left); // left clone part
        Node rcp = leftClone(node.right);

        Node nnode = new Node(node.data, lcp, null);
        node.left = nnode;
        node.right = rcp;

        return node;
    }

    public static void leafToRootPath(Node node, String str) {

        if (node == null)
            return;

        if (node.left == null && node.right == null) {
            str += node.data;
            System.out.println(str);
        }

        leafToRootPath(node.left, str + node.data);
        leafToRootPath(node.right, str + node.data);
    }

    public static void kNodesFar(Node node, int data, int k) {
        ArrayList<Node> ntrp = new ArrayList<>();
        ntrp = nodeToRootPath(node, data);
        for (int i = 0; i < ntrp.size(); i++) {
            kLevelDown_helper(ntrp.get(i), k - i, i == 0 ? null : ntrp.get(i - 1));
        }
    }

    public static void kLevelDown_helper(Node node, int k, Node blocker) {
        if (k < 0 || node == blocker)
            return;

        if (k == 0)
            System.out.print(node.data + " ");

        kLevelDown_helper(node.left, k - 1, blocker);
        kLevelDown_helper(node.right, k - 1, blocker);

    }

    public static void kLevelDown(Node node, int k) {
        if (k < 0)
            return;

        if (k == 0)
            System.out.print(node.data + " ");

        kLevelDown(node.left, k - 1);
        kLevelDown(node.right, k - 1);

    }

    public static ArrayList<Node> nodeToRootPath(Node node, int val) {
        ArrayList<Node> pfLeft = new ArrayList<>();
        ArrayList<Node> pfRight = new ArrayList<>();

        if (node.data == val) {
            ArrayList<Node> list = new ArrayList<>();
            list.add(node);
            return list;
        }

        if (node.left != null)
            pfLeft = nodeToRootPath(node.left, val); // path from left child
        if (node.right != null)
            pfRight = nodeToRootPath(node.right, val); // path from right child

        if (pfLeft.size() > 0) {
            pfLeft.add(node);
            return pfLeft;
        }
        if (pfRight.size() > 0) {
            pfRight.add(node);
            return pfRight;
        }
        return new ArrayList<>();

    }

    static ArrayList<Integer> path = new ArrayList<>();

    public static boolean nodeToRootPath_2(Node node, int val) {
        if (node == null)
            return false;
        if (node.data == val) {
            path.add(val);
            return true;
        }
        boolean filc = nodeToRootPath_2(node.left, val);
        if (filc) {
            path.add(node.data);
            return true;
        }
        boolean firc = nodeToRootPath_2(node.right, val);
        if (firc) {
            path.add(node.data);
            return true;
        }
        return false;
    }

    public static void level_order(Node node) {
        Queue<Node> q = new ArrayDeque<>();
        q.add(node);

        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                System.out.print(q.peek().data + " ");
                if (q.peek().left != null)
                    q.add(q.peek().left);
                if (q.peek().right != null)
                    q.add(q.peek().right);
                q.remove();
            }
            System.out.println();
        }
    }

    static ArrayList<Integer> pre = new ArrayList<>();
    static ArrayList<Integer> in = new ArrayList<>();
    static ArrayList<Integer> post = new ArrayList<>();

    public static void traversal(Node node) {

        if (node == null)
            return;
        // System.out.println("Pre order " + node.data);
        pre.add(node.data);
        traversal(node.left);
        // System.out.println("In order :" + node.data);
        in.add(node.data);
        traversal(node.right);
        // System.out.println("Post order :" + node.data);
        post.add(node.data);
    }

    public static int height(Node node) {
        if (node == null) {
            return -1; // counting edge return -1; for counting nodes return 0
        }
        int height = Math.max(height(node.left), height(node.right)) + 1;
        return height;
    }

    static int maxi = Integer.MIN_VALUE;

    public static void max_(Node node) {
        if (node == null)
            return;

        if (node.data > maxi) {
            maxi = node.data;
        }
        max_(node.left);
        max_(node.right);
    }

    public static int sum(Node node) {
        if (node == null)
            return 0;
        int lsum = sum(node.left);
        int rsum = sum(node.right);
        int tsum = lsum + rsum + node.data;
        return tsum;
    }

    public static int size(Node node) {
        if (node == null)
            return 0;
        int lsize = size(node.left);
        int rsize = size(node.right);
        int tsize = lsize + rsize + 1;
        return tsize;
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

    public static void main(String args[]) {
        Integer arr[] = { 50, 25, 12, null, null, 37, 30, null, null, null, 75, 62, null, 70, null, null, 57, null,
                null };
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

        // display(root);

        // System.out.println(size(root));
        // System.out.println(sum(root));

        // max_(root);
        // System.out.println(maxi);

        // System.out.println(height(root));

        // traversal(root);
        // System.out.println("Preorder :");
        // for (int i = 0; i < pre.size(); i++)
        // System.out.println(pre.get(i));

        // System.out.println("Inorder :");
        // for (int i = 0; i < in.size(); i++)
        // System.out.println(in.get(i));

        // System.out.println("Postorder :");
        // for (int i = 0; i < post.size(); i++)
        // System.out.println(post.get(i));

        // level_order(root);

        // ArrayList<Integer> ntrp = nodeToRootPath(root, 75);
        // for (int i = 0; i < ntrp.size(); i++)
        // System.out.print(ntrp.get(i) + " ");

        // nodeToRootPath_2(root, 70);
        // for (int i = 0; i < path.size(); i++)
        // System.out.print(path.get(i) + " ");

        // kLevelDown(root, 2);

        // int data = 75;
        // kNodesFar(root, data, 2);

        // leafToRootPath(root, " ");

        // display(transformLeftClone(leftClone(root)));

        // singleChildNode(root);

        // display(removeLeaves(root));

        // DiaPair p = diameter_2(root);
        // System.out.println(p.diameter + ", " + p.height);

        // tilt(root);
        // System.out.println(tilt);

        // System.out.println( isBST(root).isBST);

        System.out.println(balancedTree(root));
    }
}