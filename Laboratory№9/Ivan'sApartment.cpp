#include <iostream>
#include <string>
using namespace std;

struct vertex{
    char value;
    char color;
    int component;
};

void visit(struct vertex* arr[], int i, int j, int& count){
    arr[i][j].color = 'g';
    if (arr[i][j-1].value == '.' && arr[i][j-1].color == 'w'){
        visit(arr, i, j-1, count);
    }
    if (arr[i-1][j].value == '.' && arr[i-1][j].color == 'w'){
        visit(arr, i-1, j, count);
    }
    if (arr[i][j+1].value == '.' && arr[i][j+1].color == 'w'){
        visit(arr, i, j+1, count);
    }
    if (arr[i+1][j].value == '.' && arr[i+1][j].color == 'w'){
        visit(arr, i+1, j, count);
    }
    arr[i][j].color = 'b';
}

void dfs(struct vertex *arr[], int n, int m){

    int count = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (arr[i][j].value == '.' && arr[i][j].color == 'w'){
                count++;
                visit(arr, i, j, count);
            }
        }
    }
    cout << count;
}

int main(){

    int n, m;
    cin >> n >> m;

    //struct vertex arr[n][m];
    vertex** arr = new vertex* [n];
    for (int i = 0; i < n; ++i){
        arr[i] = new vertex [m];
    }

    char tmp;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> tmp;
            arr[i][j].value = tmp;
            arr[i][j].color = 'w';
            arr[i][j].component = 0;
        }
    }

    dfs(arr, n, m);

    return 0;
}