import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/07/31.
 */
public class AOJ0033 {
    static final int K = 10;
    static int N;
    static int[] balls = new int[10];
    static Scanner sc = new Scanner(System.in);
    static int l, r;

    public static void read() {
        for(int i = 0; i < K; i++) {
            balls[i] = sc.nextInt();
        }
    }

    public static boolean dfs(int i) {
        // stop condition
        if(i == K) return true;

        // recursive
        boolean flag_l = false; boolean flag_r = false;
        if(l == -1 || balls[l] < balls[i]) {
            int tmp_l = l; l = i; flag_l = dfs(i + 1); l = tmp_l;
        }
        if(r == -1 || balls[r] < balls[i]) {
            int tmp_r = r; r = i; flag_r = dfs(i + 1); r = tmp_r;
        }
        return flag_l || flag_r;
    }

    public static void solve() {
        l = -1; r = -1;
        String ans = dfs(0) ? "YES" : "NO";
        System.out.println(ans);
    }

    public static void main(String[] args) {
        N = sc.nextInt();
        for(int i = 0; i < N; i++) {
            read();
            solve();
        }

    }
}
