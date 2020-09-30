import java.util.*;

public class ques{

    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    }

    public static String serialize(Node node) {
        StringBuilder sb = new StringBuilder();
        if (node != null) {
            sb.append(node.data).append(",");
            for (Node child : node.children) {
                sb.append(serialize(child));
            }
            sb.append(")");
        }
        return sb.toString();
    }

    public static void deserialize(String str) {
        System.out.println(str);
        Node root = null;
        Stack<Node> st = new Stack<>();
        StringBuilder data = new StringBuilder(); // for 20 otherwise it'll pick 2,0 separately

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ',') {
                Node node = new Node(Integer.parseInt(data.toString()));
                if (!st.isEmpty()) {
                    st.peek().children.add(node);
                    
                } else {
                    // Integer.parseInt(String.valueOf(str.charAt(i - 1))); for 20 it'll take 0 this not valid we need to use data string builder
                    root = node;
                }
                st.push(node);
                data = new StringBuilder();
            } else if(str.charAt(i) == ')'){
                st.pop();
            }
            else{
                data.append( str.charAt( i ) );
            }
        }

        display(root);
    }

    static Node large=null;
    static Node slarge= null;
    public static void secondLargest(Node node){
        if(large == null)
            large = node;
        for(Node child : node.children){
            secondLargest(child);
        }

        if(large.data < node.data){
            slarge = large;
            large = node;
        }else if(slarge.data<node.data){
            slarge = node;
        }
    }

    // https://www.geeksforgeeks.org/node-maximum-sum-immediate-children-n-ary-tree/
    static int maxSum = Integer.MIN_VALUE;
    public static void maxSumChildren(Node node){
        int sum =0;
        for(Node child: node.children){
            sum+=child.data;
            maxSumChildren(child);
        }
        sum += node.data;
        if(maxSum<sum)
            maxSum = sum;
    }

    // https://www.geeksforgeeks.org/given-n-ary-tree-count-number-nodes-number-children-parent/
    static int maxCnt = Integer.MIN_VALUE;
    static int no =0;
    public static int countNodes(Node node){
        int cnt =0;
        for(Node child: node.children){
            cnt++;
            int ccnt=countNodes(child);  
            
            if(cnt < ccnt){
                no++;
            }
        }
        return cnt;
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
        // int[] arr = { 10, 20, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1 };

        // int[] arr = { 10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1 };
        int[] arr = { 10, 20,30,-1,40,-1,-1,50,60,-1,70,-1,80,-1,-1,-1};

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
        // deserialize(serialize(root));
        // secondLargest(root);
        // System.out.println(slarge.data);
        // maxSumChildren(root);
        // System.out.println(maxSum);
        countNodes(root);
        System.out.println(no);
        display(root);
    }
}