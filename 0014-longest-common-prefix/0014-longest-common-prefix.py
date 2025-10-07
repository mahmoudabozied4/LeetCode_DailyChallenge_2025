class Solution:
    def longestCommonPrefix(self, list_of_strings: list[str]) -> str:
        if not list_of_strings:
            return ""

        prefix = list_of_strings[0]

        for current_index in range(1, len(list_of_strings)):
            curWord = list_of_strings[current_index]

            while not curWord.startswith(prefix):
                prefix = prefix[:-1]

                if not prefix:
                    return ""

        return prefix
