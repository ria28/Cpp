import java.util.*;

public class ria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int q = 0; q < t; q++) {

            int n = sc.nextInt();
            int x = sc.nextInt();
            int[] arr = new int[n];
            for (int k = 0; k < n; k++)
                arr[k] = sc.nextInt();
            boolean ooperationNotOccured = true;

            if (n > 2) {
                for (int k = 0; k < n - 1 && x-- > 0; k++) {
                    if (arr[k] == 0) {
                        x++;
                        continue;
                    } else {
                        ooperationNotOccured = false;
                        int p = (int) (Math.log(arr[k]) / Math.log(2));
                        arr[k] = arr[k] ^ (int) Math.pow(2, p);
                        boolean jnotfound = true;
                        for (int j = k + 1; j < n - 1; j++) {
                            int temp = arr[j] ^ (int) Math.pow(2, p);
                            if (temp < arr[j]) {
                                arr[j] = temp;
                                jnotfound = false;
                                break;

                            }
                        }
                        if (jnotfound) {
                            arr[n - 1] ^= (int) Math.pow(2, p);
                        }
                    }
                    if (arr[k] != 0)
                        k--;
                } // for loop ends

                if (ooperationNotOccured) {
                    int b = x % 2;
                    while (b-- > 0) {
                        int p = 0;
                        arr[n - 2] = arr[n - 2] ^ (int) Math.pow(2, p);
                        arr[n - 1] = arr[n - 1] ^ (int) Math.pow(2, p);
                    }
                }
            } else { // n==2
                if (arr[0] == 0) {
                    if (x % 2 != 0) {
                        arr[0] = 1;
                        arr[1] = arr[1] ^ 1;
                    }
                } else {
                    while (x-- > 0) {
                        int p = (int) (Math.log(arr[0]) / Math.log(2));
                        arr[0] = arr[0] ^ (int) Math.pow(2, p);
                        arr[1] = arr[1] ^ (int) Math.pow(2, p);
                        if (arr[0] == 0)
                            break;
                    }
                    if (x > 0 && x % 2 != 0) {
                        arr[0] = 1;
                        arr[1] = arr[1] ^ 1;
                    }
                }
            }

            StringBuilder s = new StringBuilder();
            for (int i = 0; i < n; i++) {
                s.append(arr[i]).append(" ");
            }
            System.out.println(s);
        }
    }
}
