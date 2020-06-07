#include<iostream>
#include <queue>

using namespace std;

struct coord
{
    int x;
    int y;
    bool prolaznost;
    int udaljenost;
};

/* queue<coord> q;              BFS
    q.push(source); 
    visited[source.row][source.col] = true; 
    while (!q.empty()) { 
        QItem p = q.front(); 
        q.pop(); 
  
        // Destination found; 
        if (grid[p.row][p.col] == 'd') 
            return p.dist; 
  
        // moving up 
        if (p.row - 1 >= 0 && 
            visited[p.row - 1][p.col] == false) { 
            q.push(QItem(p.row - 1, p.col, p.dist + 1)); 
            visited[p.row - 1][p.col] = true; 
        } 
  
        // moving down 
        if (p.row + 1 < N && 
            visited[p.row + 1][p.col] == false) { 
            q.push(QItem(p.row + 1, p.col, p.dist + 1)); 
            visited[p.row + 1][p.col] = true; 
        } 
  
        // moving left 
        if (p.col - 1 >= 0 && 
            visited[p.row][p.col - 1] == false) { 
            q.push(QItem(p.row, p.col - 1, p.dist + 1)); 
            visited[p.row][p.col - 1] = true; 
        } 
  
         // moving right 
        if (p.col + 1 < M && 
            visited[p.row][p.col + 1] == false) { 
            q.push(QItem(p.row, p.col + 1, p.dist + 1)); 
            visited[p.row][p.col + 1] = true; 
        } */


int main()
{
    coord polje[20][40];
    
    coord Start;
    coord Finish;

    cout << "Unesite redak pocetne koordinate : ";
    cin >> Start.y;
    cout << "Unesite stupac pocetne koordinate : ";
    cin >> Start.x;

    cout << "Unesite redak zavrsne koordinate : ";
    cin >> Finish.y;
    cout << "Unesite stupac zavrsne koordinate : ";
    cin >> Finish.x;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            polje[i][j].x = j;
            polje[i][j].y = i;
        }

    }

    char dalje;
    do
    {
        int x, y;
        cout << "Unesite redak zida : ";
        cin >> y;
        cout << "Unesite stupac zida : ";
        cin >> x;
        polje[y][x].prolaznost = 0;

        cout << "Zelite li unijeti jos jedan zid? d/n: ";
        cin >> dalje;

    } while (dalje=='d');


    return 0;
}