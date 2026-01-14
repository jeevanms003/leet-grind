class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = coordinates[0] - 'a';
        int col = coordinates[1] - '1';
        bool res = (row + col)%2;
        return res;
        
    }
};