#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
VC的預設 stack reserve size 只有 1 MB
從 Project -> Properties (最下面) -> Configuration Properties -> Linker
              System -> Stack reserve size -> 填入 4194304 (4 MB)

*/

class _0834_sum_of_distances_in_tree
{
    int visited[30005];
    int count[30005];
    vector<int> next[30005];
    vector<int> rets;
    int n;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        rets.resize(n);
        for (auto& edge : edges) {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        visited[0] = 1;
        dfs(0);             // Compute the substree sizes

        for (int i = 1; i < n; i++) visited[i] = 0;
        rets[0] = dfs2(0);  // Get total distances towards root

        for (int i = 1; i < n; i++) visited[i] = 0;
        dfs3(0, rets[0]);

        return rets;
    }

    int dfs(int cur) {
        int sum = 1;
        for (int x : next[cur]) {
            if (visited[x]) continue;
            visited[x] = 1;
            sum += dfs(x);
        }
        count[cur] = sum;
        return sum;
    }

    int dfs2(int cur) {
        int sum = 0;
        for (int x : next[cur]) {
            if (visited[x]) continue;
            visited[x] = 1;
            sum += dfs2(x);
        }
        sum += count[cur] - 1;
        return sum;
    }

    void dfs3(int cur, int total) {
        for (int x : next[cur]) {
            if (visited[x]) continue;
            visited[x] = 1;
            int a = count[x];
            int b = n - count[x];
            rets[x] = total + b - a;
            dfs3(x, rets[x]);
        }
    }

    void clear() {
        memset(visited, 0, 30005 * 4);
        memset(count, 0, 30005 * 4);
        next->clear();
        
    }


	void do_test(_0834_sum_of_distances_in_tree* sol) {
        vector<vector<int>> edges;
        vector<int> ret;

        edges = { {0,1}, {0,2}, {2,3}, {2,4}, {2,5} };
        ret = sol->sumOfDistancesInTree(6, edges);
        print_vector(ret);
        // Outupt: [8, 12, 6, 10, 10, 10]
        sol->clear();

        edges = {};
        ret = sol->sumOfDistancesInTree(1, edges);
        print_vector(ret);
        // Outupt: [0]
        sol->clear();

        edges = { {1,0} };
        ret = sol->sumOfDistancesInTree(2, edges);
        print_vector(ret);
        // Outupt: [1, 1]
	}
};
