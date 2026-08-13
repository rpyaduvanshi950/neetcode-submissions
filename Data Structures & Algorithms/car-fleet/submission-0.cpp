class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        vector <pair<int,double>> mp;
        for (int i =0;i<n;i++){
            double m = (double)(target-position[i])/speed[i];
            mp.push_back({position[i], m});
        }
        sort(mp.begin(), mp.end());
        int number=1;
        for (int i = n - 2; i >= 0; i--){
            if (mp[i].second > mp[i+1].second) number++;
            else mp[i].second = mp[i+1].second;
        }
        return number;
    }
};
