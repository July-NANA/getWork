#include <bits/stdc++.h>
using namespace std;

//深度优先搜索，回溯法
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        columns = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int t = 0; t < columns; t++)
            {
                /* code */
                if (dfs(board, word, i, t, 0))
                    return true;
            }
        }
        return false;
    }
    int rows, columns;
    // 当前元素在矩阵 board 中的行列索引 i 和 j ，当前目标字符在 word 中的索引 k
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
    {

        if (i < 0 || i >= rows || j < 0 || j >= columns || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
        {
            return true;
        }

        char temp = word[k];
        char temp_1 = board[i][j];
        board[i][j] = '\0';
        bool result = dfs(board, word, i - 1, j, k + 1) ||
                      dfs(board, word, i + 1, j, k + 1) ||
                      dfs(board, word, i, j - 1, k + 1) ||
                      dfs(board, word, i, j + 1, k + 1);
        board[i][j] = word[k];
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> test = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution lab;
    bool result = lab.exist(test, word);
    cout << result << endl;
    return 0;
}
