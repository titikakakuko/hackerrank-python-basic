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
    string A,M;
    int n;
    cin>>A>>M>>n;
    int divider=A.size();
    for (int i=0; i<M.size(); i++) {
        for (int j=0; j<divider; j++) {
            if(M[i]==A[j]){
                cout<<A[(j+n)%divider];
                continue;
            }
        }
    }
    return 0;
}