#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &v, unordered_set<int> &s, stack<int> &st, int k)
{
    s.insert(k);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[k][i] == 1 && s.find(i) == s.end())
        {
            s.insert(i);
            dfs1(v, s, st, i);
        }
    }

    st.push(k);
    return;
}


int scc(vector<vector<int>> &v, vector<vector<int>> &vr)
{
    unordered_set<int> s{};
    stack<int> st;
    for (int i = 1; i < v.size(); i++)
    {
        if (s.find(i) == s.end())
        {
            dfs1(v, s, st, i);
        }
    }
    s.clear();
    int j = 0;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if (s.find(x) == s.end())
        {
            stack<int> componentStack;
            dfs1(vr, s, componentStack, x);
            j++;
        }
    }
    return j;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0)), vr(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.at(x).at(y) = 1;
        vr.at(y).at(x) = 1;
    }
    cout << scc(v, vr) << endl;
}
