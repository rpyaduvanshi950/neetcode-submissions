class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # s1=sorted(s1)
        # l= len(s1)

        # for i in range(len(s2)):
        #     if len(s2)-i>=l:
        #         substr=s2[i:i+l]
        #     else:
        #         return False

        #     if sorted(substr)==s1:
        #         return True
        # return False
        n = len(s1)
        m = len(s2)

        if n > m:
            return False

        mp1 = [0] * 26
        mp2 = [0] * 26

        # Frequency of s1
        for i in range(n):
            mp1[ord(s1[i]) - ord('a')] += 1

        # Frequency of first window
        for i in range(n):
            mp2[ord(s2[i]) - ord('a')] += 1

        if mp1 == mp2:
            return True

        # Slide window
        for i in range(m - n):
            # Remove left character
            mp2[ord(s2[i]) - ord('a')] -= 1

            # Add new right character
            mp2[ord(s2[i + n]) - ord('a')] += 1

            if mp1 == mp2:
                return True

        return False


