#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> &a, int u, int v) // funtion defination
{
    vector<int> dist(a.size(), INT_MAX); // vector for storing distances from given starting node

    dist.at(u) = 0; // marking starting node as distance 0;
    queue<int> q;   // queue for bfs traversal
    q.push(u);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < a[k].size(); i++)
        {
            // pushing all the connected element of k in queue
            if (dist.at(a[k][i]) == INT_MAX)
            {
                q.push(a[k][i]);
                dist.at(a[k][i]) = dist.at(k) + 1;
            }
        }
    }
    /* for (int j = 0; j < a.size(); j++)
    {
        cout << dist[j] << " ";
    }*/
    if (dist.at(v) != INT_MAX)
        return dist.at(v); // returning distance of v index

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;                               // n=no. of nodes , m=no. of edges
    vector<vector<int>> a(n + 1, vector<int>()); // creating vector _list

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a.at(x).push_back(y);
        a.at(y).push_back(x); // making edges 1
    }
    int u, v;
    cin >> u >> v; // u= starting point and v= ending point

    /*  for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    */
    cout << bfs(a, u, v); // caliing funtion
}
