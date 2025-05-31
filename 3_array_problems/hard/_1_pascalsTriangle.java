
import java.util.*;

class Solution {
  public List<Integer> generateRows(int n) {
    List<Integer> row = new ArrayList<>();
    long num = 1;
    row.add((int) num);
    for (int i = 1; i < n; i++) {
      num = num * (n - i);
      num = num / i;
      row.add((int) num);
    }
    return row;
  }

  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> pascalTriangle = new ArrayList<>();
    for (int i = 1; i <= numRows; i++) {
      pascalTriangle.add(generateRows(i));
    }
    return pascalTriangle;

    // Approach 2: Dynamic Programming
    // List<List<Integer>> ans = new ArrayList<>();
    // for (int i = 0; i < numRows; i++) {
    // List<Integer> row = new ArrayList<>();
    // // Resize the current row
    // for (int k = 0; k <= i; k++) {
    // row.add(0); // Initialize with dummy values
    // }
    // row.set(0, 1); // First element is always 1
    // if (i > 0) { // Only set the last element for rows > 0
    // row.set(i, 1); // Last element is always 1
    // }
    // if (i >= 2) {
    // for (int j = 1; j < i; j++) {
    // // Current element is sum of two elements from the previous row
    // row.set(j, ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j));
    // }
    // }
    // ans.add(row);
    // }
    // return ans;

  }
}

public class _1_pascalsTriangle {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      int numRows = sc.nextInt();

      Solution obj = new Solution();
      List<List<Integer>> result = obj.generate(numRows);
      for (List<Integer> row : result) {
        for (int val : row) {
          System.out.print(val + " ");
        }
        System.out.println();
      }
      System.out.println("~");
    }
    sc.close();
  }
}
