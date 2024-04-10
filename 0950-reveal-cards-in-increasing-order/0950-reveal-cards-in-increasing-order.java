class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int[] rtn = new int[deck.length];
        Queue<Integer> que = new LinkedList<>();
        int idx = 0;
    
        Arrays.sort(deck);
        for(int i = 0; i < deck.length; ++i)
            que.add(i);
        while(!que.isEmpty()) {
            rtn[que.poll()] = deck[idx++];
            if(!que.isEmpty())
                que.add(que.poll());
        }
        return rtn;
    }
}