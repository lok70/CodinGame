#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> budget(N);
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> budget[i];
        sum += budget[i];
    }

    if (sum < C) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        sort(budget.begin(), budget.end());

        for (int i = 0; i < N; ++i) {
            int p = C / (N - i);
            int m = min(budget[i], p);

            cout << m << endl;
            C -= m;
        }
    }
}