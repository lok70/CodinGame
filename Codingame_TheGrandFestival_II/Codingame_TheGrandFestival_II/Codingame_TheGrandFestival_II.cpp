#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/*There are N tournaments in all, held from week 1 to week N.
Merry and Pippin can play at most R consecutive tournaments before they have to rest.
The prize money for all the tournaments will be given to you.
You need to display the tournaments they should play in order to get maximum prize money.*/


using namespace std;

int N;
vector<int> v;
int consecutive = 2;
vector<vector<int>> value;
vector<vector<string>> path;
int checks = 0;

string maximum(int cnt, int left);

int main() {
    cin >> N >> consecutive;
    v.resize(N);
    value.resize(N + 1, vector<int>(consecutive, 0));
    path.resize(N, vector<string>(consecutive, ""));

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    string val1 = maximum(0, consecutive);
    string val2 = maximum(1, consecutive);
    string optimal = val2;

    if (value[0][consecutive - 1] > value[1][consecutive - 1]) {
        optimal = val1;
    }

    cout << optimal.substr(0, optimal.length() - 1) << endl;
    cerr << checks << endl;

    return 0;
}

string maximum(int cnt, int left) {
    left--;
    if (cnt >= N) {
        return "";
    }
    else if (value[cnt][left] != 0) {
        return path[cnt][left];
    }

    checks++;
    string skip_1 = maximum(cnt + 2, consecutive);
    string best = skip_1;
    int val = 0;

    if (left > 0) {
        string next = maximum(cnt + 1, left);
        if (cnt > N - 3 || value[cnt + 1][left - 1] > value[cnt + 2][consecutive - 1]) {
            best = next;
            val = value[cnt + 1][left - 1];
        }
        else {
            val = value[cnt + 2][consecutive - 1];
        }
    }
    else {
        string skip_2 = maximum(cnt + 3, consecutive);
        if (cnt > N - 3) {
            best = "";
            val = 0;
        }
        else if (value[cnt + 3][consecutive - 1] > value[cnt + 2][consecutive - 1]) {
            best = skip_2;
            val = value[cnt + 3][consecutive - 1];
        }
        else {
            val = value[cnt + 2][consecutive - 1];
        }
    }

    stringstream ss;
    ss << (cnt + 1) << ">" << best;
    best = ss.str();

    value[cnt][left] = v[cnt] + val;
    path[cnt][left] = best;

    cerr << "max[" << cnt << "][" << left << "] = " << value[cnt][left] << endl;

    return best;
}
