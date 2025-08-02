import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean x = sc.nextBoolean();
        System.out.println(x);
        System.out.println(!x);
        sc.close();
    }
}