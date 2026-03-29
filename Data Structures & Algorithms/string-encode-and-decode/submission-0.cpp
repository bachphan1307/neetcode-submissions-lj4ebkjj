class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string a: strs){
            encoded_string += to_string(a.length());
            encoded_string += "#";
            encoded_string += a;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int hashPos = s.find('#', i);
            int len = stoi(s.substr(i, hashPos - i));
            strs.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }

        return strs;
    }

};