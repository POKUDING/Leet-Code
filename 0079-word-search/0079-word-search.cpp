class Solution {
public:

    bool found_next_char(vector<vector<char> >& board, string& word, int x, int y, int index)
    {
		char	tmp = board[y][x];
		++index;
        if (index == word.size())
            return true;
		board[y][x] = 0;
		if (index == 2)
			;
        if (y - 1 >= 0 && board[y - 1][x] == word[index] && found_next_char(board, word, x, y - 1, index))
            return true;
        else if (x + 1 < board[y].size() && board[y][x + 1] == word[index] && found_next_char(board, word, x + 1, y, index))
            return true;
        else if (y + 1 < board.size() && board[y + 1][x] == word[index] && found_next_char(board, word, x, y + 1, index))
            return true;
        else if (x - 1 >= 0 && board[y][x - 1] == word[index] && found_next_char(board, word, x - 1, y, index))
            return true;
		board[y][x] = tmp;
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int index = 0;

        for (int i = 0, m = board.size(); i < m; ++i)
        {
            for(int j = 0, n = board[0].size(); j < n; ++j)
            {
                if(board[i][j] == word[0] && found_next_char(board, word, j, i, index))
                    return true;
            }
        }
        return false;
    }
};