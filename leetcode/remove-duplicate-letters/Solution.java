public class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<Character>();
        boolean[] set = new boolean[26];
        int[] last = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (set[ch - 'a']) {
                continue;
            }
            while (!stack.isEmpty() && i < last[stack.peek() - 'a']
                    && stack.peek() > ch) {
                set[stack.pop() - 'a'] = false;
            }
            stack.push(ch);
            set[ch - 'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < stack.size(); ++i) {
            sb.append(stack.get(i));
        }
        return sb.toString();
    }
}
