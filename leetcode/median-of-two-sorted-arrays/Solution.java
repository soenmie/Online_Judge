public class Solution {
    private int[] a;
    private int[] b;
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        a = nums1;
        b = nums2;
        int n = a.length + b.length;
        if (n % 2 == 1) {
            return findK(n / 2);
        } else {
            return findK((n - 1) / 2) / 2 + findK(n / 2) / 2;
        }
    }
    private double findK(int k) {
        int i = 0, j = 0, m = a.length, n = b.length;
        while (true) {
            if (i == m) {
                return b[j + k];
            }
            if (j == n) {
                return a[i + k];
            }
            if (k == 0) {
                return Math.min(a[i], b[j]);
            }
            int h = k + 1;
            int x = i + h / 2;
            int y = j + h - h / 2;
            if (x > m) {
                x = m;
                y = i + j + h - m;
            }
            if (y > n) {
                y = n;
                x = i + j + h - n;
            }
            if (a[x - 1] < b[y - 1]) {
                k -= x - i;
                i = x;
            } else {
                k -= y - j;
                j = y;
            }
        }
    }
}
