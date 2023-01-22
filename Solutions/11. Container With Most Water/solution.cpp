// Use two pointers to traverse the array from both ends.
// Calculate the area of each pair and update the maximum area if necessary.
// Move the pointer with the smaller height towards the other end.
// Repeat until both pointers meet.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmount = 0, left = 0, right = height.size() - 1;

        while (left < right) {
            maxAmount = max(maxAmount, (right-left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            } 
        }

        return maxAmount; 
    } 
};
