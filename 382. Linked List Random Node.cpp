#include <ctime>
#include <cstdlib>
class Solution {
private:
    ListNode* head;
    int length;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->length = 0;
        this->head = head;
        srand(time(NULL));
        
        ListNode *tmp = head;
        while (tmp) {
            this->length++;
            tmp = tmp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * result = this->head;
        
        int nodePos = rand() % this->length;
        for(int i = 0; i < nodePos; i++) result = result->next; 
        return result->val;
    }
};