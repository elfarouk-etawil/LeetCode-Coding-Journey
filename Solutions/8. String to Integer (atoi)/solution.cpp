class Solution {
public:
    int myAtoi(string s) {
        vector<short> nums;
        nums.reserve(s.size());

        s.erase(s.begin(), 
        find_if(s.begin(), s.end(), [](int ch) {return !isspace(ch);}));

        bool isNegative = (s.front() == '-')? true: false;
        if (s.front() == '-'|| s.front() == '+') s.erase(s.begin());

        for (const auto &c: s) {
            if (isdigit(c))
                nums.push_back(c-'0');
            else
                break;
        }

        int leftZeros = 0;
        for (const auto &n: nums) {
            if (n == 0) leftZeros++;
            else break;
        }

        if (nums.size() - leftZeros > 10)
            return (isNegative)? INT_MIN : INT_MAX;

        long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums.at(i) * pow(10, nums.size() -i -1);
        }
        
        if (isNegative) total *= -1;
        
        if (total < INT_MIN)
            return INT_MIN;
        else if (total > INT_MAX)
            return INT_MAX;
        else
            return total;
    }
};
