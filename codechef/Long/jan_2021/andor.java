import java.util.*;

class andor {

    public static void solve(int[] a, int[] b) {
        TreeSet<Integer> ts = new TreeSet<Integer>();
        Stack<Integer> st = new Stack<Integer>();
        ts.add(0);
        st.push(0);

        int x, y;
        while (!st.isEmpty()) {
            x = (int) (st.pop());
            for (int i = 0; i < a.length; i++) {
                y = a[i];
                int or_ = (x | y);
                if (!ts.contains(or_)) {
                    ts.add(or_);
                    st.push(or_);
                }
            }
            for (int i = 0; i < b.length; i++) {
                y = b[i];
                int and_ = (x & y);
                if (!ts.contains(and_)) {
                    ts.add(and_);
                    st.push(and_);
                }
            }
        }
        System.out.println(ts.size());
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- != 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int a[] = new int[n];
            int b[] = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }
            solve(a, b);
        }
    }
}