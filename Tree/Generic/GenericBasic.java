import java.util.*;

public class GenericBasic {

    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    }

    public static boolean areMirror(Node n1, Node n2) {
        if (n1.children.size() != n2.children.size())
            return false;
        for (int i = 0; i < n1.children.size(); i++) {
            int j = n1.children.size() - 1 - i; // *************************************imp
            Node c1 = n1.children.get(i);
            Node c2 = n2.children.get(j);

            if (areMirror(c1, c2) == false) {
                return false;
            }
        }
        return true;
    }

    public static boolean areSimilar(Node n1, Node n2) {
        if (n1.children.size() != n2.children.size())
            return false;

        for (int i = 0; i < n1.children.size() - 1; i++) {
            Node c1 = n1.children.get(i);
            Node c2 = n2.children.get(i);
            if (areSimilar(c1, c2) == false) {
                return false;
            }
        }
        return true;
    }

    // Distance between nodes
    public static void distBtwNodes(Node node, int d1, int d2) {
        ArrayList<Integer> list1 = nodeToRootPath(node, d1);
        ArrayList<Integer> list2 = nodeToRootPath(node, d2);

        int i = list1.size() - 1;
        int j = list2.size() - 1;

        while (i >= 0 && j >= 0 && list1.get(i) == list2.get(j)) {
            i--;
            j--;
        }
        i++;
        j++;

        System.out.println(i + j);
    }

    // lowest common ancestor
    public static int lca(Node node, int d1, int d2) {
        ArrayList<Integer> list1 = nodeToRootPath(node, d1);
        ArrayList<Integer> list2 = nodeToRootPath(node, d2);

        int i = list1.size() - 1;
        int j = list2.size() - 1;

        while (i >= 0 && j >= 0 && list1.get(i) == list2.get(j)) {
            i--;
            j--;
        }
        i++;
        j++;

        return list1.get(i);

    }

    // boolean in findInTree -------> Arraylist here
    public static ArrayList<Integer> nodeToRootPath(Node node, int val) {
        if (node.data == val) {
            ArrayList<Integer> list = new ArrayList<>();
            list.add(node.data);
            return list;
        }

        for (Node child : node.children) {
            ArrayList<Integer> ptc = nodeToRootPath(child, val);
            if (ptc.size() > 0) {
                ptc.add(node.data);
                return ptc;
            }
        }
        return new ArrayList<>();
    }

    public static boolean findInTree(Node node, int val) {
        if (node.data == val)
            return true;
        for (Node child : node.children) {
            boolean fic = findInTree(child, val);
            if (fic)
                return true;
        }
        return false;
    }

    public static Node linearize2(Node node) {
        if (node.children.size() == 0) // leaf
            return node;

        // last tail
        Node lt = linearize2(node.children.get(node.children.size() - 1));
        while (node.children.size() > 1) {
            Node last = node.children.remove(node.children.size() - 1);
            Node sl = node.children.get(node.children.size() - 1);
            // second last tail
            Node slt = linearize2(sl);
            slt.children.add(last);
        }
        return lt;
    }

    // O(n2)
    public static void linearize(Node node) {
        for (Node child : node.children) {
            linearize(child);
        }
        while (node.children.size() > 1) {
            Node lc = node.children.remove(node.children.size() - 1);
            Node sl = node.children.get(node.children.size() - 1);
            Node slt = getTail(sl);
            slt.children.add(lc);
        }
    }

    public static Node getTail(Node node) {
        while (node.children.size() == 1) {
            node = node.children.get(0);
        }
        return node;
    }

    // Removal should be done in preorder to avoid unnecessary removals
    public static void removeLeaves(Node node) {

        // remove in reverse order
        for (int i = node.children.size() - 1; i >= 0; i--) {
            Node child = node.children.get(i);
            if (child.children.size() == 0) {
                node.children.remove(i);
            }
        }

        for (Node child : node.children) {
            removeLeaves(child);
        }
    }

    public static void mirror(Node node) {

        for (Node child : node.children) {
            mirror(child);
        }
        Collections.reverse(node.children);
    }

    // pair class
    public static class Pair {
        Node node;
        int level;

        Pair(Node node, int level) {
            this.node = node;
            this.level = level;
        }
    }

    public static void level_order_linewise_4(Node node) {
        Queue<Pair> mq = new ArrayDeque<>();
        mq.add(new Pair(node, 1));

        int level = 1;
        while (mq.size() > 0) {
            Pair p = mq.remove();
            if (p.level > level) {
                level = p.level;
                System.out.println();
            }

            System.out.print(p.node.data + " ");
            for (Node child : p.node.children) {
                Pair cp = new Pair(child, p.level + 1);
                mq.add(cp);
            }
        }
    }

    public static void level_order_linewise_3(Node node) {
        Queue<Node> mq = new ArrayDeque<>();
        mq.add(node);

        while (mq.size() > 0) {
            int cicl = mq.size(); // children in current level
            for (int i = 0; i < cicl; i++) {
                node = mq.remove();
                System.out.print(node.data + " ");

                for (Node child : node.children) {
                    mq.add(child);
                }
            }
            System.out.println();
        }
    }

    public static void level_order_linewise_2(Node node) {
        Queue<Node> mq = new ArrayDeque<>();
        mq.add(node);
        mq.add(new Node(-1)); // instead of null we take -1 as mark that te level has ended

        while (mq.size() > 0) {
            node = mq.remove();
            if (node.data == -1) {
                if (mq.size() > 0)
                    mq.add(new Node(-1));
                System.out.println();
            } else {
                System.out.print(node.data);
                for (Node child : node.children) {
                    mq.add(child);
                }
            }
        }
    }

    public static void level_order_linewise_ZigZag(Node node) {
        Stack<Node> ms = new Stack<>();
        Stack<Node> cs = new Stack<>();
        ms.push(node);
        int level = 0;

        while (ms.size() > 0) {
            node = ms.pop();
            System.out.print(node.data + " ");

            if (level % 2 == 0) {
                for (Node child : node.children) { // for(int i =0; i<node.children.size();i++){
                    cs.push(child); // cs.push(node.children.get(i));
                }
            } else {
                for (int i = node.children.size() - 1; i >= 0; i--) {
                    cs.push(node.children.get(i));

                }
            }

            if (ms.size() == 0) {
                ms = cs;
                cs = new Stack<>();
                level++;
                System.out.println();
            }
        }

    }

    public static void level_order_linewise(Node node) {
        Queue<Node> mq = new ArrayDeque<>();
        mq.add(node);
        Queue<Node> cq = new ArrayDeque<>();

        while (mq.size() > 0) {
            node = mq.remove();
            System.out.print(node.data + " ");
            for (Node child : node.children) {
                cq.add(child);
            }

            if (mq.size() == 0) {
                mq = cq;
                cq = new ArrayDeque<>();
                System.out.println();
            }
        }
    }

    public static void level_order(Node node) {
        Queue<Node> q = new ArrayDeque<>();
        q.add(node);
        while (q.size() > 0) {
            node = q.remove();
            System.out.print(node.data);
            for (Node child : node.children) {
                q.add(child);
            }

        }
        System.out.println(".");
    }

    public static void Pre_Post_traversal(Node node) {

        System.out.println("Node Pre" + node.data);
        for (Node child : node.children) {
            System.out.println("Edge Pre" + node.data + "--" + child.data);
            Pre_Post_traversal(child);
            System.out.println("Edge Post" + node.data + "--" + child.data);
        }
        System.out.println("Node Post" + node.data);
    }

    public static int height(Node node) {
        int ht = -1;
        for (Node child : node.children) {
            int ch = height(child);
            ht = Math.max(ch, ht);
        }
        ht += 1;
        return ht;
    }

    public static int max(Node node) {
        int max = Integer.MIN_VALUE;
        for (Node child : node.children) {
            int cm = max(child);
            max = Math.max(cm, max);
        }
        max = Math.max(max, node.data);
        return max;
    }

    public static int size(Node node) {
        int count = 0;
        for (Node child : node.children) {
            count += size(child);
        }
        return count + 1;
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

    public static void main(String args[]) {
        // int[] arr = { 10, 20, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90,
        // -1, -1, 40, 100, -1, -1,
        // -1 };

        int[] arr = { 10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1 };

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

        // display(root);
        // System.out.println(size(root));
        // System.out.println(max(root));
        // System.out.println(height(root));

        // Pre_Post_traversal(root);
        // level_order(root);
        // level_order_linewise(root);
        // level_order_linewise_ZigZag(root);
        // level_order_linewise_2(root);
        // level_order_linewise_3(root);
        // level_order_linewise_4(root);
        // mirror(root);
        // removeLeaves(root);
        // linearize2(root);
        // System.out.println(findInTree(root, 50));

        // ArrayList<Integer> list = nodeToRootPath(root, 110);
        // for(int i =0;i<list.size();i++)
        // System.out.println(list.get(i)+" ");

        // System.out.println(lca(root,110,70));
        // distBtwNodes(root, 50, 110);
        System.out.println(areMirror(root, root));
        // display(root);

    }
}
