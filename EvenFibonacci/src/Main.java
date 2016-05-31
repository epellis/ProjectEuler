public class Main {

    private final static int MAXIMUM = 4000000;

    private static int getFibonacci(int iteration) {
        int firstVal = 0;
        int secondVal = 1;
        int holding;

        for (int i = 0; i < iteration; i++) {
            holding = firstVal;
            firstVal = secondVal;
            secondVal = firstVal + holding;
        }

        return secondVal;
    }

    private static int getEvenSum(int max) {
        int sum = 0;
        int iteration = 0;
        int fibonacci = getFibonacci(iteration);


        while (max >= fibonacci) {

            if (fibonacci % 2 == 0) {
                sum +=fibonacci;
            }

            iteration++;
            fibonacci = getFibonacci(iteration);
            System.out.println(fibonacci);
        }

        return sum;
    }

    public static void main(String[] args) {
        System.out.println("Your number is: " + getEvenSum(MAXIMUM));

    }
}
