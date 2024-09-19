#include "algorithms.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void show_route_at_high_cost() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<string>> way(n, vector<string>(m, ""));

    dp[0][0] = matrix[0][0];
    way[0][0] = "";

    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
        way[0][j] = way[0][j - 1] + "R ";
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
        way[i][0] = way[i - 1][0] + "D ";
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = matrix[i][j] + dp[i - 1][j];
                way[i][j] = way[i - 1][j] + "D ";
            }
            else {
                dp[i][j] = matrix[i][j] + dp[i][j - 1];
                way[i][j] = way[i][j - 1] + "R ";
            }

        }
    }

    cout << dp[n - 1][m - 1] << endl;
    cout << way[n - 1][m - 1] << endl;

}
