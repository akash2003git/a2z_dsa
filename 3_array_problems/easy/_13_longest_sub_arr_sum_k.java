import java.util.*;

class Solution {
  // BRUTE
  public int longestSubArrWithSumKBrute(ArrayList<Integer> nums, long k) {
    int n = nums.size();
    int longestLength = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums.get(j);
        if (sum == k) {
          longestLength = Math.max(longestLength, j - i + 1);
        }
      }
    }
    return longestLength;
  }

  // BETTER
  public int longestSubArrWithSumKBetter(ArrayList<Integer> nums, long k) {
    int n = nums.size();
    int longestLength = 0;
    HashMap<Long, Integer> preSumHash = new HashMap<>();
    long preSum = 0;
    for (int i = 0; i < n; i++) {
      preSum += nums.get(i);
      if (preSum == k) {
        longestLength = Math.max(longestLength, i + 1);
      }
      long rem = preSum - k;
      if (preSumHash.containsKey(rem)) {
        longestLength = Math.max(longestLength, i - preSumHash.get(rem));
      }
      if (!preSumHash.containsKey((long) preSum)) {
        preSumHash.put((long) preSum, i);
      }
    }
    return longestLength;
  }

  // BEST
  public int longestSubArrWithSumKBest(ArrayList<Integer> nums, long k) {
    int n = nums.size();
    int longestLength = 0;
    long sum = 0;
    int left = 0, right = 0;
    while (right < n) {
      while (left <= right && sum > k) {
        sum -= nums.get(left);
        left++;
      }
      if (sum == k) {
        longestLength = Math.max(longestLength, nums.get(right) - nums.get(left) + 1);
      }
      right += 1;
      if (right < n) {
        sum += nums.get(right);
      }
    }

    return longestLength;
  }

}

public class _13_longest_sub_arr_sum_k {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      long k = sc.nextLong();
      ArrayList<Integer> input = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        input.add(sc.nextInt());
      }
      Solution ob = new Solution();
      // System.out.println(ob.longestSubArrWithSumKBrute(input, k));
      // System.out.println(ob.longestSubArrWithSumKBetter(input, k));
      System.out.println(ob.longestSubArrWithSumKBest(input, k));
      System.out.println("~");
    }
    sc.close();
  }
}
