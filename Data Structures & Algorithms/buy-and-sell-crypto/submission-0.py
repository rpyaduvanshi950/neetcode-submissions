# class Solution:
#     def maxProfit(self, prices: List[int]) -> int:
#         l, r= 0, 1
#         maxp=0

#         while r<len(prices):
#             if prices[l]<prices[r]:
#                 profit = prices[r]-prices[l]
#                 maxp=max(profit, maxp)
#             else:
#                 l=r
#             r+=1
#         return maxp

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        minBuy = prices[0]

        for sell in prices:
            maxP = max(maxP, sell - minBuy)
            minBuy = min(minBuy, sell)
        return maxP