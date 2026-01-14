#include "History.h"
#include "Zombie.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols) 
: m_rows(nRows), m_cols(nCols)
{
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            m_grid[i][j] = 0;
}

bool History::record(int r, int c) 
{
    if (r <= 0  ||  r <= 0  ||  r > MAXROWS  ||  r > MAXCOLS)
    {
        return false;
    }
    edit(r, c);
    return true;
}

void History::display() const 
{
    clearScreen();
    char displayGrid[MAXROWS][MAXCOLS];
    
    int i;
    int j;
    
    for (i = 0; i < m_rows; i++)
    {
        for (j = 0; j < m_cols; j++)
        {
            if (m_grid[i][j] == 0) {
                displayGrid[i][j] = '.';
            } else if (m_grid[i][j] > 26) {
                displayGrid[i][j] = 'Z';
            } else {
                displayGrid[i][j] = 'A' + m_grid[i][j] - 1;
                
            }
        }
    }
    
    // print the display grid
    for (i = 0; i < m_rows; i++)
    {
        for (j = 0; j < m_cols; j++)
        {
            cout << displayGrid[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
}

void History::edit(int r, int c)
{
    r--;c--;
    m_grid[r][c]++;
}
