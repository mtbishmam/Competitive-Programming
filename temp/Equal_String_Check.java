import java.util.Scanner;

public class Equal_String_Check {
    public static void main(String[] args) {
        String s1, s2;
        Scanner sc = new Scanner(System.in);
        s1 = sc.nextLine();
        s2 = sc.nextLine();
        int n = s1.length();
        int m = s2.length();
        boolean isEqual = true;
        if (n == m) {
            for (int i = 0; i < n; i++) {
                char c1 = s1.charAt(i);
                char c2 = s2.charAt(i);
                if (c1 != c2 || (c1 - c2 != 32 && c1 - c2 != -32)) {
                    isEqual = false;
                    System.err.println(c1 + " " + c2);
                    break;
                }
            }
        } else
            isEqual = false;
        System.out.println(isEqual ? "Equal" : "Not Equal");
        sc.close();
    }
}