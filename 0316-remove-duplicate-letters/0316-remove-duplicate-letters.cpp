class Solution {
public:
    string removeDuplicateLetters(string s) {
        int     last[26] ={0};
        bool    seen[26] = {false};
        char    stack[26] = {0};
        int     top = -1;

        for(int i = 0, len = s.length(); i < len; ++i)
          last[s[i] - 'a'] = i;
        
        for(int i = 0, len = s.length(); i < len; ++i)
        {
          char c = s[i];
          if (!seen[c - 'a'])
          {
            while (top != -1 && i < last[stack[top] - 'a'] && c < stack[top])
              seen[stack[top--] - 'a'] = false;
            seen[c - 'a'] = true;
            stack[++top] = c;
          }
        }
        return string(stack, top + 1);
    }
};
