#include <bits/stdc++.h>

// https://leetcode.com/problems/find-if-path-exists-in-graph/

using namespace std;

class Solution {
public:
    vector<int> representative;
    vector<int> size;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        for (int i = 0; i < n; ++i) {
            representative.push_back(i);
            size.push_back(1);
        }

        for(vector<int> edge: edges){
            combine(edge[0], edge[1]);
        }

        int sourceRepresentation = find(source);
        int destinationRepresentation = find(destination);

        representative.clear();
        size.clear();

        return sourceRepresentation == destinationRepresentation;
    }

    int find(int u)
    {
        if(u == representative[u])
            return u;

        else
            return representative[u] = find(representative[u]);
    }

    void combine (int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        else
        {
            if(size[u] > size[v])
            {
                representative[v] = u;
                size[u] += size[v];
            }

            else
            {
                representative[u] = v;
                size[v] += size[u];
            }

        }
    }
};


int main(){
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0;
    int destination = 2;

    Solution sol = *new Solution();
    cout << sol.validPath(n, edges, source, destination);

    return 0;
}
