/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        int minDist = INT_MAX;
        int firstCp = -1;
        int prevCp = -1;
        
        int idx = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            ListNode* nxt = curr->next;
            
            bool isMaxima = (curr->val > prev->val) && (curr->val > nxt->val);
            bool isMinima = (curr->val < prev->val) && (curr->val < nxt->val);
            
            if (isMaxima || isMinima) {
                if (firstCp == -1) {
                    firstCp = idx;
                } else {
                    minDist = min(minDist, idx - prevCp);
                }
                prevCp = idx;
            }
            
            prev = curr;
            curr = nxt;
            idx++;
        }
        
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        
        int maxDist = prevCp - firstCp;
        return {minDist, maxDist};
    }
};