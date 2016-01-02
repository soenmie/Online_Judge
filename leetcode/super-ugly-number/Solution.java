public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        List<Integer> q = new ArrayList<Integer>();
        int[] idx = new int[primes.length];
        q.add(1);
        while (q.size() < n) {
            int x = Integer.MAX_VALUE;
            for (int i = 0; i < primes.length; ++i) {
                x = Math.min(x, q.get(idx[i]) * primes[i]);
            }
            q.add(x);
            for (int i = 0; i < primes.length; ++i) {
                if (x == q.get(idx[i]) * primes[i]) {
                    ++idx[i];
                }
            }
        }
        return q.get(n - 1);
    }
}
