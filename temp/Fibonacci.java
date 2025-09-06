import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        f(0, 1, n);
    }

    public static void f(int a, int b, int n) {
        if (n == 0)
            return;
        else {
            System.out.print(a + " ");
            f(b, a + b, n - 1);
        }
    }
}