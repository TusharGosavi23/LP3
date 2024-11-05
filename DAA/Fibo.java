import java.util.*;

class Fibo {

    static int RecursiveCnt = 0;
    static int NonRecursiveCnt = 0;
    
    public static int fiboRec(int n) {
        RecursiveCnt++;
        if (n <= 1) {
            return n;
        }
        return fiboRec(n - 1) + fiboRec(n - 2);
    }

    public static void printRec(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(fiboRec(i) + " ");
        }
        System.out.println("\nRecursive steps: " + RecursiveCnt);
    }

    public static long fiboNRec(int n) {
        if (n <= 1) {
            return n;
        }

        long previous = 0;
        long current = 1;
        System.out.print(previous + " " + current + " ");
        for (int i = 2; i < n; i++) {
            long next = previous + current;
            previous = current;
            current = next;
            System.out.print(current + " ");
            NonRecursiveCnt++;
        }
        System.out.println("\nNon-recursive steps: " + NonRecursiveCnt);
        return current;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of Fibonacci numbers: ");
        int n = sc.nextInt();


        System.out.println("Recursive Fibonacci Series:");
        printRec(n);

        RecursiveCnt = 0;

        System.out.println("Non-recursive Fibonacci Series:");
        fiboNRec(n);

        sc.close();
    }
}
