import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();
        String temp = "";
        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ' ') {
                for (int j = temp.length() - 1; j >= 0; j--)
                    System.out.print(temp.charAt(j));
                System.out.print(' ');
                temp = "";
            } else
                temp += c;
        }
        for (int j = temp.length() - 1; j >= 0; j--)
            System.out.print(temp.charAt(j));
        temp = "";
    }
}
