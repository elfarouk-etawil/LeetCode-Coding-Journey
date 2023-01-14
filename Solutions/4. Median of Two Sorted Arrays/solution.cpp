class Solution {
public:
    /** 
     * Finds the median of two sorted arrays. 
     * @param nums1 The first array of integers. 
     * @param nums2 The second array of integers. 
     * @return The median value of the combined arrays. 
     */ 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 

        // Get the size of each array. 
        size_t n = nums1.size(); 
        size_t m = nums2.size();

        // Create a new vector to store the merged arrays.  
        vector<int> merged;
        merged.reserve(m+n);

        // Merge both arrays into one vector using std::merge().  
        std::merge(nums1.begin(), nums1.end(),  
            nums2.begin(), nums2.end(),  
            back_inserter(merged));

        // Check if the total number of elements is odd or even and return accordingly.  
        if ((n + m) % 2) {  
            return (double)merged[(n + m) / 2];  
        } else {  
            int mid = (m + n) / 2;  
            return double(merged[mid-1] + merged[mid]) / 2;  
        }  

    }  // end findMedianSortedArrays()                    
};
