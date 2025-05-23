
import java.util.*;

class Solution {
  public ArrayList<Integer> sortedArray(int[] a, int[] b) {
    int n = a.length;
    int m = b.length;

    // Optimized Two-Pointer Approach (original C++ logic)
    ArrayList<Integer> unionArr = new ArrayList<>();
    int i = 0; // Pointer for array 'a'
    int j = 0; // Pointer for array 'b'

    while (i < n && j < m) {
      // Skip duplicates in 'a'
      if (i > 0 && a[i] == a[i - 1]) {
        i++;
        continue;
      }
      // Skip duplicates in 'b'
      if (j > 0 && b[j] == b[j - 1]) {
        j++;
        continue;
      }

      if (a[i] <= b[j]) {
        // Add if the union list is empty or the last element is different
        if (unionArr.isEmpty() || unionArr.get(unionArr.size() - 1) != a[i]) {
          unionArr.add(a[i]);
        }
        i++;
      } else { // a[i] > b[j]
        // Add if the union list is empty or the last element is different
        if (unionArr.isEmpty() || unionArr.get(unionArr.size() - 1) != b[j]) {
          unionArr.add(b[j]);
        }
        j++;
      }
    }

    // Add remaining elements of array 'a'
    while (i < n) {
      // Skip duplicates in 'a'
      if (i > 0 && a[i] == a[i - 1]) {
        i++;
        continue;
      }
      if (unionArr.isEmpty() || unionArr.get(unionArr.size() - 1) != a[i]) {
        unionArr.add(a[i]);
      }
      i++;
    }

    // Add remaining elements of array 'b'
    while (j < m) {
      // Skip duplicates in 'b'
      if (j > 0 && b[j] == b[j - 1]) {
        j++;
        continue;
      }
      if (unionArr.isEmpty() || unionArr.get(unionArr.size() - 1) != b[j]) {
        unionArr.add(b[j]);
      }
      j++;
    }

    return unionArr;
  }

  // --- Alternate Approach 1: Using HashSet (equivalent to C++ std::set) ---
  // Time Complexity: O(N log N + M log M) if arrays are unsorted, but O(N+M) on
  // average if adding to HashSet.
  // Space Complexity: O(N+M) in worst case (all unique elements).
  public ArrayList<Integer> sortedArrayUsingSet(int[] a, int[] b) {
    HashSet<Integer> set = new HashSet<>();
    for (int num : a) {
      set.add(num);
    }
    for (int num : b) {
      set.add(num);
    }
    ArrayList<Integer> ans = new ArrayList<>(set);
    Collections.sort(ans);
    return ans;
  }

  // --- Alternate Approach 2: Using HashMap (equivalent to C++ std::map) ---
  // Time Complexity: O(N log N + M log M) due to TreeMap, or O(N+M) on average
  // for HashMap + sorting.
  // Space Complexity: O(N+M) in worst case.
  public ArrayList<Integer> sortedArrayUsingMap(int[] a, int[] b) {
    // Using TreeMap to keep keys sorted automatically (like std::map in C++)
    TreeMap<Integer, Integer> tmpp = new TreeMap<>();
    for (int num : a) {
      tmpp.put(num, tmpp.getOrDefault(num, 0) + 1);
    }
    for (int num : b) {
      tmpp.put(num, tmpp.getOrDefault(num, 0) + 1);
    }
    ArrayList<Integer> ans = new ArrayList<>();
    for (Map.Entry<Integer, Integer> entry : tmpp.entrySet()) {
      ans.add(entry.getKey());
    }
    return ans;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt(); // Number of test cases
    while (t-- > 0) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      int[] a = new int[n];
      int[] b = new int[m];
      for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
      }
      for (int i = 0; i < m; i++) {
        b[i] = sc.nextInt();
      }

      Solution obj = new Solution();

      // Call the two-pointer approach (original C++ implementation)
      ArrayList<Integer> result = obj.sortedArray(a, b);

      // Uncomment the lines below to test alternate approaches:
      // ArrayList<Integer> result = obj.sortedArrayUsingSet(a, b);
      // ArrayList<Integer> result = obj.sortedArrayUsingMap(a, b);

      for (int num : result) {
        System.out.print(num + " ");
      }
      System.out.println();
    }
    sc.close();
  }
}
