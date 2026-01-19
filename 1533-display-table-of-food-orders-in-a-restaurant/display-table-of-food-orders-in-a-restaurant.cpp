class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> table;
        set<string> foods;

        for (auto &o : orders) {
            int tableNum = stoi(o[1]);
            string food = o[2];
            table[tableNum][food]++;
            foods.insert(food);
        }

        vector<vector<string>> res;
        vector<string> header;
        header.push_back("Table");
        for (auto &f : foods) header.push_back(f);
        res.push_back(header);

        for (auto &t : table) {
            vector<string> row;
            row.push_back(to_string(t.first));
            for (auto &f : foods) {
                row.push_back(to_string(t.second.count(f) ? t.second[f] : 0));
            }
            res.push_back(row);
        }
        return res;
    }
};
