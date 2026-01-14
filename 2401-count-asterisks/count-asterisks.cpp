class Solution {
public:
    int countAsterisks(string s) {
        bool inside = false;
        int count=0;
        for (auto c : s)
        {
            if (c == '|')
            {
                inside = !inside;
            }
            else if ( c == '*' && inside == false )
            {
                count++;

            }

        }

        return count;
    }
};