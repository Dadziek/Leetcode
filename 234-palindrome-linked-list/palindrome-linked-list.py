# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tab = []

        current = head
        while current is not None:
            tab.append(current.val)
            current = current.next

        i  = 0
        j = len(tab) - 1
        while i <= j:
            if tab[i] != tab[j]:
                return False
            i += 1
            j -= 1

        return True
    