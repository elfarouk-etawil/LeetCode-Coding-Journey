class Solution {
public:
    /**
     * Given an array of integers and a target value, find the indices of two elements 
     * that add up to the target value using a hash map.
     * 
     * @param nums The input array of integers
     * @param target The target value to add up to
     * @return A vector containing the indices of the two elements
     */
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if we have seen the complement value before
            if (seen.find(complement) != seen.end()) {
                return vector<int>{seen[complement], i};
            } else {
                // Add the current value to the hash map
                seen[nums[i]] = i;  
            } 
        }
        // Return an empty vector if no solution is found
        return vector<int>();
    }
};

/* ِِAnother solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums.at(i) + nums.at(j) == target) return vector<int>{i, j};
            }
        }
        return vector<int>();
    }
};
*/
