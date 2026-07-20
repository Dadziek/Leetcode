class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0

        current_level = {beginWord}
        steps = 1
        
        while current_level:
            if endWord in current_level:
                return steps
            
            next_level = set()
            for current_word in current_level:

                for word in list(words): 
                    if self.how_many_changes(current_word, word) == 1:
                        next_level.add(word)
                        words.remove(word)

            current_level = next_level
            steps += 1
            
        return 0

        
    def how_many_changes(self, word1: str, word2: str):
        counter = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                counter += 1
        return counter
