#include <array>
#include <iostream>

using namespace std;

int up[] =   {1,0};
int down[] = {-1,0};
int rgt[] ={0,1};
int lft[] = {0,-1};
array<array<char, 5>, 5> map = {{
    {'S','#','#','#','#'},
    {'.','.','.','.','#'},
    {'.','#','#','#','#'},
    {'.','.','#','.','F'},
    {'#','.','.','.','#'}}};
bool findPath(int x, int y){
   
    if (y > map.size() || x > map[0].size()){ return false; }
    if (y < 0 || x < 0){ return false; }
   
    if (map[y][x] == 'F'){ return true; }
    if (map[y][x] == '#'){ return false; }
    if (map[y][x] == '+'){ return false; }
    if (map[y][x] == 'x'){ return false; }
    map[y][x] = '+';
    cout << '{' << x << ',' << y << '}';
    if (findPath(up[0] + x, up[1] + y) == true){ return true; }
    else if (findPath(down[0] + x, down[1] + y) == true){ return true; }
    else if (findPath(rgt[0] + x, rgt[1] + y) == true){ return true; }
    else if (findPath(lft[0] + x, lft[1] + y) == true){ return true; }
    else {
        map[y][x] = 'x';
        return false;
    }
}

int main(){
    findPath(0,0);
    for (const auto& row : map) {
        for (const auto& element : row) {
            cout << element << ' ';
        }
        cout << endl;
    }
    return 0;
}
