class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        finish = []
        for i in order:
            if i in friends:
                finish.append(i)
        return finish