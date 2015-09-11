import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/09/11.
 */
public class POJ2385 {
    static Scanner sc = new Scanner(System.in);
    static int MAX_T = 1000, MAX_W = 30;
    static int T, W;
    static int[] apples = new int[MAX_T];

    static int[][][] dp = new int[MAX_T][MAX_W + 1][2];

    static void read() {
        T = sc.nextInt();
        W = sc.nextInt();
        for(int i = 0; i < T; i++) apples[i] = sc.nextInt() - 1;
    }

    static int swichPosition(int pos) {
        return pos == 0 ? 1 : 0;
    }

    static int canCatchApple(int t, int pos) {
        return pos == apples[t] ? 1 : 0;
    }

    static int dfs(int nowT, int remainedW, int nowPos) {
        // stopping condition
        if(nowT >= T) return 0;
        if(dp[nowT][remainedW][nowPos] > 0) return dp[nowT][remainedW][nowPos];

        int ret = canCatchApple(nowT, nowPos) + dfs(nowT + 1, remainedW, nowPos);
        if(remainedW > 0) {
            int switchedPos = swichPosition(nowPos);
            ret = Math.max(ret, canCatchApple(nowT, switchedPos) + dfs(nowT + 1, remainedW - 1, switchedPos));
        }

        return dp[nowT][remainedW][nowPos] = ret;
    }

    public static void main(String args[]) {
        read(); // t = {0, ..., T-1}, pos = {0, 1}
        System.out.println(dfs(0, W, 0)); // start with pos = 0
        return;
    }
}
