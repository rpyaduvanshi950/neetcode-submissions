class Solution {
public:
    int timer(vector<int>& piles, int x){
        int ans=0;
        for (int i =0;i<piles.size();i++){
            if (piles[i]%x!=0){
                ans+= piles[i]/x + 1;
            }else{
                ans+= piles[i]/x;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1, high=0;
        for (int i =0;i<piles.size();i++){
            high = max(high, piles[i]);
        }
        while (low <=high){
            int mid = (low+high)/2;
            int check = timer(piles, mid);
            if (check > h) low=mid+1;
            else high = mid-1;
        }
        return low;
    }
};
