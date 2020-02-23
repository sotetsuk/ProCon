import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class D {
    static Scanner sc = new Scanner(System.in);
    static int N, M;
    static int[][] G = new int[12][12];
    static List<Integer> arr;

    public static void main(String[] args) {
        read();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            arr = new ArrayList<>(20);
            int a = solve(i);
            ans = Math.max(ans, a);
        }
        System.out.println(ans);
    }

    static void read() {
        N = sc.nextInt();
        M = sc.nextInt();
        int x, y;
        for (int i = 0; i < M; i++) {
            x = sc.nextInt() - 1;
            y = sc.nextInt() - 1;
            G[x][y] = 1;
            G[y][x] = 1;
        }

        for (int i = 0; i < N; i++) {
            G[i][i] = 1;
        }
    }

    static int solve(int i) {
        arr.add(i);
        for (int j = 0; j < N; j++) {
            boolean flag = true;
            for (Integer e: arr) {
                if (G[e][j] == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag && i != j) {
                arr.add(j);
            }
        }

        return arr.size();
    }
}
