class Solution {
public:
    /**
     * Convert a Roman numeral to an integer
     * @param romanNumeral The Roman numeral to convert
     * @return The integer value of the Roman numeral
     */
    int romanToInt(string romanNumeral)
    {
        // Create a map to store the values of the Roman numerals
        map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int prevValue = -1;

        // Iterate through the Roman numeral characters
        for (int i = 0; i < romanNumeral.size(); i++) {   
            int currentValue = values[romanNumeral.at(i)];
            if (prevValue == -1) {
                prevValue = currentValue;
                continue;
            }
            if (currentValue > prevValue) {
                // Subtract the previous value from the result if the current value is larger
                result += currentValue - prevValue;
                prevValue = -1;
            } else if (currentValue == prevValue) {
                prevValue += currentValue;
            } else {
                // Add the previous value to the result if the current value is smaller
                result += prevValue;
                prevValue = currentValue;
            }
        }

        // Check if there is a remaining value to add to the result
        return (prevValue != -1)? result + prevValue: result;
    }
};
