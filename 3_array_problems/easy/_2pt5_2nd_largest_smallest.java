import java.util.*;

class Solution {
  public int[] getSecondOrderElements(ArrayList<Integer> arr) {
    int large = Integer.MIN_VALUE;
    int slarge = Integer.MIN_VALUE;
    int small = Integer.MAX_VALUE;
    int ssmall = Integer.MAX_VALUE;
    for (int i = 0; i < arr.size(); i++) {
      if (arr.get(i) > large) {
        slarge = large;
        large = arr.get(i);
      } else if (arr.get(i) > slarge && arr.get(i) != large) {
        slarge = arr.get(i);
      }
      if (arr.get(i) < small) {
        ssmall = small;
        small = arr.get(i);
      } else if (arr.get(i) < ssmall && arr.get(i) != small) {
        ssmall = arr.get(i);
      }
    }

    return new int[] { slarge, ssmall };
  }
}

public class _2pt5_2nd_largest_smallest {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    sc.nextLine();
    while (t-- > 0) {
      int n = sc.nextInt();
      ArrayList<Integer> input = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        input.add(sc.nextInt());
      }
      Solution ob = new Solution();
      int result[] = ob.getSecondOrderElements(input);
      System.out.println(result[0] + " " + result[1]);
      System.out.println("~");
    }
    sc.close();
  }
}
