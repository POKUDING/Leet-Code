class Solution {
    public int minimumDeletions(String word, int k) {
        int[] cnt = new int[26];
        List<Integer> freq = new ArrayList();
        int rtn = Integer.MAX_VALUE;

        for(char c : word.toCharArray())
            ++cnt[c - 'a'];

        for(int i = 0; i < 26; ++i)
            if(cnt[i] > 0)
                freq.add(cnt[i]);

        Collections.sort(freq);

        int lessCnt = 0;

        for (int i = 0; i < freq.size(); ++i) {
            int curr = freq.get(i);
            int currDelete = 0;

            for(int j = i; j < freq.size(); ++j)
                if(freq.get(j) - curr > k)
                    currDelete += freq.get(j) - (curr + k);

            rtn = Math.min(rtn, lessCnt + currDelete);
            lessCnt += curr;
        }

        return rtn;
    }
}