#include <iostream> // Required for input/output operations like cout, cin
#include <string>   // Required for std::string

int main() {
  // 1. Declaration and Initialization
  std::string s1; // Default initialization (empty string)
  std::string s2 =
      "Hello, C++!"; // Initialization with a C-style string literal
  std::string s3("Another way to initialize"); // Direct initialization
  std::string s4(s2);     // Copy initialization from another std::string
  std::string s5(5, 'x'); // Initializes with 5 'x' characters ("xxxxx")

  std::cout << "1. Declarations and Initializations:" << std::endl;
  std::cout << "s1: \"" << s1 << "\"" << std::endl;
  std::cout << "s2: \"" << s2 << "\"" << std::endl;
  std::cout << "s3: \"" << s3 << "\"" << std::endl;
  std::cout << "s4: \"" << s4 << "\"" << std::endl;
  // std::cout << "s5: \"" << s5 << "\"" << std::cout << std::endl;

  // 2. Concatenation
  std::string firstName = "John";
  std::string lastName = "Doe";
  std::string fullName = firstName + " " + lastName; // Using + operator
  std::cout << "2. Concatenation:" << std::endl;
  std::cout << "Full Name: " << fullName << std::endl;

  std::string greeting = "Welcome";
  greeting += "!"; // Using += operator
  std::cout << "Modified greeting: " << greeting << std::endl << std::endl;

  // 3. Length and Size
  std::cout << "3. Length and Size:" << std::endl;
  std::cout << "Length of s2: " << s2.length()
            << std::endl; // Returns the number of characters
  std::cout << "Size of s2: " << s2.size() << std::endl; // Alias for length()
  std::cout << "Is s1 empty? " << (s1.empty() ? "Yes" : "No") << std::endl
            << std::endl;

  // 4. Accessing Characters
  std::cout << "4. Accessing Characters:" << std::endl;
  std::cout << "First character of s2: " << s2[0] << std::endl;
  std::cout << "Fifth character of s2: " << s2.at(4)
            << std::endl; // Bounds checking
  // s2[100] would compile but might crash; s2.at(100) would throw an exception.
  std::cout << std::endl;

  // 5. Comparison
  std::string strA = "apple";
  std::string strB = "banana";
  std::string strC = "apple";

  std::cout << "5. Comparison:" << std::endl;
  std::cout << "strA == strC: " << (strA == strC ? "True" : "False")
            << std::endl;
  std::cout << "strA < strB: " << (strA < strB ? "True" : "False")
            << std::endl; // Lexicographical comparison
  std::cout << "strA != strB: " << (strA != strB ? "True" : "False")
            << std::endl
            << std::endl;

  // 6. Substrings
  std::string sentence = "The quick brown fox jumps over the lazy dog.";
  std::cout << "6. Substrings:" << std::endl;
  // substr(position, length)
  std::string word1 =
      sentence.substr(4, 5); // "quick" (starts at index 4, length 5)
  std::string word2 = sentence.substr(10, 5); // "brown"
  std::string restOfSentence =
      sentence.substr(16); // "fox jumps over the lazy dog." (to end)
  std::cout << "Word 1: " << word1 << std::endl;
  std::cout << "Word 2: " << word2 << std::endl;
  std::cout << "Rest: " << restOfSentence << std::endl << std::endl;

  // 7. Searching
  std::cout << "7. Searching:" << std::endl;
  size_t pos = sentence.find(
      "fox"); // Returns the starting index of the first occurrence
  if (pos != std::string::npos) { // std::string::npos indicates "not found"
    std::cout << "'fox' found at position: " << pos << std::endl;
  } else {
    std::cout << "'fox' not found." << std::endl;
  }

  size_t pos2 = sentence.find("cat");
  if (pos2 == std::string::npos) {
    std::cout << "'cat' not found." << std::endl;
  }
  std::cout << std::endl;

  // 8. Insertion and Erasure
  std::string text = "Hello World!";
  std::cout << "8. Insertion and Erasure:" << std::endl;
  std::cout << "Original text: " << text << std::endl;

  text.insert(6, "Beautiful "); // Insert "Beautiful " at index 6
  std::cout << "After insertion: " << text
            << std::endl; // "Hello Beautiful World!"

  text.erase(6, 10); // Erase 10 characters starting from index 6 ("Beautiful ")
  std::cout << "After erasure: " << text << std::endl
            << std::endl; // "Hello World!"

  // 9. Input with std::getline
  std::cout << "9. Input with std::getline:" << std::endl;
  std::string line;
  std::cout << "Enter a line of text (can include spaces): ";
  // Use std::getline to read an entire line including spaces
  // cin.ignore() is often used before getline if there's a leftover newline
  // from a previous cin >>
  std::cin.ignore(); // Consume any leftover newline character from previous
                     // input if any
  std::getline(std::cin, line);
  std::cout << "You entered: \"" << line << "\"" << std::endl << std::endl;

  // 10. Converting std::string to C-style string (char*)
  std::cout << "10. Converting to C-style string:" << std::endl;
  const char *c_str_ptr =
      s2.c_str(); // Returns a const pointer to a null-terminated C-style string
  std::cout << "C-style string of s2: " << c_str_ptr << std::endl;

  // Be careful when using data() for non-const string and modifying it,
  // or when the string object goes out of scope, the pointer becomes invalid.
  char *modifiable_c_str = s2.data(); // For C++11 onwards, can return non-const
                                      // char* for non-const string
  // std::cout << "Modifiable C-style string of s2: " << modifiable_c_str <<
  // std::endl; Don't modify the data returned by data() or c_str() unless you
  // know what you're doing, as it might invalidate the string's internal state.

  return 0;
}
