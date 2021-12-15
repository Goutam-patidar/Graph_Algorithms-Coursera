#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool explore(vector<vector<ll>> &v, vector<ll> &v1, ll x, ll y)//funtion calling
{
    if (x == y)//checking if start == end then return true
        return 1;

    v1[x] = 1;// marking as visited nodes at the given position
    for (ll i = 1; i <= v.size(); i++)
    {
        if (!v1[i])// it return true when the postion is unvisited 
        {
            if (v[x][i]) //checking the edges is present or not
            {
                if (explore(v, v1, i, y)) //recursive call
                    return 1;
            }
        }
    }
    return 0;
}

bool reach(vector<vector<ll>> &v, ll x, ll y)
{
    vector<ll> v1(v.size());//vector for checking visited of=r non visited nodes
    ll p = explore(v, v1, x, y);// calling funtion 

    /*for (ll i = 0; i < v.size(); i++)
        cout << v1[i] << "   ";

    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
*/
    return p;
}

int main()
{
    ll m, n;
    cin >> n >> m;// n=no.  of nodes   and m = no. of conntecting edges
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));//making 2d vector and intilize with 0 at all postition.
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.at(x).at(y) = 1;// making a 2d vector and putting 1 at connected edges
        v.at(y).at(x) = 1;
    }
    ll x, y;
    cin >> x >> y;// taking start and end point respectively
    if (reach(v, x, y)) //funtion call which return bool value 
        cout << "1" << endl;
    else
        cout << "0" << endl;// printing result
}
