#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct vertex{
    char color = 'w';
    int energy = 0;
    int value = 0;
};

struct coordinates{
    int x;
    int y;
    int z;
};

int main(){

    int k, e;
    cin >> k >> e;

    int x_Start, y_Start, z_Start;
    cin >> x_Start >> y_Start >> z_Start;

    int x_Finish, y_Finish, z_Finish;
    cin >> x_Finish >> y_Finish >> z_Finish;

    vertex arr[205][205][205];
    int x_k, y_k, z_k, h_k;
    for (int i = 0; i < k; ++i){
        cin >> x_k >> y_k >> z_k >> h_k;
        for (int j = 0; j < h_k; ++j){
            arr[x_k][y_k][z_k+j].value = 1;
        }
    }

    arr[x_Start][y_Start][z_Start].color = 'g';
    list <struct coordinates> queue;
    coordinates q;
    q.x = x_Start;
    q.y = y_Start;
    q.z = z_Start;
    queue.push_back(q);
    while (queue.empty() != true) {
        struct coordinates u = queue.front();
        queue.pop_front();
        if (u.x + 1 < 205 && arr[u.x + 1][u.y][u.z].color == 'w' && arr[u.x + 1][u.y][u.z].value != 1) {
            arr[u.x + 1][u.y][u.z].color = 'g';
            arr[u.x + 1][u.y][u.z].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x + 1;
            q.y = u.y;
            q.z = u.z;
            queue.push_back(q);
        }
        if (u.x - 1 > -1 && arr[u.x - 1][u.y][u.z].color == 'w' && arr[u.x - 1][u.y][u.z].value != 1) {
            arr[u.x - 1][u.y][u.z].color = 'g';
            arr[u.x - 1][u.y][u.z].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x - 1;
            q.y = u.y;
            q.z = u.z;
            queue.push_back(q);
        }
        if (u.y + 1 < 205 && arr[u.x][u.y + 1][u.z].color == 'w' && arr[u.x][u.y + 1][u.z].value != 1) {
            arr[u.x][u.y + 1][u.z].color = 'g';
            arr[u.x][u.y + 1][u.z].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x;
            q.y = u.y + 1;
            q.z = u.z;
            queue.push_back(q);
        }
        if (u.y - 1 > -1 && arr[u.x][u.y - 1][u.z].color == 'w' && arr[u.x][u.y - 1][u.z].value != 1) {
            arr[u.x][u.y - 1][u.z].color = 'g';
            arr[u.x][u.y - 1][u.z].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x;
            q.y = u.y - 1;
            q.z = u.z;
            queue.push_back(q);
        }
        if (u.z + 1 < 205 && arr[u.x][u.y][u.z + 1].color == 'w' && arr[u.x][u.y][u.z + 1].value != 1) {
            arr[u.x][u.y][u.z + 1].color = 'g';
            arr[u.x][u.y][u.z + 1].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x;
            q.y = u.y;
            q.z = u.z + 1;
            queue.push_back(q);
        }
        if (u.z - 1 > -1 && arr[u.x][u.y][u.z - 1].color == 'w' && arr[u.x][u.y][u.z - 1].value != 1) {
            arr[u.x][u.y][u.z - 1].color = 'g';
            arr[u.x][u.y][u.z - 1].energy = arr[u.x][u.y][u.z].energy + 1;
            q.x = u.x;
            q.y = u.y;
            q.z = u.z - 1;
            queue.push_back(q);
        }

        arr[u.x][u.y][u.z].color = 'b';
    }

    if (arr[x_Finish][y_Finish][z_Finish].energy <= e && arr[x_Finish][y_Finish][z_Finish].color == 'b') {
        cout << arr[x_Finish][y_Finish][z_Finish].energy;
    }
    else {
        cout << -1;
    }

    return 0;
}
