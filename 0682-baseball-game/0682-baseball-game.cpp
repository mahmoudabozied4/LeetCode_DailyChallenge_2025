class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for (const string& operation : operations)
            if (operation == "+")
                v.push_back(v.back() + v[v.size() - 2]);
            else if (operation == "D")
                v.push_back(v.back() * 2);
            else if (operation == "C")
                v.pop_back();
            else
                v.push_back(stoi(operation));

        return accumulate(v.begin(), v.end(), 0);
    }
};