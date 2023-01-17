class Solution {
public:
   /**
   * Solution to the Reverse Integer problem on LeetCode.
   * 
   * @param x The integer to reverse.
   * @return The reversed integer, or 0 if the reversed integer is out of range.
   */
  int reverse(int x) {
      // Convert the integer to a string.
      string s = to_string(x);

      // Reverse the string.
      std::reverse(s.begin(), s.end());

      try {
          // Return the reversed integer, or if it's negative, multiply by -1.
          return (x < 0) ? stoi(s) * -1 : stoi(s);

      } catch (out_of_range &ex) {   // If the reversed integer is out of range, return 0. 
          return 0; 
      } 
  }
};
