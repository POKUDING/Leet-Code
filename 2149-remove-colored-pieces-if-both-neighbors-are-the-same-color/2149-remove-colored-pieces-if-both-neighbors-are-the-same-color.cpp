class Solution {
public:
    bool winnerOfGame(string colors) {
        ios::sync_with_stdio(0);
        cin.tie(0);
       int size = colors.size();
       int cnt = 0;
       int a = 0;
       int b = 0;
       for(int i = 0; i < size; ++i)
       {
            if (colors[i] != 'A')
                cnt = 0;
            else if (++cnt >= 3)
                ++a;
       }
       cnt = 0;
       for(int i = 0; i < size; ++i)
       {
            if (colors[i] != 'B')
                cnt = 0;
            else if (++cnt >= 3)
                ++b;
       }
        if (a <= b)
            return false;
        return true;
    }
};