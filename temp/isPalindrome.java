public class isPalindrome {
    public static void main(String[] args) {
        String s = "abcdcba";
        String s2 = "abc";
        String s3 = "aaa";
        String s4 = "0110";
        System.out.println(s + " " + isPalindrome(s, 0));
        System.out.println(s2 + " " + isPalindrome(s2, 0));
        System.out.println(s3 + " " + isPalindrome(s3, 0));
        System.out.println(s4 + " " + isPalindrome(s4, 0));
    }

    public static boolean isPalindrome(String s, int i) {
        int n = s.length();
        if (i >= n / 2)
            return true;
        if (s.charAt(i) != s.charAt(n - i - 1))
            return false;
        return isPalindrome(s, i + 1);
    }
}
// abda