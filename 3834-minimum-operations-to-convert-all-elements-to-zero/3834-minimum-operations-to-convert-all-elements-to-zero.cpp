class Solution {
    template<typename T>
    struct MonoStack {
        stack<pair<T, T> > st;

        void push(const T &x) {
            T mx = st.empty() ? x : max(x, st.top().second);
            st.emplace(x, mx);
        }

        void pop() {
            st.pop();
        }

        T top() { return st.top().first; }

        bool empty() { return st.empty(); }

        size_t size() { return st.size(); }

        T getMax() { return st.top().second; }

        void clear() { while (!st.empty()) st.pop(); }
    };

public:
    int minOperations(vector<int> &nums) {
        int ans = 0;

        MonoStack<int> st;
        for (int x: nums) {
            if (x == 0) {
                st.clear();
                continue;
            }

            while (!st.empty() && st.top() > x) st.pop();

            if (st.empty() || st.top() < x) {
                st.push(x);
                ++ans;
            }
        }
        return ans;
    }
};