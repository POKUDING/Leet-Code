class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto str : tokens) {
            if (isdigit(str[0]) || str.length() != 1) {
                s.push(stoi(str));
                continue;
            }
            int num1 = s.top();
            s.pop();
            int num2 = s.top();
            s.pop();
            switch(str[0]) {
                case '+':
                    s.push(num2 + num1);
                    break;
                case '-':
                    s.push(num2 - num1);
                    break;
                case '/' :
                    s.push(num2 / num1);
                    break;
                case '*':
                    s.push(num2 * num1);
                    break;
            }
        }
        return s.top();
    }
};