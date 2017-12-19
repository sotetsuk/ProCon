import java.util.Scanner;

public class D {

    static Scanner sc = new Scanner(System.in);
    static int H, W;
    static char[][] c = new char[300][300];
    static int[] d = new int[300];
    static int ans = 1 << 31 - 1;

    public static void main(String[] args) {
        read();

        for (int i = 0; i < W; i++) {
            for (int j = 0; j < W; j++) {
                d[j] = 0;
            }
            dfs(i, 0);
        }
        System.out.println(ans);
    }

    static void read() {
        H = sc.nextInt();
        W = sc.nextInt();

        for (int i = 0; i < H; i++) {
            c[i] = sc.next().toCharArray();
        }
    }

    static int getCost(int n) {
        if (d[n] == H) {
            return 0;
        }

        int ret = 0;
        for (int i = 0; i < H - d[n]; i++) {
            if (n > 0 && i + d[n] - d[n - 1] >= 0 && i + d[n] - d[n - 1] < H
                    && c[i][n] == c[i + d[n] - d[n - 1]][n - 1]) {
                ret += 1;
            }
            if (n < W - 1 && i + d[n] - d[n + 1] >= 0 && i + d[n] - d[n + 1] < H
                    && c[i][n] == c[i + d[n] - d[n + 1]][n + 1]) {
                ret += 1;
            }
        }

        return ret;
    }

    static boolean done() {
        for (int i = 0; i < W; i++) {
            if (d[i] != H) {
                return false;
            }
        }

        return true;
    }

    static void dumpD() {
        String s = "";
        for (int i = 0; i < W; i++) {
            s += String.format("%d ", d[i]);
        }

        System.out.println(s);
    }

    static void dfs(int n, int s) {
        dumpD();
        System.out.println(n);

        int cost = getCost(n);
        System.out.println(cost);
        d[n]++;

        if (done()) {
            System.out.println(String.format("done!: %d", cost + s));
            if (cost + s < ans) {
                ans = cost + s;
            }
            return;
        }

        for (int i = 0; i < W; i++) {
            if (d[i] >= H) {
                continue;
            }

            dfs(i, s + cost);
        }

        d[n]--;
    }
}
