class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int leftPeople = tickets.length;
        int time = 0;
        for(int i = 0; i < tickets.length; ++i) {
            if(map.containsKey(tickets[i]))
                map.put(tickets[i],map.get(tickets[i]) + 1);
            else
                map.put(tickets[i], 1);
        }
        for(int i = 0; i < tickets[k]; ++i) {
            leftPeople -= map.get(i) == null ? 0 : map.get(i);
            time += leftPeople;
        }
        for(int i = k + 1; i <tickets.length; ++i)
            if(tickets[i] >= tickets[k])
                --time;
        return time;
    }
}