#include<bits/stdc++.h>

using namespace std;

//no. of digits <=num which whose digits sum == x


int dp[10001][201][2];



int solve(string num, int n, int x, bool tight)
{
    if (x < 0)return 0;

    if (n == 0)
    {
        if (x == 0)return 1;
        return 0;
    }

    if (dp[n][x][tight] != -1)return dp[n][x][tight];


    int temp = 0;

    int ub = tight ? (num[num.length() - n] - '0') : 9;


    for (int i = 0;i <= ub;i++)
    {
        temp += solve(num, n - 1, x - i, (tight & (i == ub)));
    }


    return  dp[n][x][tight] = temp;
}
int main()
{



    memset(dp, -1, sizeof(dp));

    string num;
    cin >> num;

    int x;
    cin >> x;


    int ans = solve(num, num.length(), x, 1);
    cout << ans << endl;

}
