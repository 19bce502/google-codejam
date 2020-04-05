#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0

#define N 5
int grid[N][N];
vector<vector<int>> v[200000];
bool FindUnassignedLocation(int &row, int &col, int n);
int l;
bool isSafe(int row, int col, int num, int n);
  int cnt = 0;
set<int> s;
void printGrid(int n)
{
    int sum = 0;
    cnt++;

    for (int row = 0; row < n; row++)
    {
        vector<int> v1;
        for (int col = 0; col < n; col++)
        {
            v1.push_back(grid[row][col]);
                    }
        v[l].push_back(v1);

    }

    l++;


}
void SolveSudoku(int n)
{
    int row, col;

        if (!FindUnassignedLocation(row, col, n))
    {
        printGrid(n);
        return;
    }

    for (int num = 1; num <= n; num++)
    {

        if (isSafe(row, col, num, n))
        {

            grid[row][col] = num;


            SolveSudoku(n);

                      grid[row][col] = UNASSIGNED;
        }
    }

}

bool FindUnassignedLocation(int &row, int &col, int n)
{
    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int row, int num, int n)
{
    for (int col = 0; col < n; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int col, int num, int n)
{
    for (int row = 0; row < n; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool isSafe(int row, int col, int num, int n)
{
    return !UsedInRow(row, num, n) &&
           !UsedInCol(col, num, n) &&
            grid[row][col] == UNASSIGNED;
}

void clear(int n)
{
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            grid[i][j] = 0;
}

int main()
{

    SolveSudoku(2);
    int start[6], end[6];
    start[2] = 0, end[2] = l;
    clear(2);
    start[3] = l;
    SolveSudoku(3);
    end[3] = l;
    clear(3);
    start[4] = l;
    SolveSudoku(4);
    end[4] = l;
    clear(4);
    start[5] = l;
    SolveSudoku(5);
    end[5] = l;

    int t;
    cin >> t;
    for(int l=1;l<=t;l++)
    {
        int n, k;
        cin >> n >> k;
        int s = start[n], e = end[n];
        int i;
        for(i = s;i<e;i++)
        {
            vector<vector<int>> ch = v[i];
            int sum = 0;
            for(int j = 0;j<n;j++)
            {
                sum = sum + ch[j][j];
            }
            if(sum == k)
                break;
        }
        if(i == e)
            cout << "Case #"<<l<<": IMPOSSIBLE\n";
        else
        {
            cout << "Case #"<<l<<": POSSIBLE\n";
            vector<vector<int>> ch = v[i];
            for(i=0;i<ch.size();i++)
            {
                vector<int> ch1 = ch[i];
                for(auto j : ch1)
                    cout << j << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}
