class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

    bool isIPv4(string s) {
        if (s.empty() || s.back() == '.') return false;
        if (count(s.begin(), s.end(), '.') != 3) return false;

        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] == '.') return false;

            int num = 0, digits = 0;
            while (i < n && s[i] != '.') {
                if (!isdigit(s[i])) return false;
                if (digits == 0 && s[i] == '0' && i + 1 < n && s[i + 1] != '.')
                    return false;
                num = num * 10 + (s[i] - '0');
                if (num > 255) return false;
                digits++;
                i++;
            }
            if (digits == 0) return false;
            i++;
        }
        return true;
    }

    bool isIPv6(string s) {
        if (s.empty() || s.back() == ':') return false;
        if (count(s.begin(), s.end(), ':') != 7) return false;

        int i = 0, n = s.size();

        while (i < n) {
            int len = 0;
            while (i < n && s[i] != ':') {
                if (!isxdigit(s[i])) return false;
                len++;
                if (len > 4) return false;
                i++;
            }
            if (len == 0) return false;
            i++;
        }
        return true;
    }
};
