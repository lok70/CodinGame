#include <iostream>
#include <vector>

using namespace std;

struct Attack {
    int nbFire;
    int x;
    int y;

    Attack(int nbFire, int x, int y) : nbFire(nbFire), x(x), y(y) {}
};

bool** grid;

int calcFireFrom(int i, int j, int nbArea, int L) {
    int nbFire = 0;
    for (int k = 0; k < nbArea; k++) {
        for (int l = 0; l < nbArea; l++) {
            nbFire += grid[i + k][j + l] ? 1 : 0;
        }
    }
    return nbFire;
}

int main() {
    int L;
    cin >> L;
    int water;
    cin >> water;

    while (true) {
        int N;
        cin >> N;

        grid = new bool* [L];
        for (int i = 0; i < L; ++i) {
            grid[i] = new bool[L]();
        }

        for (int i = 0; i < N; i++) {
            int fireX, fireY;
            cin >> fireX >> fireY;
            grid[fireY][fireX] = true;
        }

        vector<Attack> attack(3, Attack(0, 0, 0));

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (i + 2 < L && j + 2 < L) {
                    int nbFireIn3x3 = calcFireFrom(i, j, 3, L);
                    if (nbFireIn3x3 > attack[0].nbFire) {
                        attack[0] = Attack(nbFireIn3x3, i, j);
                    }
                }

                if (i + 1 < L && j + 1 < L) {
                    int nbFireIn2x2 = calcFireFrom(i, j, 2, L);
                    if (nbFireIn2x2 > attack[1].nbFire) {
                        attack[1] = Attack(nbFireIn2x2, i, j);
                    }
                }

                if (grid[i][j]) {
                    attack[2] = Attack(1, i, j);
                }
            }
        }

        if (attack[0].nbFire > 5) {
            cout << "C " << attack[0].y << " " << attack[0].x << endl;
        }
        else if (attack[1].nbFire > 1) {
            cout << "H " << attack[1].y << " " << attack[1].x << endl;
        }
        else {
            cout << "J " << attack[2].y << " " << attack[2].x << endl;
        }

        for (int i = 0; i < L; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    return 0;
}
