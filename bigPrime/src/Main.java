public class Main {
    private static boolean isPrime(long num) {
        boolean isPrime = true;

        if (num == 1) {
            isPrime = false;
        }

        for (int i = 2; i <= (long)Math.sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
            }
        }

        return isPrime;
    }

    private static long findPrime(long index) {
        long ind = index;
        long num = 1;
        long startTime = System.currentTimeMillis();

        while (ind > 0) {

            if (isPrime(num)) {
                ind--;
                if (ind % 10000 == 0) {
                    System.out.println("Time to find index: " + (index - ind) + " was " + (System.currentTimeMillis() - startTime) + " ms");
                }
                startTime = System.currentTimeMillis();
            }
            num++;
        }

        return num - 1;
    }

    public static void main(String[] args) {
        final int INDEX = 100000;
        long startTime = System.currentTimeMillis();

        System.out.println("The " + INDEX + "th prime number is: " + findPrime(INDEX));

        System.out.println("This was accomplished in " + (System.currentTimeMillis() - startTime) + " milliseconds");
    }

}
