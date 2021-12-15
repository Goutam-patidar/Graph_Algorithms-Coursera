#include <bits/stdc++.h>

using namespace std;

int minimum(vector<int> &dist, unordered_set<int> &s) //finding minimum
{
    int j = 0, i, min = INT_MAX;
    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] < min && s.find(i) == s.end())
        {
            min = dist[i];
            j = i;
        }
    }

    return j; //return index
}

int bellemen(vector<vector<int>> &a, vector<vector<int>> &b, unordered_set<int> &s, int x)
{

    vector<int> dist(b.size(), INT_MAX); //vector for storing distance from source
    dist.at(x) = 0;
    for (int z = 1; z < b.size() - 1; z++)
    {
        s.clear();
        for (int i = 1; i < b.size(); i++)
        {
            int k = minimum(dist, s);
            if (k == 0)
                break;
            s.insert(k);
            for (int j = 0; j < a[k].size(); j++)
            {
                int m = a[k][j];

                if (dist[m] > b[k][m] + dist[k]) //relaxing connected nodes
                {
                    dist[m] = dist[k] + b[k][m];
                    if (z== b.size()-2)
                        return 1;
                }
            }
        }
    }

    return 0;
}

/*bool shortest_path(vector<vector<int>> &a, vector<vector<int>> &b)
{
    unordered_set<int> s;
    int k;
    for(int i=1; i<b.size(); i++)
    {
        if(s.find(i)==s.end())
        {
            k= bellemen(a,b,s,i);
            if(!k)
                return 0;
        }
    }
    return k;
}*/

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
    unordered_set<int> s;
    cout << bellemen(a, b, s, 1);
}
