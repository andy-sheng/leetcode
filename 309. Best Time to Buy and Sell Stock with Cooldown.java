public class Solution {
    public int maxProfit(int[] prices) {
        int sell = 0, prevSell = 0, prevPrevSell = 0, buy = 0, prevBuy = Integer.MIN_VALUE;
        for (int price: prices) {
            buy = Math.max(prevPrevSell - price, prevBuy);
            sell = Math.max(prevBuy + price, prevSell);
            prevBuy = buy;
            prevPrevSell = prevSell;
            prevSell = sell;
        }
        return sell;
    }
}
