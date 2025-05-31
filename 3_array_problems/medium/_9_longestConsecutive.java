import java.util.HashSet;
import java.util.Set; // Use Set interface for flexibility
import java.util.Scanner;

class Solution {
  public int longestConsecutive(int[] nums) {
    // Handle the edge case of an empty array
    if (nums.length == 0) {
      return 0;
    }

    // Create a HashSet to store all unique numbers for efficient O(1) lookups
    Set<Integer> numSet = new HashSet<>();
    for (int num : nums) {
      numSet.add(num);
    }
    // Alternatively, using Java 8 Streams:
    // Set<Integer> numSet =
    // Arrays.stream(nums).boxed().collect(Collectors.toSet());

    int longestConsecutiveSequence = 0;

    // Iterate through each number in the set
    for (int num : numSet) {
      // Check if the current number is the start of a sequence.
      // A number `num` is the start of a sequence if `num - 1` is NOT present in the
      // set.
      if (!numSet.contains(num - 1)) {
        int currentNum = num;
        int currentSequenceLength = 1;

        // While the next consecutive number exists in the set, extend the sequence
        while (numSet.contains(currentNum + 1)) {
          currentNum += 1;
          currentSequenceLength += 1;
        }

        // Update the maximum longest sequence found so far
        longestConsecutiveSequence = Math.max(longestConsecutiveSequence, currentSequenceLength);
      }
    }

    return longestConsecutiveSequence;
  }
}

public class _9_longestConsecutive {
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
      int result = obj.longestConsecutive(nums);

      System.out.println(result);
      System.out.println("~"); // Separator for test cases
    }
    cin.close();
  }
}
