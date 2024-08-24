#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int up[] =   {1,0};
int down[] = {-1,0};
int rgt[] ={0,1};
int lft[] = {0,-1};

vector<vector<char>> map = {
    {'S','#','#','#','#'},
    {'.','.','.','.','#'},
    {'.','#','#','#','#'},
    {'.','.','#','.','F'},
    {'#','.','.','.','#'}};

int recursiones = 0;
int retrocesos = 0;
int error = 0;
bool errorCount = false;

bool findPath(int x, int y){   
    recursiones += 1;
    if (y >= map.size() || x >= map[0].size() || y < 0 || x < 0) { return false; }
    if (map[y][x] == 'F') { return true; }
    if (map[y][x] == '#' || map[y][x] == '+' || map[y][x] == 'x') { return false; }
    map[y][x] = '+';
    
    if (retrocesos > 0 && !errorCount) {
        error += 1;
        errorCount = true;
    }
    if (findPath(up[0] + x, up[1] + y) == true){ return true; }
    else if (findPath(down[0] + x, down[1] + y) == true){ return true; }
    else if (findPath(rgt[0] + x, rgt[1] + y) == true){ return true; }
    else if (findPath(lft[0] + x, lft[1] + y) == true){ return true; }
    else {
        errorCount = false;  
        retrocesos += 1;
        map[y][x] = 'x';
        return false;
    }
}

int main(){
    int x = 0, y = 0;
    for (int i = 0; i < map.size(); i++) { 
        for (int j = 0; j < map[0].size(); j++) { 
            if (map[i][j] == 'S') {
                x = j;
                y = i;
            }
        } 
        cout << endl; 
    }
    std::clock_t start = std::clock();
    findPath(x,y);
    std::clock_t end = std::clock();
    //devoluciones en consola
    for (const vector<char> row : map) { 
        for (char col : row) { 
            cout << col << " "; 
        } 
        cout << endl; 
    }
    cout << "Tiempo de ejecucion:  " << end - start << "s" << endl ;
    cout << "Cantidad de recursiones:  " << recursiones << endl;
    cout << "Cantidad de retrosesos:  " << retrocesos << endl;
    cout << "Caminos incorrectos encontrados:  " << error << endl;
    return 0;
}
/*
map = {
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '.', '.', '.', '#', '#', '.', '#'},
    {'.', '.', '.', '#', '#', '#', '.', '.', '.', '#'},
    {'.', '#', '#', '.', '#', '.', '.', '#', '.', '.'},
    {'.', '.', 'S', '.', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '#', '#', '#', 'F', '.', '.', '#', '.'},
    {'.', '.', '.', '#', '.', '#', '.', '#', '.', '.'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'.', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'.', '#', '#', '#', '.', '#', '.', '.', '.', '.'},
    {'.', '.', '#', '.', '.', '.', '.', '#', '#', '.'}
};
*/
