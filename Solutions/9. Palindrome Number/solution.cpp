class Solution {
public:
    bool isPalindrome(int x) {
        string s(to_string(x));
        return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
    }
};
