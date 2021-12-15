#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, r, p;
    node(int x, int y, int p, int r = 0)
    {
        this->x = x;
        this->y = y;
        this->p = p;
        this->r = r;
    }
};
struct edge
{
    int u, v;
    double w;
    edge(int u, int v, double w)
    {
        this->v = v;
        this->u = u;
        this->w = w;
    }
};
void make_node(int i, vector<node> &nodes, vector<int> &x, vector<int> &y)
{
    nodes.push_back(node(x[i], y[i], i));
}
double weight(int x1, int y1, int x2, int y2)
{
    return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
int comp(edge a, edge b)
{
    return (a.w < b.w);
}
int find(int i, vector<node> &nodes)
{
    if (i != nodes[i].p)
    {
        nodes[i].p = find(nodes[i].p, nodes);
    }
    return nodes[i].p;
}
void Union(int u, int v, vector<node> &nodes)
{
    int a = find(u, nodes);
    int b = find(v, nodes);
    if (a != b)
    {
        if (nodes[a].r > nodes[b].r)
            nodes[b].p = a;
        else
        {
            nodes[a].p = b;
            if (nodes[a].r == nodes[b].r)
                nodes[b].r++;
        }
    }
}
double minimum_cost(vector<int> &x, vector<int> &y,int k)
{
    double result = 0;
    int n = x.size();
    vector<node> nodes;
    for (int i = 0; i < n; i++)
    {
        make_node(i, nodes, x, y);
    }
    vector<edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edges.push_back(edge(i, j, weight(x[i], y[i], x[j], y[j])));
        }
    }
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < edges.size(); i++)
    {
        edge temp = edges[i];
        int u = temp.u;
        int v = temp.v;
        if (find(v, nodes) != find(u, nodes))
        {
            result++;
            Union(u, v, nodes);
        }
        if (result > n - k)
            return temp.w;
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
        int k;
        cin>>k;
    cout << setprecision(15) << minimum_cost(x, y,k);
}
