import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/07/07.
 */
public class AOJ0118 implements Runnable {

    static Scanner sc = new Scanner(System.in);
    static int h, w;
    static int[] dx = {0, 1,  0, -1};
    static int[] dy = {1, 0, -1,  0};
    static char[][] grid = new char[105][105];

    public static boolean read() {
        h = sc.nextInt();
        w = sc.nextInt();
        if(h == 0 && w == 0) return false;

        for(int i = 0; i < h; i++) {
            grid[i] = sc.next().toCharArray();
        }
        return true;
    }

    public static void dfs(int i, int j , char c) {
        // stopping condition
        if(i < 0 || i >= h || j < 0 || j >= w) return;
        if(grid[i][j] != c) return;

        // marking
        grid[i][j] = '.';

        // recursion
        for(int k = 0; k < 4; k++) {
            dfs(i + dx[k], j + dy[k], c);
        }
    }

    public static void solve() {
        int ans = 0;

        // dfs
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(grid[i][j] != '.') {
                    ans++;
                    dfs(i, j, grid[i][j]);
                }

            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Thread(null, new AOJ0118(), "", 32 * 1024 * 1024).start();
    }

    public void run() {
        while(read()) solve();
    }

}
