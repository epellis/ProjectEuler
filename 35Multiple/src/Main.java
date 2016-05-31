public class Main {
    private static int findMultipleSum(int num) {
        if (num <= 0) {
            return 0;
        }

        else if (num % 3 == 0 || num % 5 == 0) {
            return num + findMultipleSum(num - 1);
        }

        else {
            return findMultipleSum(num - 1);
        }
    }

    public static void main(String[] args) {
        final int MAXIMUM = 1000;

        System.out.println(findMultipleSum(MAXIMUM - 1));
    }
}
