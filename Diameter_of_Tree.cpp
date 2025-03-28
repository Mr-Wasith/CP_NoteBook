#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int depth[N];

void dfs(int vertex, int par = -1)
{
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
    int mx_depth = -1;
    int mx_depth_node;
    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i] = 0;
    }

    // Call dfs for the max depth node. so that we can get
    // the maximum depth which is the diameter of the Tree

    dfs(mx_depth_node);
    mx_depth = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
}