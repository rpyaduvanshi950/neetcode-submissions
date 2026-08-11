class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1=sorted(s1)
        l= len(s1)

        for i in range(len(s2)):
            if len(s2)-i>=l:
                substr=s2[i:i+l]
            else:
                return False

            if sorted(substr)==s1:
                return True
        return False