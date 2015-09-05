// Brute force, O(n)

#include <vector>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<char> letter = {'I','V','X','L','C','D','M'};
        string ans; 
        int index = 6;
        int limit = 1000;
        while (num<limit) {
            limit /= 10;
            index -= 2;
        }
        while (limit>0) {
            int digit = num/limit%10;
            switch (digit) {
                case 0: break;
                case 6:case 7:case 8:
                        ans.push_back(letter[index+1]);
                        digit -= 5;
                case 1:case 2:case 3:
                        ans.append(digit,letter[index]);
                        break;
                case 4: ans.push_back(letter[index]);
                case 5: ans.push_back(letter[index+1]);
                        break;
                case 9: ans.push_back(letter[index]);
                        ans.push_back(letter[index+2]);
                        break;
            }
            limit /= 10;
            index -= 2;
        }
        return ans;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ("I", sol.intToRoman(1));
    EXPECT_EQ("III", sol.intToRoman(3));
    EXPECT_EQ("XIX", sol.intToRoman(19));
    EXPECT_EQ("CDXCIX", sol.intToRoman(499));
    EXPECT_EQ("MMMCMXCIX", sol.intToRoman(3999));
    EXPECT_EQ("MMMCDLXXXIX", sol.intToRoman(3489));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
