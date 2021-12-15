#include <bits/stdc++.h>

using namespace std;

int minimum(vector<int> &dist, unordered_set<int> &s)//finding minimum
{
    int j=0, i, min = INT_MAX;
    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] < min && s.find(i) == s.end())
        {
            min = dist[i];
            j = i;
        }
    }

    return j;//return index
}

int shortest_path(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y)
{
    unordered_set<int> s;
    vector<int> dist(b.size(), INT_MAX);//vector for sstoring distance from source
    dist.at(x) = 0;
 for(int z=1;z<b.size()-2;z++)
 {
    for (int i = 1; i < b.size(); i++)
    {
        int k = minimum(dist, s);
        if (k==0)
            break;
        s.insert(k);
        for (int j = 0; j < a[k].size(); j++)
        {
            int m = a[k][j];

            if(dist[m]>b[k][m]+dist[k])//relaxing connected nodes
            {
                dist[m]=dist[k]+b[k][m];
            }
        }
    }
    s.clear();
 }
    if(dist[y]!=INT_MAX)
        return dist[y];

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;                               // createing an flag vector (for marking visiting and unvisited nodes)
    vector<vector<int>> a(n + 1, vector<int>()); //making 2d vector and intilize with 0 at all postition.
    vector<vector<int>> b(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a.at(x).push_back(y); //making a 2d vector and putting 1 at connected edges
        b.at(x).at(y) = z;
    }
    int x, y;
    cin >> x >> y;
    cout << shortest_path(a, b, x, y);
}
