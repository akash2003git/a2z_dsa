import java.util.*;

class Solution {
  public void moveZeroes(int[] nums) {
    int n = nums.length;

    int j = -1;
    // Find the index of the first zero
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        j = i;
        break;
      }
    }

    // If no zeros are found, the array is already in the desired state
    if (j == -1) {
      return;
    }

    // Iterate from the element after the first zero
    // If a non-zero element is found, swap it with the element at index j
    // and increment j to point to the next potential zero position.
    for (int i = j + 1; i < n; i++) {
      if (nums[i] != 0) {
        // Swap nums[i] and nums[j]
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        j++; // Move j to the next zero position
      }
    }
  }
}

class _7_move_zeroes {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt(); // Number of test cases
    while (t-- > 0) {
      int n = sc.nextInt();
      int[] nums = new int[n];
      for (int i = 0; i < n; i++) {
        nums[i] = sc.nextInt();
      }

      Solution obj = new Solution();
      obj.moveZeroes(nums);

      for (int num : nums) {
        System.out.print(num + " ");
      }
      System.out.println();
    }
    sc.close();
  }
}
