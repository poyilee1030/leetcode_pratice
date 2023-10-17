#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0417_pacific_atlantic_water_flow_bfs
{
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));


        vector<vector<int>> result;

        return result;
	}

	void do_test(_0417_pacific_atlantic_water_flow_bfs* sol)
	{
        vector<vector<int>> heights1 = { {1, 2, 2, 3, 5},
                                         {3, 2, 3, 4, 4},
                                         {2, 4, 5, 3, 1},
                                         {6, 7, 1, 4, 5},
                                         {5, 1, 1, 2, 4} };
        vector<vector<int>> ret1 = sol->pacificAtlantic(heights1);
        print_res(ret1);
        /*
        Output : [[0, 4],[1, 3],[1, 4],[2, 2],[3, 0],[3, 1],[4, 0]]
        Explanation : The following cells can flow to the Pacific and Atlantic oceans, 
        as shown below :
        [0, 4] : [0, 4] -> Pacific Ocean
                 [0, 4] -> Atlantic Ocean
        [1, 3] : [1, 3] -> [0, 3] -> Pacific Ocean
                 [1, 3] -> [1, 4] -> Atlantic Ocean
        [1, 4] : [1, 4] -> [1, 3] -> [0, 3] -> Pacific Ocean
                 [1, 4] -> Atlantic Ocean
        [2, 2] : [2, 2] -> [1, 2] -> [0, 2] -> Pacific Ocean
                 [2, 2] -> [2, 3] -> [2, 4] -> Atlantic Ocean
        [3, 0] : [3, 0] -> Pacific Ocean
                 [3, 0] -> [4, 0] -> Atlantic Ocean
        [3, 1] : [3, 1] -> [3, 0] -> Pacific Ocean
                 [3, 1] -> [4, 1] -> Atlantic Ocean
        [4, 0] : [4, 0] -> Pacific Ocean
                 [4, 0] -> Atlantic Ocean
        Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
        */
        
        vector<vector<int>>  heights2 = { {1} };
        vector<vector<int>> ret2 = sol->pacificAtlantic(heights2);
        print_res(ret2);
        //Output : [[0, 0]]
        //Explanation : The water can flow from the only cell to the Pacific and Atlantic oceans.
	}

    void print_res(vector<vector<int>>& res)
    {
        cout << "[";
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[";
            vector<int> oo = res[i];
            for (int j = 0; j < oo.size(); j++)
            {
                cout << oo[j];
                if (j < oo.size() - 1)
                    cout << ",";
            }
            cout << "]";

            if (i < res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
};
