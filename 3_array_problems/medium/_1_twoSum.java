import java.util.*;

class Solution {
  public ArrayList<Integer> twoSum(ArrayList<Integer> nums, int k) {
    int n = nums.size();
    HashMap<Integer, Integer> mpp = new HashMap<>();
    for (int i = 0; i < n; i++) {
      int rem = k - nums.get(i);
      if (mpp.containsKey(rem)) {
        ArrayList<Integer> ans = new ArrayList<>(Arrays.asList(mpp.get(rem), i));
        return ans;
      }
      mpp.put(nums.get(i), i);
    }
    return new ArrayList<>();
  }
}

// 3
// 4 9
// 2 7 11 15
// 3 6
// 3 2 4
// 2 6
// 3 3

// [0, 1]
// ~
// [1, 2]
// ~
// [0, 1]
// ~

public class _1_twoSum {
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
      Solution ob = new Solution();
      System.out.println(ob.twoSum(nums, k));
      System.out.println("~");
    }
    sc.close();
  }
}
