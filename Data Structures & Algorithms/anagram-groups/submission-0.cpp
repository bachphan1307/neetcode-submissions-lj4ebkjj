#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store key: sorted string, value: vector of original strings
        unordered_map<string, vector<string>> hmap;
        
        // 1. Iterate through all strings
        for(string s : strs) {
            string original = s; // Keep a copy of the original string
            
            // 2. Sort the string to create the "key"
            // "eat" -> "aet", "tea" -> "aet", "tan" -> "ant"
            sort(s.begin(), s.end());
            
            // 3. Group them in the map
            hmap[s].push_back(original);
        }
        
        // 4. Convert the map values to the final result format
        vector<vector<string>> res;
        for(auto const& [key, val] : hmap) {
            res.push_back(val);
        }
        
        return res;
    }
};