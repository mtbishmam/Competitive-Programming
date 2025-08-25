import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();

        // make lowercase
        String low = "";
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if ('A' <= c && c <= 'Z')
                c = (char) (c + 32);
            low += c;
        }

        String ans = "", word = "";
        s = low;
        int ans_vow = n + 1;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == ' ' || i + 1 == n) {
                int vow_count = 0;
                for (int j = 0; j < word.length(); j++) {
                    char c2 = word.charAt(j);
                    if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')
                        vow_count++;
                }
                if (vow_count < ans_vow) {
                    ans_vow = vow_count;
                    ans = word;
                }
                word = "";
            } else
                word += c;
        }
        System.out.println("Word: " + ans);
        System.out.println("Vow: " + ans_vow);
    }
}