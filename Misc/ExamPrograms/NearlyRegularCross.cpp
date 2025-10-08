#include <iostream>
#include <vector>
using std::vector;

struct LineInfo 
{
    int type = 0;
    int common = 0;
    int singletonPos = -1;
};

LineInfo analyzeRow(const vector<int>& row) {
    LineInfo info;
    int n = (int)row.size();

    int v0 = row[0], c0 = 0, last0 = -1;
    int v1 = 0, c1 = 0, last1 = -1;

    for (int j = 0; j < n; ++j) 
    {
        if (row[j] == v0) 
        { 
            ++c0; 
            last0 = j; 
        }
        else if (c1 == 0) 
        { 
            v1 = row[j]; 
            c1 = 1; 
            last1 = j; 
        }
        else if (row[j] == v1) 
        { 
            ++c1; 
            last1 = j; 
        }
        else 
        { 
            info.type = 0; 
            return info; 
        }
    }

    if (c1 == 0) 
    { 
        info.type = 1; 
        info.common = v0; 
        return info; 
    }

    if (c0 == 1) 
    { 
        info.type = 2; 
        info.common = v1; 
        info.singletonPos = last0; 
        return info; 
    }

    if (c1 == 1) 
    { 
        info.type = 2; 
        info.common = v0; 
        info.singletonPos = last1; 
        return info; 
    }

    

    info.type = 0;
    return info;
}

LineInfo analyzeCol(const vector<vector<int>>& a, int col) {
    LineInfo info;
    int n = (int)a.size();

    int v0 = a[0][col]; 
    int c0 = 0; 
    int last0 = -1;
    int v1 = 0, c1 = 0, last1 = -1;

    for (int i = 0; i < n; ++i) 
    {
        int x = a[i][col];
        if (x == v0) 
        { 
            ++c0; 
            last0 = i; 
        }

        else if (c1 == 0) 
        { 
            v1 = x; 
            c1 = 1; 
            last1 = i; 
        }

        else if (x == v1) 
        { 
            ++c1; 
            last1 = i; 
        }

        else 
        { 
            info.type = 0; 
            return info; 
        }
    }

    if (c1 == 0) 
    { 
        info.type = 1; 
        info.common = v0; 
        return info; 
    }

    if (c0 == 1) 
    { 
        info.type = 2; 
        info.common = v1; 
        info.singletonPos = last0; 
        return info; 
    }

    if (c1 == 1) 
    { 
        info.type = 2; 
        info.common = v0; 
        info.singletonPos = last1; 
        return info; 
    }
    
    info.type = 0;
    return info;
}


int solution(vector<vector<int>> matrix) {
    int n = (int)matrix.size(); // number of rows
    std::cout << "n: " << n << std::endl;
    int m = (int)matrix[0].size(); // number of columns
    std::cout << "m: " << m << std::endl;
    
    vector<LineInfo> rowInfo(n); 
    vector<LineInfo> colInfo(m);

    for (int r = 0; r < n; ++r) 
    {
        rowInfo[r] = analyzeRow(matrix[r]);
    }

    for (int c = 0; c < m; ++c) 
    {
        colInfo[c] = analyzeCol(matrix, c);
    }

    int ans = 0;

    for (int r = 0; r < n; ++r) 
    {
        if (rowInfo[r].type == 0) continue;
        
        for (int c = 0; c < m; ++c) 
        {
            if (colInfo[c].type == 0) continue;

            bool rowOK = (rowInfo[r].type == 1) || (rowInfo[r].type == 2 && rowInfo[r].singletonPos == c);
            bool colOK = (colInfo[c].type == 1) || (colInfo[c].type == 2 && colInfo[c].singletonPos == r);

            if (rowOK && 
                colOK && 
                rowInfo[r].common == colInfo[c].common) 
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> a = {{1, 2, 1},
                             {2, 1, 2},
                             {1, 2, 1}};    

    vector<vector<int>> b = {{1,2},
                             {2,1}};

    
    std::cout << solution({{1, 1, 1, 1},
                           {2, 3, 1, 1},
                           {1, 1, 1, 0},
                           {1, 4, 1, 1}}) << std::endl; 

    std::cout << solution({{1,2}, {2,1}}) << std::endl; // answer should be 4, but we are getting 1
    std::cout << solution({{1,2,3}, {2,1,3}}) << std::endl; 
    std::cout << solution(b) << std::endl; 

    return 0;
}