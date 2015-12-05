import java.util.Scanner;

class Trie {
    char val;
    int cnt;
    Trie[] chd = new Trie[256];
    public Trie(char val) {
        this.val = val;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m;
        n = in.nextInt();
        Trie root = new Trie('^');
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            Trie cur = root;
            for (int j = 0; j < s.length(); ++j) {
                char c = s.charAt(j);
                Trie tmp = cur.chd[c];
                if (tmp == null) {
                    tmp = new Trie(c);
                    cur.chd[c] = tmp;
                }
                cur = tmp;
                ++tmp.cnt;
            }
        }
        m = in.nextInt();
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            Trie cur = root;
            int cnt = 0;
            for (int j = 0; j < s.length(); ++j) {
                char c = s.charAt(j);
                Trie tmp = cur.chd[c];
                if (tmp == null) {
                    cnt = 0;
                    break;
                }
                cur = tmp;
                cnt = cur.cnt;
            }
            System.out.println(cnt);
        }
    }
}
