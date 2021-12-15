
//in directed graphs
#include <bits/stdc++.h>

using namespace std;

int detect(vector<int> &flag, vector<vector<int>> &a, stack<int> &s)
{

    
	 flag[s.top()] = 1;// marking as visited nodes
    if (!s.empty())// checking for stack is empty or not
    {
        for (int i = 1; i < a.size(); i++)
        {
            if (a[s.top()][i] == 1 && flag[i] == 0)// checking for edges and also that  given node is unvisited 
            {
                
                s.push(i);// if unvisited then pushing in stack
                if(detect(flag, a, s))// recursive call
                	return 1;
            }
            else if (a[s.top()][i] == 1 && flag[i] == 1)//checking for edges and also that  given node is visited
                return 1;//means cycle is present
        }
        flag[s.top()] = 2;//marking as completely visited and popout from stck
        s.pop();
        return 0;
    }
    return 0;
}

int search(vector<vector<int>> &a, int n)
{

    vector<int> flag(a.size(), 0);// vector for checking visited or unvisited nodes
    stack<int> s; //declaration of stack
    int k;
    for (int i = 1; i < a.size(); i++)
    {
        if (flag[i] == 0)// checking for unvisited nodes
        {
            s.push(i);
            
            k = detect(flag, a, s);// calling funtion
            if (k)//checking if cycle is present if present then return
                return 1;
        }
    }
    /* for (int i = 0; i < n + 1; i++)
        cout << flag[i];
    cout << endl;
*/
    return k;
}

int main()
{
    int n, m;
    cin >> n >> m;// createing an flag vector (for marking visiting and unvisited nodes)
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));//making 2d vector and intilize with 0 at all postition.
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a.at(x).at(y) = 1;//making a 2d vector and putting 1 at connected edges
    }

    /* for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    */
    cout << search(a, n) << endl;// calling funtion
}
