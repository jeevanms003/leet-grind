class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } 
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            else {
                stack.push_back(token);
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1)
                result += "/";
        }

        return result;
    }
};
