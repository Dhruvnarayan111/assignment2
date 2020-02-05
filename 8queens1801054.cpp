#include <bits/stdc++.h>
#define N 8
using namespace std;
bool check(int a[N][N], int row, int col);
bool sol(int a[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {

        if (check(a, i, col)) {
            a[i][col] = 1;

            if (sol(a, col + 1))
                return true;

            a[i][col] = 0;
        }
    }

    return false;
}
bool check(int a[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (a[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (a[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (a[i][j])
            return false;
    return true;
}

void print(int a[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j];
        cout << '\n';
    }
}
int main()
{
    int a[N][N] = { 0 };
    if (sol(a, 0) == true) {
        print(a);
    }
}