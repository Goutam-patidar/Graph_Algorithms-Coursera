#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &a, queue<int> &q, vector<int> &v, int i)
{
    v.at(i) = 1;// marking first node as red
    q.push(i);// pushing in queue
    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        for (int j = 0; j < a[k].size(); j++)//finding connecting nodes of k nodes
        {
            int s=a[k][j];
            if ( v[s] == -1)// checking for unvisited node
            {
                v.at(s) = 1 - v.at(k); // marking blue and red one after one
                q.push(s);
            }
            else if ( v[s] == v[k])// if two contineously same colour found then return 0;
                return 0;
        }
    }
    return 1;//found bipartite return 1;
}

bool bipartite(vector<vector<int>> &a)
{
    vector<int> v(a.size(), -1);// for marking 1=red,0=blue,-1 for unvisited
    queue<int> q;//bfs traversal
   int k;
    for (int i = 0; i < a.size(); i++)
    {
        if (v[i] == -1)// checking for unvisited node
        {
             k = bfs(a, q, v, i);
           if (!k)//if bipartite condition fails then return 0 else return 1;
                return 0;
        }
    }
    return k;
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
    cout << bipartite(a);//caling funtion
}
