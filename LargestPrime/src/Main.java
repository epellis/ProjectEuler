import java.util.*;
import java.math.BigInteger;

public class Main {

    private Thread process;

    private static boolean isPrime(int num) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static ArrayList<Integer> getFactors(BigInteger num) {
        ArrayList<Integer> factors = new ArrayList<>();
        BigInteger iterations = new BigInteger("1");
        BigInteger increment = new BigInteger("1");

        while (num.compareTo(iterations) >= 0) {

            if (num.remainder(iterations).equals(0)) {
                factors.add(num.remainder(iterations).intValue());
                System.out.println(num.remainder(iterations).intValue());
            }

            iterations.add(increment);
        }

        return factors;
    }

    private static int getHighestPrime(ArrayList<Integer> factors) {
        int highestNum = -1;

        for (int num : factors) {
            if (isPrime(num) && num >= highestNum) {
                highestNum = num;
            }
        }

        return highestNum;
    }

    public static void main(String[] args) {
        BigInteger NUMBER = new BigInteger("600851475143");

        System.out.println(Arrays.toString(getFactors(NUMBER).toArray()));
        System.out.println(getHighestPrime(getFactors(NUMBER)));
    }
}
