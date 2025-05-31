import java.util.*;

class Solution {
  public void nextPermutation(int[] nums) {
    int n = nums.length;
    int idx = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      reverse(nums, 0, n - 1);
      return;
    }
    for (int i = n - 1; i > idx; i--) {
      if (nums[i] > nums[idx]) {
        swap(nums, i, idx);
        break;
      }
    }
    reverse(nums, idx + 1, n - 1);
  }

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  private void reverse(int[] nums, int start, int end) {
    while (start < end) {
      swap(nums, start, end);
      start++;
      end--;
    }
  }
}

// 3
// 3
// 1 2 3
// 3
// 3 2 1
// 4
// 1 3 2 4

// 1 3 2
// ~
// 1 2 3
// ~
// 1 3 4 2
// ~

public class _7_nextPermutation {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt(); // Number of test cases
    while (t-- > 0) {
      int n = cin.nextInt();
      int[] nums = new int[n];
      for (int i = 0; i < n; i++) {
        nums[i] = cin.nextInt();
      }

      Solution obj = new Solution();
      obj.nextPermutation(nums);

      for (int i = 0; i < n; i++) {
        System.out.print(nums[i] + (i == n - 1 ? "" : " "));
      }
      System.out.println();
      System.out.println("~");
    }
    cin.close();
  }
}
