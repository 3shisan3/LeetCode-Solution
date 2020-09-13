class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		bool ans = false;
		int len = word.size();
		int flag = 0;
		auto tmp = vector<way>();
		judgement(board, word, flag, len, ans, 0, 0, tmp);
		return ans;
	}

	struct way
	{
		int m;
		int n;
	};

	void judgement(vector<vector<char>>& board, string word, int flag, int len, bool& ans, int a, int b, vector<way> tmp)
	{
		way tmps;
		if (flag != 0)
		{
			tmps.m = a;
			tmps.n = b;
			tmp.push_back(tmps);
		}
		if (flag == len)
		{
			ans = true;
			return;
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (flag == 0)
				{
					if (board[i][j] == word[flag])
					{
						judgement(board, word, flag + 1, len, ans, i, j, tmp);
					}
				}
				else
				{
					if (board[i][j] == word[flag])
					{
						if ((((i == a + 1) || (i == a - 1)) && (j == b))
							|| (((j == b + 1) || (j == b - 1)) && (i == a)))
						{
							bool YN = true;
							for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
							{
								if ((*iter).m == i && (*iter).n == j)
								{
									YN = false;
									break;
								}
							}
							if (YN == true)
							{
								judgement(board, word, flag + 1, len, ans, i, j, tmp);
							}
						}
					}
				}
			}
		}
		return;
	}
};



//时间复杂度超了。。。


































class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(board, word, 0, i , j)){ // 从二维表格的每一个格子出发
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int wordIndex, int x, int y){
        if( board[x][y] != word[wordIndex]){ // 当前位的字母不相等，此路不通
            return false;
        }
        if(word.size() - 1  == wordIndex){ // 最后一个字母也相等, 返回成功
            return true;
        }
        char tmp = board[x][y]; 
        board[x][y] = 0; // 避免该位重复使用
        wordIndex++;
        if((x > 0 && backtrack(board, word, wordIndex, x - 1, y)) // 往上走 (此处多谢笑川兄指正)
        || (y > 0 && backtrack(board, word, wordIndex, x, y - 1)) // 往左走
        || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y)) // 往下走
        || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))){ // 往右走
            return  true; // 其中一条能走通，就算成功
        }
        board[x][y] = tmp; // 如果都不通，则回溯上一状态
        return false;
    }
};
