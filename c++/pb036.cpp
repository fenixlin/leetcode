// Brute force, compressed with bit operation, O(n^2)

#include <vector>
#include <gtest/gtest.h>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {   
        int offset = 0;
        int row[9], col[9], blk[9], bin[9];
        bin[0] = 1;
        for (int i=1; i<9; i++) bin[i] = bin[i-1] << 1;
        for (int i=0; i<9; i++) row[i] = col[i] = blk[i] = 0;
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j]=='.') continue;
                int x = board[i][j]-'1';
                if (bin[x] & row[i] || bin[x] & col[j] || bin[x] & blk[i/3*3+j/3]) return false;
                row[i] |= bin[x];
                col[j] |= bin[x];
                blk[i/3*3+j/3] |= bin[x];
            }
        return true;
    }
};

TEST(case1, test1) {
    typedef vector<char> V;
    Solution sol;
    vector<vector<char>> v;
    v.push_back(V{'5','3','.','.','7','.','.','.','.'});
    v.push_back(V{'6','.','.','1','9','5','.','.','.'});
    v.push_back(V{'.','9','8','.','.','.','.','6','.'});
    v.push_back(V{'8','.','.','.','6','.','.','.','3'});
    v.push_back(V{'4','.','.','8','.','3','.','.','1'});
    v.push_back(V{'7','.','.','.','2','.','.','.','6'});
    v.push_back(V{'.','6','.','.','.','.','2','8','.'});
    v.push_back(V{'.','.','.','4','1','9','.','.','5'});
    v.push_back(V{'.','.','.','.','8','.','.','7','9'});
    EXPECT_EQ(true, sol.isValidSudoku(v));
    v.clear();
    v.push_back(V{'5','3','4','6','7','8','9','1','2'});
    v.push_back(V{'6','7','2','1','9','5','3','4','8'});
    v.push_back(V{'1','9','8','3','4','2','5','6','7'});
    v.push_back(V{'8','5','9','7','6','1','4','2','3'});
    v.push_back(V{'4','2','6','8','5','3','7','9','1'});
    v.push_back(V{'7','1','3','9','2','4','8','5','6'});
    v.push_back(V{'9','6','1','5','3','7','2','8','4'});
    v.push_back(V{'2','8','7','4','1','9','6','3','5'});
    v.push_back(V{'3','4','5','2','8','6','1','7','9'});
    EXPECT_EQ(true, sol.isValidSudoku(v));
    v.clear();
    v.push_back(V{'5','3','4','6','7','8','.','1','2'});
    v.push_back(V{'6','7','2','1','9','5','3','4','8'});
    v.push_back(V{'1','9','8','3','4','2','5','6','7'});
    v.push_back(V{'8','5','9','7','6','1','4','2','3'});
    v.push_back(V{'4','2','6','8','5','3','7','9','1'});
    v.push_back(V{'7','1','3','9','2','4','8','5','6'});
    v.push_back(V{'.','6','1','5','3','7','9','8','4'});
    v.push_back(V{'2','8','7','4','1','9','6','3','5'});
    v.push_back(V{'3','4','5','2','8','6','1','7','9'});
    EXPECT_EQ(false, sol.isValidSudoku(v));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
