#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(vector<vector<ll>> &v, vector<ll> flag, ll i)// declaration of dfs funtion
{
    flag[i] == 1; // putting 1 at postion where we are visiting at flag vector
    for (ll j = 1; j <= v.size(); j++)
    {
        if (v[i][j] && flag[j] == -1) //checking in 2d vector for 1 and chevking for unvisited nodes 
            dfs(v, flag, j); // recursive call of funtion at j postion
    }
    return;
}

ll find(vector<vector<ll>> &v, vector<ll> &flag)
{
    ll count = 0; //declaration of count variable
    for (ll i = 1; i <= v.size(); i++)
    {
        if (flag[i] == -1)
        {
            dfs(v, flag, i);// calling of dfs funtion
            count++;// increasing value for counting the connected edges
        }
    }
    return count;
}

int main()
{
    ll n, m;
    cin >> n >> m; // n=no.  of nodes   and m = no. of conntecting edges
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));//making 2d vector and intilize with 0 at all postition.
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.at(x).at(y) = 1; // making a 2d vector and putting 1 at connected edges
        v.at(y).at(x) = 1;
    }
    vector<ll> flag(n+1, -1);// createing an flag vector (for marking visiting and unvisited nodes)

    /*
    for (ll i = 1; i <= n+1; i++)
        cout << flag.at(i) << "   ";

    for (ll i = 0; i <= n+1; i++)
    {
        for (ll j = 0; j <= n+1; j++)
        {
            cout << v.at(i).at(j)<< " ";
        }
        cout << endl;
    }
    */
    cout<<find(v, flag)<<endl;// funtion calling

}
