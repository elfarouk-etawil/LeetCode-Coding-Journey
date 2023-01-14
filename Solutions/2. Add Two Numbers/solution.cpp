class Solution {
public:
    /**
     * Given two non-empty linked lists representing two non-negative integers, 
     * add the two numbers and return the sum as a linked list.
     *
     * @param l1 The first linked list representing a non-negative integer
     * @param l2 The second linked list representing a non-negative integer
     * @return The linked list representing the sum of the two input integers
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // Initialize the result linked list
        ListNode *result = new ListNode();
        ListNode *cursor = result;
        // Initialize the carry-over value
        int carryOver = 0;
        // Iterate through both linked lists until we reach the end of one of them
        while (l1 != nullptr || l2 != nullptr) {
            // Get the values of the current nodes in each linked list
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            // Calculate the sum of the current nodes and the carry-over value
            int sum = x + y + carryOver;
            // Update the carry-over value for the next iteration
            carryOver = sum / 10;
            // Create a new node in the result linked list with the ones digit of the sum
            cursor->next = new ListNode(sum % 10);
            // Move the cursor to the new node
            cursor = cursor->next;
            // Move to the next node in each linked list if it exists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        // If there is a remaining carry-over value, create a new node for it in the result linked list
        if (carryOver) cursor->next = new ListNode(carryOver);
        // Return the result linked list, starting from the first node
        return result->next;
    }
};
