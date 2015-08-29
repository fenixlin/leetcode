// DFS, O(n^2). Consider substrings with and without '*' separately. Equivalent complexity as Dynamic Programming. Requires good understanding of the requirements.
// 1. '*' is combined with exactly 'one' preceeding character.
// 2. Two strings should be matched 'strictly', rather than being a substring of another.
// 3. Greedy algorithm is not enough since you won't know how much should ".*" matches.

#include <string>
#include <list>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = s.length()-1;
        int j = p.length()-1;
        list<char> eat;

        while (j-1>=0 && p[j]=='*') {
            eat.push_back(p[j-1]);
            j -= 2;
        }
        while (i>=0) {
            int oldi = i;
            int ii = i;
            int jj = j;
            while (ii>=0 && jj>=0 && p[jj]!='*' && (s[ii]==p[jj] || p[jj]=='.')) {
                ii--;
                jj--;
            }
            if (jj>=0 && p[jj]=='*' && isMatch(s.substr(0,ii+1), p.substr(0,jj+1)) || ii<0 && jj<0) return true;
            while (!eat.empty() && eat.front()!='.' && eat.front()!=s[i]) eat.pop_front();
            if (!eat.empty()) i--;
            if (i==oldi) break;
        }
        while (j-1>=0 && p[j]=='*') j-=2;
        if (i<0 && j<0) return true;
        else return false;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(false, sol.isMatch("aa","a"));
    EXPECT_EQ(true, sol.isMatch("aa","aa"));
    EXPECT_EQ(false, sol.isMatch("aaa","aa"));
    EXPECT_EQ(true, sol.isMatch("aa","a*"));
    EXPECT_EQ(true, sol.isMatch("aa",".*"));
    EXPECT_EQ(true, sol.isMatch("ab",".*"));
    EXPECT_EQ(true, sol.isMatch("aab","c*a*b"));

    EXPECT_EQ(false, sol.isMatch("aaacb","a*c.b"));
    EXPECT_EQ(true, sol.isMatch("acccb","a.c*b"));
    EXPECT_EQ(false, sol.isMatch("aaacb","a.c.b"));
    EXPECT_EQ(false, sol.isMatch("aab",".b"));
    EXPECT_EQ(false, sol.isMatch("aab",".b."));
    EXPECT_EQ(true, sol.isMatch(" *",".."));
    EXPECT_EQ(false, sol.isMatch(" ***",". .."));
    EXPECT_EQ(true, sol.isMatch("*","."));
    EXPECT_EQ(true, sol.isMatch("","a*d*"));
    EXPECT_EQ(true, sol.isMatch("c","c*a*d*"));
    EXPECT_EQ(false, sol.isMatch("",".a*d*"));
    EXPECT_EQ(true, sol.isMatch("aaaa","b*aaa."));
    EXPECT_EQ(true, sol.isMatch("abaabaaab","abaa.aaac*b"));
    EXPECT_EQ(false, sol.isMatch("abaabaaab","abaa.a.aa.aaab"));

    EXPECT_EQ(false, sol.isMatch("abcd","d*"));
    EXPECT_EQ(true, sol.isMatch("a","d*a"));
    EXPECT_EQ(true, sol.isMatch("aaddd","a*dd*d"));
    EXPECT_EQ(false, sol.isMatch("cda","d.*"));
    EXPECT_EQ(false, sol.isMatch("ab",".*c"));
    
    EXPECT_EQ(true, sol.isMatch("aaa","ab*a*c*a"));
    EXPECT_EQ(true, sol.isMatch("aaca","ab*a*c*a"));
    EXPECT_EQ(false, sol.isMatch("aaca","ac*a*b*a"));    
    EXPECT_EQ(true, sol.isMatch("bab","..*"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc","c*.b*a*a.*a.*c"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc",".*.b*a*a.*cbc.*.a*c.*"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc",".*acc"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc","c*b*a*b*acc.*"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc",".*acc.*acc"));
    EXPECT_EQ(true, sol.isMatch("baabbbaccbccacacc",".*cb.*cc.*ac.*"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
