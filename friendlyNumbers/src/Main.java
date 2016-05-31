import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    private static ArrayList<Integer> getFactors(int num) {
        ArrayList<Integer> factors = new ArrayList<>();

        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                factors.add(i);
            }
        }

        return factors;
    }

    private static int arrayListSum(ArrayList<Integer> numList) {
        int sum = 0;

        for (int i : numList) {
            sum +=i;
        }

        return sum;
    }

    private static boolean isAmicable(int num) {
        boolean isAmicable = false;

        int sum = arrayListSum(getFactors(num));

        if (arrayListSum(getFactors(sum)) == num && sum != num) {
            isAmicable = true;
            System.out.println(num + " is an amicable pair of: " + sum);
        }

        return isAmicable;
    }

    public static void main(String[] args) {

        final int MAX = 10000;

        ArrayList<Integer> amicableNums = new ArrayList<>();

        for (int i = 1; i < MAX; i++) {
            if (isAmicable(i)) {
                amicableNums.add(i);
            }
        }

        System.out.println(Arrays.toString(amicableNums.toArray()));

        System.out.println("Sum is: " + arrayListSum(amicableNums));

    }
}
