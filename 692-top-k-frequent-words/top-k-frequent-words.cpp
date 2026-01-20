class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (auto &w : words) freq[w]++;

        vector<string> v;
        for (auto &p : freq) v.push_back(p.first);

        sort(v.begin(), v.end(), [&](const string& a, const string& b) {
            if (freq[a] != freq[b]) return freq[a] > freq[b];
            return a < b;
        });

        return vector<string>(v.begin(), v.begin() + k);
    }
};
