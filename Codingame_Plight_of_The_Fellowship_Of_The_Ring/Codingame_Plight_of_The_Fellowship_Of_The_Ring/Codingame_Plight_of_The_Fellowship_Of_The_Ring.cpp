#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>

/*
Rules:

The Spots will be INDEXED as 0, 1, 2, 3, ...

You will be given the COORDINATES OF THE SPOTS to where Gandalf can create a portal.

You will be given the COORDINATES OF THE ORCS.

You will also be given the POSSIBLE PATHS from one spot to another. (the indexes)
(note: the paths are double sided. this means that if a path is possible from spot 2 to spot 5, then it is possible to go from 2 to 5, as also from 5 to 2)

The Problem:

Your algorithm should display the sequence of the spots in order of how the fellowship go in order to reach the end fastest, and safely.
(note: the fellowship can travel from one spot to another along the POSSIBLE PATHS only)

You will be given the index of the STARTING SPOT and also the ENDING SPOT.*/


using namespace std;
struct Point { int x, y; };
struct State // Cтруктура State для хранения состояния в BFS
{
    int index;
    int time;
    vector<int> path;
};
double distance(const Point& a, const Point& b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
bool isSafe(const Point& spot, const vector<Point>& orcs, int time) // Функция для проверки безопасности перемещения
{
    for (const auto& orc : orcs) { if (distance(spot, orc) <= time) { return false; } }
    return true;
}
int main()
{
    int N, M, L; // Точки, орки, порталы
    cin >> N >> M >> L;
    vector<Point> spots(N); // Чтение координат точек
    for (int i = 0; i < N; ++i) { cin >> spots[i].x >> spots[i].y; }
    vector<Point> orcs(M); // Чтение координат орков
    for (int i = 0; i < M; ++i) { cin >> orcs[i].x >> orcs[i].y; }
    vector<vector<int>> adj(N); // Чтение списка смежности графа
    for (int i = 0; i < L; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    int start, end; // Чтение начальной и конечной точек
    cin >> start >> end;
    queue<State> q; // Инициализация очереди для BFS и массива посещенных вершин
    q.push({ start, 0, {start} });
    vector<bool> visited(N, false);
    visited[start] = true;
    while (!q.empty()) // BFS для поиска пути
    {
        State current = q.front();
        q.pop();
        if (current.index == end) // Если достигли конечной точки
        {
            for (size_t i = 0; i < current.path.size(); ++i)
            {
                cout << current.path[i];
                if (i != current.path.size() - 1) { cout << " "; }
            }
            cout << endl;
            return 0;
        }
        for (int next : adj[current.index]) // Проверка соседних вершин
        {
            if (!visited[next] && isSafe(spots[next], orcs, current.time + 1))
            {
                visited[next] = true;
                vector<int> newPath = current.path;
                newPath.push_back(next);
                q.push({ next, current.time + 1, newPath });
            }
        }
    }
    cout << "IMPOSSIBLE" << endl; // Если путь не найден
    return 0;
}