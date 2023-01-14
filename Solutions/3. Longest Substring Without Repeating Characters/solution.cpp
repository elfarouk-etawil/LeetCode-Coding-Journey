class Solution {
private:
    /**
     * Helper function to get the substring after a certain character.
     * This function is assuming that the character will always be in the string
     *
     * @param s The input string
     * @param c The character to search for
     * @return The substring after the first occurrence of the character
     */
    string subStrAfterChar(const string &s, const char &c) {
        int i = s.find_first_of(c) + 1; // find the index of the first occurrence of the character
        return s.substr(i); // return the substring starting from the index found above
    }
public:
    /**
     * Given a string, find the length of the longest substring without repeating characters.
     *
     * @param s The input string
     * @return The length of the longest substring without repeating characters
     */
    int lengthOfLongestSubstring(string s) {
        size_t longestSubStr = 0;
        string subStr;
        
        for (int i = 0; i < s.size(); i++) {
            if (subStr.find_first_of(s[i]) == string::npos) {
                subStr += s[i];
            }
            else {
                longestSubStr = max(subStr.size(), longestSubStr);
                subStr = subStrAfterChar(subStr, s[i]) + s[i];
            }
        }
        longestSubStr = max(subStr.size(), longestSubStr);
        return longestSubStr;
    }
};
