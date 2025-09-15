import java.util.Scanner;

public class final_tracing_SetA {
    public static void main(String[] args) {
        int n = 4;
        System.out.println(foo(n));
    }

    public static int foo(int n) {
        int sum = 0;
        if (n > 0) {
            int left = foo(n - 1);
            int right = bar(n + left);
            sum = left + right;
        }
        System.out.println(sum);
        return sum - n;
    }

    public static int bar(int x) {
        int y = 2 * x;
        return x - x * y;
    }
}