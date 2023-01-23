class Solution {
public: 
    int findJudge(int n, vector<vector<int>>& trust) { 

        // If there is only one person, then that person is the judge. 
        if (n == 1) return n;

        // Create an array to store the trust count for each person. 
        vector<int> trust_count(n+1);

        // Iterate through all the trust relationships and update the trust count accordingly. 
        for (int i = 0; i < trust.size(); i++) { 
            trust_count[trust[i][0]]--; // Decrement the count for the trusting person  
            trust_count[trust[i][1]]++; // Increment the count for the trusted person  
        }

        // Iterate through all people and check if anyone has a trust count of n-1 (everyone trusts them except themselves).  
        for (int i = 0; i < trust_count.size(); i++) {  
            if (trust_count[i] == n - 1) return i;  
        }

        // If no one has a trust count of n-1, then there is no judge. 
        return -1;  

    }  
};
