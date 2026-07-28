class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        if len(pattern) != len(words):
            return False
        
        letter_to_word = {}
        word_set = set()
        
        for letter, word in zip(pattern, words):
            if letter in letter_to_word:
                if letter_to_word[letter] != word:
                    return False
            elif word in word_set:
                return False
            else:
                letter_to_word[letter] = word
                word_set.add(word)
                
        return True