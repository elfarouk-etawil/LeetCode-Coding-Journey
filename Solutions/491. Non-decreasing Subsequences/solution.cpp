/*
This solution uses a recursive approach to find all non-decreasing subsequences in an array of integers. 
The function findSequences takes in the array of integers, the starting index, a vector to store the current subsequence, and a vector of vectors to store all possible subsequences. 
The base case is when the size of the current subsequence is greater than or equal to 2, in which case it is added to the vector of vectors. 
An unordered set is used to keep track of which elements have been used in the current subsequence. 
For each element starting from the given start index, if it is greater than or equal to the last element in the current subsequence and has not been used yet, it is added to the current subsequence and findSequences is called recursively with an incremented start index. 
After returning from each recursive call, the last element is removed from the current subsequence before continuing on with other elements. 
Finally, after all recursive calls are complete, all possible non-decreasing subsequences are returned.
*/
class Solution {
    void findSequences(vector<int>& nums, int start, vector<int>& subSeq, vector<vector<int>>& possibilities) {
        if (subSeq.size() >= 2) possibilities.push_back(subSeq);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
          if ((subSeq.empty() || nums[i] >= subSeq.back()) && used.count(nums[i]) == 0) {
              used.insert(nums[i]);
              subSeq.push_back(nums[i]);
              findSequences(nums, i + 1, subSeq, possibilities);
              subSeq.pop_back();
          }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> possibilities;
        vector<int> subSeq;
        findSequences(nums, 0, subSeq, possibilities);
        return possibilities;
    }
};
