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
    int days;
    cin>>days;
    int up=0,down=0,same=0,day1,day2;
    cin>>day1;
    for (int i=1; i<days; i++) {
        cin>>day2;
        if (day1<day2) {
            up++;
        }else if (day1>day2) {
            down++;
        }else {
            same++;
        }
        day1=day2;
    }
    cout<<down<<" "<<same<<" "<<up;
    return 0;
}