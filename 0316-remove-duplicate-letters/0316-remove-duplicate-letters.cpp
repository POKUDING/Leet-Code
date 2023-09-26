class Solution {
public:
    string removeDuplicateLetters(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<char, int> last;
        stack<char> tmp;
        unordered_set<char>  seen;
        
        for(int i = 0, len = s.length(); i < len; ++i)
          last[s[i]] = i;
        
        for(int i = 0, len = s.length(); i < len; ++i)
        {
          char c = s[i];
          if (seen.find(c) == seen.end())
          {
            while (!tmp.empty() && i < last[tmp.top()] && c < tmp.top())
            {
              seen.erase(tmp.top());
              tmp.pop();
            }
            seen.insert(c);
            tmp.push(c);
          }
        }
        string rtn;
        while(!tmp.empty())
        {
          rtn += tmp.top();
          tmp.pop();
        }
        reverse(rtn.begin(), rtn.end());
        return rtn;
    }
};