#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int N = 1e2+5, M = 256+5, OO = 0x3f3f3f3f;

int n, q;
char dict[N][M], rule[M];
vector<string> path;

void solve(int i){
    if(rule[i] == 0){
        for(string x : path)
            printf("%s", x.c_str());
        puts("");
    }else{
        if(rule[i] == '0'){ //Digit
            for(int d = 0 ; d < 10 ; ++d){
                path.push_back(to_string(d));
                solve(i+1);
                path.pop_back();
            }
        }else{              //Word
            for(int w = 0 ; w < n ; ++w){
                path.push_back(dict[w]);
                solve(i+1);
                path.pop_back();
            }
        }
    }
}

int main(){
    while(~scanf("%d", &n)){
        puts("--");
        for(int i = 0 ; i < n ; ++i)
            scanf("%s", dict[i]);
        scanf("%d", &q);
        while(q--){
            scanf("%s", rule);
            solve(0);
        }
    }
    return 0;
}