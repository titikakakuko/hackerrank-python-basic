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
    int n,g,p;
    cin>>n>>g>>p;
    map<int,int> courseN;
    int map_ntoc[n];
    vector<vector<int>> coursePre(n,vector<int>(n,0));
    for (int i=0; i<n; i++) {
        int courseNo,preN;
        cin>>courseNo>>preN;
        courseN[courseNo]=i;
        map_ntoc[i]=courseNo;
        for (int p=0; p<preN; p++) {
            int preNo;
            cin>>preNo;
            coursePre[courseN[preNo]][courseN[courseNo]]=1;
        }
    }

    int req[g];
    int plan[p];
    for (int i=0; i<g; i++) {
        cin>>req[i];
    }
    for (int i=0; i<p; i++) {
        cin>>plan[i];
    }

    queue <int> missedC;
    for (int i=0; i<g; i++) {
        for (int j=0; j<p; j++) {
            if(req[i]==plan[j]){
                continue;
            }
        }
        missedC.push(req[i]);
    }

    for (int i=0; i<p; i++) {
        bool sameC=false;
        for (int j=0; j<g; j++) {
            if(req[j]==plan[i]){
                sameC=true;
                continue;
            }
        }
        //check pre
        if(!sameC){
            queue <int> preC;
            for (int p=0; p<n; p++) {
                if(coursePre[p][plan[i]]==1){
                    preC.push(map_ntoc[p]);
                }
            }
            while (!preC.empty()){
                int precourse = preC.front();
                bool isC=false;
                for (int i=0; i<p; i++) {
                    if(precourse==plan[i]){
                        isC=true;
                    }
                }
                if(!isC){
                    missedC.push(precourse);
                }
                preC.pop();
            }
        }
    }

    if(missedC.empty()){
        cout<<"OK";
    }else{
        cout<<"MISSING ";
        while(!missedC.empty()){
            cout<<missedC.front()<<" ";
            missedC.pop();
        }
    }
    return 0;
}