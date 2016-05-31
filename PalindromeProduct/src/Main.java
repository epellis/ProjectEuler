public class Main {
    private static boolean isPalindrome(int number) {
        String num =Integer.toString(number);

        if (num.length() == 1) {
            return true;
        }

        if (num.length() == 2 && (num.charAt(0) == num.charAt(1))) {
            return true;
        }

        for (int i = 0; i < findMiddleIndex(num); i++) {
            if (num.charAt(i) != num.charAt(num.length() - i - 1)) {
                return false;
            }
        }

        return true;
    }

    private static int findMiddleIndex(String num) {
        return num.length() / 2;
    }

    private static int palindromeProduct(int max) {
        int maxProduct = -1;

        for (int i = 0; i <= max; i++) {
            for (int j = 0; j <= max; j++) {
                if (isPalindrome(i * j) && (i * j) >= maxProduct) {
                    maxProduct = i * j;
                }
            }
        }

        return maxProduct;
    }

    public static void main(String[] args) {
        final int MAXNUM = 999;

        System.out.println("The largest palindrome of " + MAXNUM + " is: " + palindromeProduct(MAXNUM));
    }
}
