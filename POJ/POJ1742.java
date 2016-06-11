import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/10/02.
 */

public class POJ1742 {
    static Scanner sc = new Scanner(System.in);
    static int MAX_N = 100, MAX_M = 100000;
    static int n;
    static int m;
    static int A[] = new int[MAX_N];
    static int C[] = new int[MAX_N];
    static int dp[] = new int[MAX_M + 1];

    static boolean read() {
        n = sc.nextInt(); m = sc.nextInt();
        if(n == 0 && m == 0) return false;
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            C[i] = sc.nextInt();
        }
        return true;
    }

    static void initializeDP() {
        for (int i = 0; i < MAX_M + 1; i++) {
            dp[i] = -1;
        }
    }

    static void solve() {
        initializeDP();
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (dp[j] >= 0) {
                    dp[j] = C[i];
                } else if (j - A[i] >= 0 && dp[j - A[i]] >= 0) {
                    dp[j] = dp[j - A[i]] - 1;
                } else {
                    dp[j] = -1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < m + 1; i++) {
            ans += dp[i] >= 0 ? 1 : 0;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        while(read()) {
            solve();
        }
    }
}
