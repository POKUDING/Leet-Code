const static auto _ = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxlen = 0;
        int curr_len = 1;
        int cnt_maxlen_char = 0;
        int tasks_size = tasks.size();
        sort(tasks.begin(),tasks.end());
        char pre_char = tasks[0];
        for(int i = 1; i <= tasks_size; ++i) {
            if(i < tasks_size && pre_char == tasks[i]) {
                ++curr_len;
                continue;            
            }
            if(curr_len > maxlen) {
                maxlen = curr_len;
                cnt_maxlen_char = 0;
            }
            if(maxlen == curr_len)
                ++cnt_maxlen_char;
            curr_len = 1;
            if(i < tasks_size)
                pre_char = tasks[i];
        }
        if((maxlen - 1) * (n + 1) + cnt_maxlen_char > tasks_size)
            return (maxlen - 1) * (n + 1) + cnt_maxlen_char;
        return tasks_size;
    }
};