class MyQueue {
private:
    stack<int> que;
    stack<int> push_s;

public:
    MyQueue() {}

    void push(int x) {
        while (!que.empty()) {
            push_s.push(que.top());
            que.pop();
        }
        push_s.push(x);
        while (!push_s.empty()) {
            que.push(push_s.top());
            push_s.pop();
        }
    }

    int pop() {
        int rtn = que.top();
        que.pop();
        return rtn;
    }

    int peek() { return que.top(); }

    bool empty() { return que.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */