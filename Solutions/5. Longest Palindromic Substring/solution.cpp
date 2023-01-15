class Solution {
public:
    string longestPalindrome(string s) {
        // get the length of the original string
        int n = s.length();
        // create a new string "t" with a special character "$" added at the      beginning and "#" added between each original character
        string t = "$#";
        for (int i = 0; i < n; ++i) {
            t += s[i];
            t += "#";
        }
        // add a null character at the end of the new string
        t += '\0';
        // get the length of the new string
        n = t.length();
        // initialize variables for tracking the palindrome
        int mx = 0, id = 0, maxLen = 0, start = 0;
        // create a vector "p" to keep track of the palindrome radius at each index "i" of the new string "t"
        vector<int> p(n, 0);
        // iterate through the new string "t"
        for (int i = 1; i < n; ++i) {
            // if the current index "i" is within the palindrome centered at "id"
            if (i < mx)
                // set the palindrome radius at index "i" to the minimum of the palindrome radius at "2*id - i" and the distance from "i" to the right boundary "mx"
                p[i] = min(p[(id << 1) - i], mx - i);
            else
                // if "i" is outside the palindrome centered at "id" set the radius at "i" to 1
                p[i] = 1;
            // expand the palindrome at index "i" as far as possible
            while (t[i + p[i]] == t[i - p[i]])
                ++p[i];
            // update the palindrome centered at "id" and its right boundary "mx" if necessary
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            // update the longest palindrome substring if necessary
            if (p[i] > maxLen) {
                maxLen = p[i];
                start = (i - maxLen) / 2;
            }
        }
        // return the longest palindrome substring of the original string "s"
        return s.substr(start, maxLen - 1);
    }
};
