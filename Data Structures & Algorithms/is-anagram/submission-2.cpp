class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char,int> mpp;
        int n =s.size();
        if (s.size()!=t.size()) return false;

        for (int i =0;i<n;i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }

        for (int i =0;i<mpp.size();i++){
            if (mpp[i]!=0) return false;
        }

        return true;
    }
};
