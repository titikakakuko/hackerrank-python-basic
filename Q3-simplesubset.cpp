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

void subset(string s, int starter, int size){
    for (int i=starter+1; i<size; i++) {
        cout<<s[starter]<<s[i]<<" ";
    }
    if(starter<size-1){
        subset(s, starter+1, size);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    cin>>input;
    subset(input, 0, input.size());
    return 0;
}