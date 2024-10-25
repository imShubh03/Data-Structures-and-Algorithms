#include <bits/stdc++.h>
using namespace std;

//TC:O(m*n)+ 4 *O(m* n)   SC:O(m*n)stackspace + O(m *n) copy arr

void dfs(int m, int n, vector<vector<int>>& ans, vector<vector<int>>& image, int row, int col, int newcolor, int inicolor) {
    ans[row][col] = newcolor;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor) {
            dfs(m, n, ans, image, nrow, ncol, newcolor, inicolor);
        }
    }
}

vector<vector<int>> floodFill(int m, int n, vector<vector<int>>& image, int sr, int sc, int newcolor) {
    int inicolor = image[sr][sc];
    vector<vector<int>> ans = image;

    if (inicolor != newcolor) {
        dfs(m, n, ans, image, sr, sc, newcolor, inicolor);
    }

    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newcolor;
    cin >> sr >> sc >> newcolor;

    vector<vector<int>> res = floodFill(m, n, image, sr, sc, newcolor);

    for (const auto& row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
