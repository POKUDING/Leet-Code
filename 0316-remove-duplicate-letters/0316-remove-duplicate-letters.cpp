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
          if (!seen[s[i] - 'a'])
          {
            while (top != -1 && i < last[stack[top] - 'a'] && s[i] < stack[top])
              seen[stack[top--] - 'a'] = false;
            seen[s[i] - 'a'] = true;
            stack[++top] = s[i];
          }
        }
        return string(stack, top + 1);
    }
};
