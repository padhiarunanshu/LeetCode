class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(needle.size() > haystack.size()) return -1;
        
        for(int i = 0; i < haystack.length(); i++){
            if(haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
};
