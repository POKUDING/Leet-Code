class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int max = 0;
        int[] charCount = new int[26];
        for(int i = 0; i < letters.length; ++i)
            ++charCount[letters[i] - 'a'];
        // System.out.println(charMap.toString());
        return dfs(words,0,charCount, score);
    }

    public int dfs(String[] words,int idx, int[] charCount, int[] score) {
        int rtn1 = 0;
        int rtn2 = 0;

        if(idx == words.length)
            return 0;
        int[] charCountBackUp = new int[26];
        for(int i = 0; i < 26; ++i)
            charCountBackUp[i] = charCount[i];
        rtn1 = checkScore(words[idx], charCount, score);
        if(rtn1 != -1)
            rtn1 += dfs(words, idx + 1, charCount, score);
        rtn2 = dfs(words, idx + 1, charCountBackUp, score);
        return Math.max(rtn1, rtn2);
    }

    public int checkScore(String word, int[] charCount,int[] score) {
        int rtn = 0;
        for(int i = 0; i < word.length(); ++i) {
            if(charCount[word.charAt(i) - 'a'] == 0)
                return -1;
            --charCount[word.charAt(i) - 'a'];
            rtn += score[word.charAt(i) - 'a'];
        }
        // System.out.println(word + " " + rtn);
        return rtn;
    }
}