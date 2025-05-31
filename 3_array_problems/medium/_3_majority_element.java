import java.util.*;

class Solution {
  public int majorityElementBetter(int[] nums) {
    int n = nums.length;
    HashMap<Integer, Integer> mpp = new HashMap<>();
    for (int num : nums) {
      mpp.put(num, mpp.getOrDefault(num, 0) + 1);
    }
    for (Map.Entry<Integer, Integer> entry : mpp.entrySet()) {
      if (entry.getValue() > n / 2) {
        return entry.getKey();
      }
    }
    return -1;
  }

  public int majorityElementBest(int[] nums) {
    int n = nums.length;
    int count = 0;
    int element = 0;
    for (int num : nums) {
      if (count == 0) {
        count = 1;
        element = num;
      } else if (element == num) {
        count += 1;
      } else {
        count -= 1;
      }
    }
    int freq = 0;
    for (int num : nums) {
      if (num == element) {
        freq += 1;
      }
    }
    if (freq > n / 2) {
      return element;
    }
    return -1;
  }
}

// 3
// 3
// 3 2 3
// 7
// 2 2 1 1 1 2 2
// 8
// 1 2 2 1 1 2 1 2

// 3
// ~
// 2
// ~
// -1
// ~

public class _3_majority_element {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int[] nums = new int[n];
      for (int i = 0; i < n; i++) {
        nums[i] = sc.nextInt();
      }
      Solution ob = new Solution();
      // System.out.println(ob.majorityElementBetter(nums));
      System.out.println(ob.majorityElementBest(nums));
      System.out.println("~");
    }
    sc.close();
  }
}
