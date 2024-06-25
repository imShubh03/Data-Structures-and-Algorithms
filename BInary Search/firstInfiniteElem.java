import java.util.Scanner;


class firstInfiniteElem {
    public int findFirstInfinite(int[] arr) {
        int low = 0;
        int high = 1;
        int maxVal = Integer.MAX_VALUE;

        // Double the high index until finding an infinite or very large element
        while (high < arr.length && arr[high] < maxVal) {
            low = high;
            high *= 2;
        }

        // Perform binary search to find the first infinite element
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] < maxVal) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low; // Return the index of the first infinite element
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Example array with some integers followed by infinite elements
        int[] arr = {2, 3, 5, 8, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE};

        firstInfiniteElem sol = new firstInfiniteElem();
        int result = sol.findFirstInfinite(arr);

        if (result < arr.length) {
            System.out.println("Index of first infinite element: " + result);
        } else {
            System.out.println("No infinite element found.");
        }

        scanner.close();
    }
}
