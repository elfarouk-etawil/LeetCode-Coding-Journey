// Solution to the Zigzag Conversion problem
// This solution uses a vector of strings to store each row of the zigzag pattern. 
// We iterate through the input string and add each character to the appropriate row. 
// We also keep track of the current row and whether we are climbing up or down the zigzag pattern. 
// Finally, we concatenate all of the rows together to form our output string. 

class Solution {
public:
    string convert(string s, int numRows) {
        
        // If there is only one row, no need to convert. 
        if (numRows == 1) return s;

        // Initialize a vector of strings with numRows elements 
        vector<string> rows(numRows);

        // Decrement numRows since we will use it as an index in our loop below 
        numRows--;

        // Keep track of our current row and whether we are climbing up or down 
        int currentRow = 0; 
        bool isClimb = true;

        // Iterate through each character in our input string 
        for (const auto &c: s) {

            // Add this character to the appropriate row in our vector of strings  
            rows[currentRow] += c;

            // If we have reached either end of our zigzag pattern, switch directions  
            if (currentRow == numRows || currentRow == 0) { 
                isClimb = !isClimb;  
            }

            // Increment or decrement our current row depending on which direction we are going  
            if (isClimb) {
                currentRow--;
            } else { 
                currentRow++;  
            }   
        }

        // Concatenate all of the rows together into one output string
        string converted;
        for (const auto &row: rows)
            converted += row;    
        return converted;    
    } 
};
