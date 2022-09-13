#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int row,col,n;
    cin>>row>>col>>n;
    vector<vector<char>> grid(row+=2, vector<char>(col+=2), 'O');
    vector<vector<char>> gridnext(row, vector<char>(col),'O');
    for (int i=1; i<row-1; i++) {
        for (int j=1; j<col-1; j++) {
            cin>>grid[i][j];
            gridnext[i][j]=grid[i][j];
        }
    }
    
    while(n>0){
        for (int i=1; i<row-1; i++) {
            for (int j=1; j<col-1; j++) {
                //birth
                if(grid[i][j]=='O'){
                    int countNb=0;
                    for (int h=-1; h<=1; h++) {
                        for (int v=-1; v<=1; v++) {
                            if(grid[i+h][j+v]=='X'){
                                countNb++;
                            }
                        }
                    }
                    if (countNb>=3) {
                        gridnext[i][j]='X';
                    }
                }else{
                    //die or surv
                    int countNb=-1;
                    for (int h=-1; h<=1; h++) {
                        for (int v=-1; v<=1; v++) {
                            if(grid[i+h][j+v]=='X'){
                                countNb++;
                            }
                        }
                    }
                    if (countNb>=4&&countNb<2) {
                        gridnext[i][j]='O';
                    }
                }
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                grid[i][j]=gridnext[i][j];
            }
        }
        n--;
    }
    for (int i=1; i<row-1; i++) {
        for (int j=1; j<col-1; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}