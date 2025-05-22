import java.util.*;

class Solution {
  public int largest(ArrayList<Integer> arr) {
    int largest = arr.get(0);
    for (int i = 0; i < arr.size(); i++) {
      if (arr.get(i) > largest) {
        largest = arr.get(i);
      }
    }
    return largest;
    // Collections.sort(arr);
    // return arr.get(arr.size() - 1);
  }
}

public class _1_largest_element_in_arr {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    sc.nextLine();
    while (t-- > 0) {
      String inputString = sc.nextLine();
      ArrayList<Integer> input = new ArrayList<>();
      Scanner ss = new Scanner(inputString);
      while (ss.hasNextInt()) {
        int num = ss.nextInt();
        input.add(num);
      }
      Solution ob = new Solution();
      System.out.println(ob.largest(input));
      System.out.println("~");
      ss.close();
    }
    sc.close();
  }
}
