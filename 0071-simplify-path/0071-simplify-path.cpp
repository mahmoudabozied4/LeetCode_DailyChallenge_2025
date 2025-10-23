class Solution {
public:
    string simplifyPath(string path) {
        stack<string> directoryStack;
        stringstream pathStream(path);
        string token;
        while (getline(pathStream, token, '/')) {
            if (token == "" || token == ".")
                continue;
            if (token == "..") {
                if (!directoryStack.empty()) {
                    directoryStack.pop();
                }
            } else {
                directoryStack.push(token);
            }
        }
        if (directoryStack.empty()) return "/";
    
        string ans;
        while(!directoryStack.empty()){
            ans = "/" + directoryStack.top() + ans;
            directoryStack.pop();
        }
        return ans;
    }
};