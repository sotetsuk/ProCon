import java.util.BitSet;
import java.util.Scanner;

/**
 * Created by sotetsuk on 2015/07/18.
 */
public class AOJ0525 {

    static Scanner sc = new Scanner(System.in);
    static final int MAX_R = 15, MAX_C = 1005;
    static int R, C;
    static BitSet[] o = new BitSet[MAX_R];

    public static boolean read() {
        R = sc.nextInt();
        C = sc.nextInt();
        if(R == 0 && C == 0) return false;
        for(int i = 0; i < R; i++) {
            o[i] = new BitSet(MAX_C);
            for(int j = 0; j < C; j++) {
                if(sc.nextInt() == 1) o[i].set(j);
            }
        }
        return true;
    }

    public static void flip(int i) {
        for(int j = 0; j < R; j++) {
            if((i >> j & 1) == 1) {
                o[j].flip(0, C);
            }
        }
    }

    public static int count() {
        int ret = 0;
        for(int j = 0; j < C; j++) {
            int s = 0;
            for(int i = 0; i < R; i++) {
                s += o[i].get(j) ? 1 : 0;
            }
            ret += Math.max(s, R - s);
        }
        return ret;
    }

    public static void solve() {
        int ans = 0;
        // search all 2^R patterns
        for(int i = 0; i < (1 << R); i++) {
            flip(i);
            ans = Math.max(ans, count());
            flip(i);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        while(read()) {
            solve();
        }
    }
}
