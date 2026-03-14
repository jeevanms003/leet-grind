class Solution {
public:

    void solve(int index, string digits, string temp, 
               vector<string>& ans, vector<string>& mp)
    {
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for(char ch : letters)
        {
            temp.push_back(ch);
            solve(index + 1, digits, temp, ans, mp);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        solve(0, digits, temp, ans, mp);

        return ans;
    }
};