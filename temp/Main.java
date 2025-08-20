import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();
        String temp = "", ans = "";
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == ' ') {
                temp = " " + temp;
                ans = temp + ans;
                temp = "";
            } else
                temp += c;
        }
        ans = temp + ans;
        System.out.println(ans);
    }
}