#include <bits/stdc++.h>

using namespace std;

vector<int> update_(vector<vector<int>> &v)
{
    vector<int> s(v.size());
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            if (v[i][j] == 1)
                s[j]++;
        }
    }
    return s;
}

int search_(vector<int> &v1,unordered_set<int> &s)// funtion defination
{
    for (int i = 1; i < v1.size(); i++)
    {
        if (v1[i] == 0 && s.find(i) == s.end())// checking the node is visited or not and also any edges are present or not
        {
            return i;// returning the i index where the edges is present and i is unvisited
        }
    }
    return 0;
}

vector<int> tp_sort(vector<vector<int>> &v,unordered_set<int> &s, vector<int> &a)
{
    vector<int> v1(v.size(), 0);// creating vector for storing order
    v1 = update_(v);

    /*   for (int j = 1; j <v1.size(); j++)
    {
        cout << v1[j] << " ";
    }
    cout << endl;
*/
    int k = search_(v1, s);// funtion call

    if (k != 0)
    {
        for (int i = 1; i < v.size(); i++)
        {
            v.at(k).at(i) = 0;//deleting the visited nodes from graph
        }
        a.push_back(k);// adding in visited set and also to the order
        s.insert(k);
        return tp_sort(v, s, a);// recursive call
    }
    return a;
}

int main()
{
    int n, m;
    cin >> n >> m;// n= no. of nodes and m= no. edeges
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));// amking an 2d vector
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.at(x).at(y) = 1;// putting 1 at connecting edges
    }
    unordered_set<int>s{};// making an set for checking visited and unvisited node
    vector<int> a;
    a = tp_sort(v, s, a);// calling funtion
    for (int i = 0; i < a.size(); i++)// printing vector order
    {
        cout << a[i] << " ";
    }
}
