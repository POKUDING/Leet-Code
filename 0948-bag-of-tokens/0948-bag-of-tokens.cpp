const static auto _ = [](){cin.tie(0); cout.tioe(0); ios::sync_with_stdio(0); return nullptr;}();
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