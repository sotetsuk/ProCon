import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/07/14.
 */
public class AOJ0558 {
    public static final int MAX_H = 1005;
    public static final int MAX_W = 1005;
    public static final int MAX_N = 15;
    public static int H, W, N;
    public static char[][] grid = new char[MAX_H][MAX_W];
    public static int[][] d = new int[MAX_H][MAX_W];
    public static Pair[] pos = new Pair[MAX_N];

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};

    public static class Pair {
        int first, second;
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void read() {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt(); W = sc.nextInt(); N = sc.nextInt();

        for(int i = 0; i < H; i++) {
            grid[i] = sc.next().toCharArray();
        }

        // set all of cheese positions at pos
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(grid[i][j] == 'S') {
                    pos[0] = new Pair(i, j);
                }
                if('0' <= grid[i][j] && grid[i][j] <= '9') {
                    int k = Integer.valueOf(String.valueOf(grid[i][j]));
                    pos[k] = new Pair(i, j);
                }
            }
        }
    }

    public static int bfs(Pair start, Pair goal) {
        // fill 2d array d by -1
        for(int[] arr: d) Arrays.fill(arr, -1);
        // This deque is used as queue for bfs
        ArrayDeque<Pair> q = new ArrayDeque<Pair>();
        q.add(start);
        d[start.first][start.second] = 0;
        while(!q.isEmpty()) {
            Pair now = q.pop();
            int nowX = now.first; int nowY = now.second;
            // stopping condition
            if(nowX == goal.first && nowY == goal.second) {
                return d[nowX][nowY];
            }
            // search 4 destination
            for(int i = 0; i < 4; i++) {
                Pair next = new Pair(nowX + dx[i], nowY + dy[i]);
                int nextX = next.first; int nextY = next.second;
                if(0 <= nextX && nextX < H && 0 <= nextY && nextY < W
                        && grid[nextX][nextY] != 'X' && d[nextX][nextY] == -1) {
                    q.add(next);
                    d[nextX][nextY] = d[nowX][nowY] + 1;
                }
            }
        }

        return -1; // something is wrong
    }

    public static void main(String[] args) {
            int ans = 0;
            read();
            for(int i = 0; i < N; i++) {
                ans += bfs(pos[i], pos[i + 1]);
            }
            System.out.println(ans);
    }

}