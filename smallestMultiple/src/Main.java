public class Main {
    private static boolean isDivisible(int num, int max) {
        int multiple = 2;

        while (num % multiple == 0 && multiple <= max) {
            multiple++;
        }

        return (multiple - 1 == max);
    }

    private static int smallestMultiple(int max) {
        int num = 1;

        while (!isDivisible(num, max)) {
            num++;
        }

        return num;
    }

    public static void main(String[] args) {
        final int MAXNUM = 20;

        System.out.println(smallestMultiple(MAXNUM));
    }
}
