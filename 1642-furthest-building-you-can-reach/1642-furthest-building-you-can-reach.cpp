const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int brick_used = 0, size = heights.size() - 1;
        for(int i = 1, gap =0; i <= size; ++i) {
            gap = heights[i] - heights[i - 1];
            if (gap <= 0) continue;
            pq.push(gap);
            brick_used += gap;
            if(brick_used <= bricks) continue;
            if(ladders <= 0) return i - 1;
            --ladders;
            brick_used -= pq.top();
            pq.pop();
        }
        return size;
    }
};