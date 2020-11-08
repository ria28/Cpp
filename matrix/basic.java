import java.util.*;

class basic {

    // https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
    public static String tictactoe(int[][] moves) {
        int n = 3;
        int[] rows = new int[n];
        int[] cols = new int[n];
        int diag1 = 0;
        int diag2 = 0;
        int currPlayer = 1;   // 1 is 'A', -1 is 'B'
    
        for (int[] currMove : moves) {
            rows[currMove[0]] += currPlayer;
            cols[currMove[1]] += currPlayer;
            diag1 = currMove[0] == currMove[1] ? diag1 + currPlayer : diag1;
            diag2 = currMove[0] + currMove[1] == n - 1 ? diag2 + currPlayer : diag2; 
            
            if (Math.abs(rows[currMove[0]]) == n || Math.abs(cols[currMove[1]]) == n || Math.abs(diag1) == n || Math.abs(diag2) == n) {
                return currPlayer == 1 ? "A" : "B";
            }
            currPlayer *= -1;
        }
        
        return moves.length < 9 ? "Pending" : "Draw";
    }

    // https://leetcode.com/problems/valid-tic-tac-toe-state/
    public static boolean validTicTacToe(String[] board) {
        int[] rows = new int[3];
        int[] cols = new int[3];
        int diag = 0, antidiag = 0, turns = 0;
        boolean xwin = false, owin = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'X') {
                    turns++;
                    rows[i]++;
                    cols[j]++;
                    if (i == j)
                        diag++;
                    if (i + j == 2)
                        antidiag++;
                } else if (board[i].charAt(j) == 'O') {
                    turns--;
                    rows[i]--;
                    cols[j]--;
                    if (i == j)
                        diag--;
                    if (i + j == 2)
                        antidiag--;
                }
            }
        }
        xwin = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || diag == 3
                || antidiag == 3;
        owin = rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || cols[0] == -3 || cols[1] == -3 || cols[2] == -3
                || diag == -3 || antidiag == -3;

        if (xwin && turns == 0 || owin && turns == 1) {
            return false;
        }
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }

    public static void main(String[] args) {
        String[] board = { "XOX", "O O", "XOX" }; // true
        // String[] board = {"XXX", " ", "OOO"}; // false
        System.out.println(validTicTacToe(board));

        int[][] moves = { {0,0} ,{2,0}, {1,1}, {2,1}, {2,2} };
        // int[][] moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]  //draw
        System.out.println(tictactoe(moves));
    }
}