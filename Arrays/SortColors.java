public class SortColors {
    public static void main(String[] args) {
        SortColors sortColors = new SortColors();

        int[] nums = {2, 0, 2, 1, 1, 0};
        System.out.println("Before sorting:");
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();

        sortColors.sortColors(nums);

        System.out.println("After sorting:");
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public void sortColors(int[] nums) {
        int n = nums.length;
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        // Count the number of 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else if (nums[i] == 1) {
                ones++;
            } else {
                twos++;
            }
        }

        int i = 0;

        // Place 0s in the array
        while (zeros > 0) {
            nums[i++] = 0;
            zeros--;
        }

        // Place 1s in the array
        while (ones > 0) {
            nums[i++] = 1;
            ones--;
        }

        // Place 2s in the array
        while (twos > 0) {
            nums[i++] = 2;
            twos--;
        }
    }
}
