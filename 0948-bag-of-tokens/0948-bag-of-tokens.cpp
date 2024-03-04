class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int s = 0;
        int e = tokens.size() - 1;
        int score = 0;
        int maxscore = 0;
        while(s <= e) {
            if(power >= tokens[s]) {
                power -= tokens[s++];
                ++score;
                maxscore = max(maxscore, score);
            } else if (score > 0) {
                power += tokens[e--];
                --score;
            } else
                break;
        }
        return maxscore;
    }
};