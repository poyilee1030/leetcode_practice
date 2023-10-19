#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

/*
    Given grid: -1 wall, 0 gate, INF empty, fill each empty w/ dist to nearest gate

    BFS traversal, shortest path from each gate to all empty rooms
    Each gate only looks at within 1 space, then next gate, guarantees shortest

    Time: O(m x n)
    Space: O(m x n)
*/

class _0286_walls_and_gates
{
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({ i, j });
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = row + dirs[i][0];
                int y = col + dirs[i][1];

                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX) {
                    continue;
                }

                rooms[x][y] = rooms[row][col] + 1;
                q.push({ x, y });
            }
        }
    }

    // slower
    /* 
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        unordered_set<string> visit;
        queue<pair<int, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (rooms[r][c] == 0) {
                    q.push({ r, c });
                    string oo = to_string(r) + "," + to_string(c);
                    visit.insert(oo);
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                rooms[r][c] = dist;
                addRooms(r + 1, c, m, n, visit, q, rooms);
                addRooms(r - 1, c, m, n, visit, q, rooms);
                addRooms(r, c + 1, m, n, visit, q, rooms);
                addRooms(r, c - 1, m, n, visit, q, rooms);
            }
            dist++;
        }
	}

    void addRooms(int r, int c, int m, int n, unordered_set<string>& visit, 
                  queue<pair<int, int>>& q, vector<vector<int>>& rooms)
    {
        if (r < 0 || r == m || c < 0 || c == n || rooms[r][c] == -1)
            return;
        string xx = to_string(r) + "," + to_string(c);
        if (visit.find(xx) != visit.end())
            return;

        q.push({ r, c });
        visit.insert(xx);
    }
    */

	void do_test(_0286_walls_and_gates* sol)
	{
		vector<vector<int>> rooms1 = { {2147483647, -1, 0, 2147483647},
									   {2147483647, 2147483647, 2147483647, -1},
									   {2147483647, -1, 2147483647, -1},
									   {0, -1, 2147483647, 2147483647} };
		sol->wallsAndGates(rooms1);
        print_res(rooms1);
		// Output : {{3, -1, 0, 1}, {2, 2, 1, -1}, {1, -1, 2, -1}, {0, -1, 3, 4}}
		

		vector<vector<int>> rooms2 = { {-1} };
		sol->wallsAndGates(rooms2);
        print_res(rooms2);
		// Output : {{-1}}
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

