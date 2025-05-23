import java.util.*;

class Solution {
  public void rotate(ArrayList<Integer> nums, int k) {
    int n = nums.size();
    k = k % n;
    Collections.reverse(nums.subList(0, n - k));
    Collections.reverse(nums.subList(n - k, n));
    Collections.reverse(nums);
  }
}

class _6_right_rotate_arr_by_k {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int n = sc.nextInt();
      int k = sc.nextInt();
      ArrayList<Integer> nums = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        nums.add(sc.nextInt());
      }

      Solution obj = new Solution();
      obj.rotate(nums, k);

      for (int num : nums) {
        System.out.print(num + " ");
      }
      System.out.println();
    }
    sc.close();
  }
}
