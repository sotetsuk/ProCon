import java.util.Scanner;

public class D {

    static Scanner sc = new Scanner(System.in);
    static int R, C, X, Y, D, L;
    static long dp[][] = new long[1000][1000];
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        read();
        long ans = count();
        ans = (ans * (R - X + 1)) % MOD;
        ans = (ans * (C - Y + 1)) % MOD;
        System.out.println(ans);
    }

    public static void read() {
        R = sc.nextInt();
        C = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        D = sc.nextInt();
        L = sc.nextInt();
    }

    public static long count() {
        int N = X * Y;
        // System.out.println(comb(4, 2));
        return comb(N, D);
    }

    public static long comb(int n, int k) {
        if (n == k || k == 0) {
            return 1;
        }

        if (dp[n][k] > 0) {
            return dp[n][k];
        }

        return dp[n][k] = ((comb(n - 1, k - 1) + comb(n - 1, k)) % MOD);
    }
}
