class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();

        for(int i = 0; i < words.length; ++i) {
            for(int j = 0; j < words.length; ++j) {
                if (i == j || words[i].length() > words[j].length()) continue;
                if(kmpSearch(words[j], words[i])) {
                    ans.add(words[i]);
                    break;
                }
            }
        }
        return ans;
    }

    private boolean kmpSearch(String srcWord, String searchWord) {
        int srcLength = srcWord.length();
        int searchLength = searchWord.length();
        int[] searchWordPi = getPartialMatch(searchWord);
        char[] srcWordArr = srcWord.toCharArray();
        char[] searchWordArr = searchWord.toCharArray();

        int begin = 0;
        int matched = 0;

        while(begin <= srcLength - searchLength) {
            if(matched < searchLength && srcWordArr[begin + matched] == searchWordArr[matched]) {
                ++matched;
                if (matched == searchLength)
                    return true;
            } else {
                if (matched == 0) {
                    ++begin;
                    continue;
                }
                begin += matched - searchWordPi[matched - 1];
                matched = searchWordPi[matched - 1];
            }
        }
        return false;
    }

    private int[] getPartialMatch(String word) {
        int len = word.length();
        int[] Pi = new int[len];
        char[] wordArr = word.toCharArray();

        int begin = 1;
        int matched = 0;
        while(begin + matched < len) {
            if(wordArr[begin + matched] == wordArr[begin]) {
                Pi[begin + matched] = ++matched;
            } else {
                if(matched == 0) {
                    ++begin;
                    continue;
                }
                begin += matched - Pi[matched - 1];
                matched = Pi[matched - 1];
            }
        }
        return Pi;
    }
}