# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        while current.next is not None:
            ins = gcd(current.val, current.next.val)
            node = ListNode(ins)
            node.next = current.next
            current.next = node

            current = node.next
        return head
            

    def gcd(self, a: int, b: int) -> int:
        while a != b:
            if a > b:
                a -= b
            else:
                b -= a
        return a
        