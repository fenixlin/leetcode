// stl:map, easy, O(n)

#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last;
        int start = 0, ans = 0, i = 0;
        for (char ch : s) {
            if (last.find(ch) != last.end()) {
                if (i-start>ans) ans = i-start;
                if (last[ch]+1>start) start = last[ch]+1;
            }
            last[ch] = i;
            i++;
        }
        if (i-start>ans) ans = i-start;
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring(string("abba")) << endl;
    return 0;
}
